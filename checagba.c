/* pt_BR.utf-8

Xerecador de ROOMs.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "calculo.h"
#include "cartucho_gba.h"
#include "bios_gba.h"

cabecalho_gba cabecalho_agb;

int checa_gba( FILE *rom )
{
 int erros = 0, testi = 0;
 unsigned char testu = 0;

 testi = gbacart_checa_fixo( cabecalho_agb.valor_fixo );

 if ( testi != 0 )
{
  erros++;
  printf( "Valor fixo errado!\n" );
}

 testi = memcmp( logo_gba, cabecalho_agb.logo, GBACART_TAMANHO_LOGO );

 if ( testi != 0 )
{
  erros++;
  printf( "Logo adulterado!\n" );
}

 testu = calc_soma1byte( rom, GBACART_ENDERECO_SOMA - GBACART_ENDERECO_TITULO );

 if ( testu != cabecalho_agb.soma )
{
  erros++;
  printf( "Soma de verificação errada!\n" );
}

 return(erros);
}

int main ( int argc, char *argv[] )
{
 FILE *rom = 0;
 int testgba = 0, testi = 0;
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

  testu = gbacart_pega_cab( rom, &cabecalho_agb );
  fseek( rom, -(testu - GBACART_ENDERECO_TITULO), SEEK_CUR );
  printf( "Arquivo: \"%s\"\n", argv[testi] );
  testgba = checa_gba(rom);

   if ( testgba > 0 )
{
    printf( "%d erro(s) fatal(is)! O jogo está quebrado!\n\n", testgba );
}
   else
{
    printf( "Tudo checado com sucesso!\n\n" );
}

  fclose(rom);
}

 return(0);
}
