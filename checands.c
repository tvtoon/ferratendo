/* pt_BR.utf-8

Xerecador de ROOMs.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "bios_gba.h"
#include "cartucho_nds.h"

/* EXtrotoras grobais... */
cabecalho_nds cabecalho_ntr;

/*
A checagem de NDS é MUITO EXTENSA, além de precisar ser reavaliada e testada na
máquina, pois além do DeSmuME afirmar que o cálculo de CRC16 do GBATEK está
errado, muitas funções de encriptação são extremamente duvidosas e
interpretativas.

Por um longo ENQÜANTO, apenas o básico...
*/

int checa_nds( void )
{
 int erros = 0, testi = 0;

 testi = memcmp( logo_gba, cabecalho_ntr.logo, NDSCART_TAMANHO_LOGO );

 if ( testi != 0 )
{
  erros++;
  printf( "Logo adulterado!\n" );
}

 if ( cabecalho_ntr.somalogo != NDSCART_VALOR_SOMALOGO )
{
  erros++;
  printf( "Soma de verificação do logo está errada!\n" );
}

 return(erros);
}

/* Principal */

int main ( int argc, char *argv[] )
{
 FILE *rom = 0;
 int testnds = 0, testi = 0;
 /* size_t testu = 0;*/

 do
{
  testi = getopt( argc, argv, "h" );

  switch ( testi )
{
   case 'h':
    printf( "%s <ROM1> <ROM2> ... <ROMx>\n", argv[0] );
    return(0);

   case '?':
   default:
    break;
}

} while ( testi != -1 );

 for ( testi = optind; testi < argc; testi++ )
{
  rom = fopen( argv[testi], "rb" );

  if ( rom == 0 )
{
   fprintf( stderr, "Falhou ao abrir o arquivo \"%s\".\n", argv[testi] );
   return(1);
}

  ndscart_pega_cab( rom, &cabecalho_ntr );
  printf( "Arquivo: \"%s\".\n", argv[testi] );
  testnds = checa_nds();

   if ( testnds > 0 )
{
    printf( "%d erro(s) fatal(is)! O jogo está quebrado!\n\n", testnds );
}
   else
{
    printf( "Tudo checado com sucesso!\n\n" );
}

  fclose(rom);
}

 return(0);
}
