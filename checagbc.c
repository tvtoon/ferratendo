/* pt_BR.utf-8

Xerecador de ROOMs.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "calculo.h"
#include "cartucho_gbc.h"
#include "bios_gb.h"

cabecalho_gb cabecalho_cgb;

int checa_gbc( FILE *rom )
{
 int erros = 0, testi = 0;
 unsigned char testu = 0;

 testi = memcmp( logo_gb, cabecalho_cgb.logo, GBCART_TAMANHO_LOGO );

 if ( testi != 0 )
{
  erros++;
  printf( "Logo adulterado!\n" );
}

 testu = calc_somagb( rom, GBCART_ENDERECO_SOMACAB - GBCART_ENDERECO_TITULO );

 if ( testu != cabecalho_cgb.soma_cab )
{
  erros++;
  printf( "Soma de verificação errada!\n" );
}

 return(erros);
}

int main( int argc, char **argv )
{
 FILE *rom = 0;
 int testgb = 0, testi = 0;
 size_t testu = 0;

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

  fseek( rom, GBCART_ENDERECO_ROTINA1, SEEK_CUR );
  testu = gbcart_pega_cab( rom, &cabecalho_cgb );
  fseek( rom, -(testu - ( GBCART_ENDERECO_TITULO - GBCART_ENDERECO_ROTINA1 ) ), SEEK_CUR );
  printf( "Arquivo: \"%s\"\n", argv[testi] );
  testgb = checa_gbc(rom);

   if ( testgb > 0 )
{
    printf( "%d erro(s) fatal(is)! O jogo está quebrado!\n\n", testgb );
}
   else
{
    printf( "Tudo checado com sucesso!\n\n" );
}

  fclose(rom);
}

 return(0);
}
