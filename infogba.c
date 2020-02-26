/* pt_BR.utf-8

Informador de ROOMs.
*/

#include <stdio.h>
#include <unistd.h>

#include "cartucho_gba.h"
#include "codigos.h"
#include "codigos_letras.h"
#include "tempo.h"
#include "transcrever.h"

cabecalho_gba cabecalho_agb;

void info_gba( void )
{
 unsigned int ind_prod = 0, ind_reg = 0;

 ind_prod = trans36( cabecalho_agb.produtor );
 ind_reg = trans36( &cabecalho_agb.codigo[3] );

 printf( "Logo...\n" );
 imprime_hexa_ate( cabecalho_agb.logo, GBACART_TAMANHO_LOGO );
 printf( "Título: %s.\n" , cabecalho_agb.titulo );
 printf( "Código: %s.\n", cabecalho_agb.codigo );

 if ( ind_reg != 0 )
{
  printf( "Região: %s.\n", regioes[ind_reg] );
}
 else
{
  printf( "Região desconhecida.\n" );
}

 printf( "Produtora: " );

 if ( ind_prod != 0 )
{
  printf( "%s", produtoras[ind_prod] );
}
 else
{
  printf( "desconhecida" );
}

 printf( " (%s).\n", cabecalho_agb.produtor );
 printf( "Valor fixo: 0x%X.\n", cabecalho_agb.valor_fixo );
 printf( "Unidade: %d.\n", cabecalho_agb.unidade );
 printf( "Dispositivo: %d.\n", cabecalho_agb.dispositivo );
 printf( "Reservado...\n" );
 imprime_hexa_ate( cabecalho_agb.reservado, GBACART_TAMANHO_RESERVADO );
 printf( "Versão: 1.%d.\n", cabecalho_agb.versao );
 printf( "Soma de verificação: 0x%X.\n", cabecalho_agb.soma );
 printf( "Final...\n" );
 imprime_hexa_ate( cabecalho_agb.final, GBACART_TAMANHO_FINAL );
}

int main ( int argc, char *argv[] )
{
 FILE *rom = 0;
 int testi = 0;

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

  gbacart_pega_cab( rom, &cabecalho_agb );
  fclose(rom);
  printf( "Arquivo: \"%s\"\n", argv[testi] );
  info_gba();
}

 return(0);
}
