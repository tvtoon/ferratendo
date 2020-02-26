/* pt_BR.utf-8

Informador de ROOMs.
*/

#include <stdio.h>
#include <unistd.h>

#include "cartucho_gbc.h"
#include "codigos.h"
#include "codigos_gbc.h"
#include "codigos_letras.h"
#include "tempo.h"
#include "transcrever.h"

const int indmax_cgbm = sizeof( cgb_marca ) / sizeof( cgb_marca[0] );
const int indmax_gbtipo = sizeof( gbcart_tipo ) / sizeof( gbcart_tipo[0] );
const int indmax_gbtamrom = sizeof( gbcart_tamrom ) / sizeof( gbcart_tamrom[0] );

cabecalho_gb cabecalho_cgb;

void info_gbc( void )
{
 char prod[3];
 int ind_cgbm = 0, ind_gbtipo = 0, ind_gbtamrom = 0;
 unsigned int ind_prod = 0, ind_reg = 0;

 ind_cgbm = trans_byte_explicado( cgb_marca, cabecalho_cgb.titulo.cgb, indmax_cgbm );
 ind_gbtipo = trans_byte_explicado( gbcart_tipo, cabecalho_cgb.tipo, indmax_gbtipo );
 ind_gbtamrom = trans_byte_explicado( gbcart_tamrom, cabecalho_cgb.tamrom, indmax_gbtamrom );

 printf( "Logo...\n" );
 imprime_hexa_ate( cabecalho_cgb.logo, GBCART_TAMANHO_LOGO );

 if ( cabecalho_cgb.titulo.cgb == 0x80 || cabecalho_cgb.titulo.cgb == 0xc0 )
{
  printf( "Título: %s.\n" , cabecalho_cgb.titulo.titulo );
  printf( "Código: %s.\n", cabecalho_cgb.titulo.codigo );
  printf( "Marcação CGB: %s (0x%X).\n", cgb_marca[ind_cgbm].explica, cgb_marca[ind_cgbm].byte );
  ind_reg = trans36( &cabecalho_cgb.titulo.codigo[3] );
}
 else
{
  printf( "Título: %s%s%c.\n" , cabecalho_cgb.titulo.titulo, cabecalho_cgb.titulo.codigo,
           cabecalho_cgb.titulo.cgb );
  printf( "Código e marcação CGB indisponíveis para a época antes de Game Boy Color.\n" );
  ind_reg = 0;
}

 if ( ind_reg != 0 )
{
  printf( "Região: %s.\n", regioes[ind_reg] );
}
 else
{
  printf( "Região desconhecida.\n" );
}

 if ( cabecalho_cgb.prod_velho == 0x33 )
{
  printf( "Produtora na posição antiga sinalizada como 0x33.\n");
  printf( "Produtora nova usada: %s - ", cabecalho_cgb.prod_novo );
  ind_prod = trans36( cabecalho_cgb.prod_novo );
}
 else
{
  sprintf( prod, "%02X", cabecalho_cgb.prod_velho );
  printf( "Produtora na posição nova: 0x%X 0x%X\n", cabecalho_cgb.prod_novo[0], cabecalho_cgb.prod_novo[1] );
  printf( "Produtora velha usada: %s - ", prod );
  ind_prod = trans36( prod );
}

 if ( ind_prod != 0 )
{
  printf( "%s.\n", produtoras[ind_prod] );
}
 else
{
  printf( "desconhecido.\n" );
}

 printf( "Funções SGB: " );

 if ( cabecalho_cgb.sgb == 0 || cabecalho_cgb.sgb == 3 )
{
  printf( "%s", sgb_marca[cabecalho_cgb.sgb] );
}
 else
{
  printf( "desconhecido" );
}

 printf( " (0x%X).\n", cabecalho_cgb.sgb );
 printf( "Tipo do cartucho: " );

 if ( ind_gbtipo != -1 )
{
  printf( "%s", gbcart_tipo[ind_gbtipo].explica );
}
 else
{
  printf( "desconhecido" );
}

 printf( " (0x%X).\n", cabecalho_cgb.tipo );
 printf( "Tamanho da ROM: " );

 if ( ind_gbtamrom != -1 )
{
  printf( "%s", gbcart_tamrom[ind_gbtamrom].explica );
}
 else
{
  printf( "desconhecido" );
}

 printf( " (0x%X).\n", cabecalho_cgb.tamrom );
 printf( "Tamanho da RAM: " );

 if ( cabecalho_cgb.tamram < 6 )
{
  printf( "%s", gbcart_tamram[cabecalho_cgb.tamram] );
}
 else
{
  printf( "desconhecido" );
}

 printf( " (0x%X).\n", cabecalho_cgb.tamram );
 printf( "Mercado do produto: " );

 if ( cabecalho_cgb.mercado == 0 || cabecalho_cgb.mercado == 1 )
{
  printf( "%s", gbcart_mercado[cabecalho_cgb.mercado] );
}
 else
{
  printf( "desconhecido" );
}

 printf( " (0x%X).\n", cabecalho_cgb.mercado );
 printf( "Versão: 1.%d.\n", cabecalho_cgb.versao );
 printf( "Soma de verificação do cabeçalho: 0x%X.\n", cabecalho_cgb.soma_cab );
 printf( "Soma de verificação da ROM: 0x%X.\n", cabecalho_cgb.soma_total );
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

  fseek( rom, GBCART_ENDERECO_ROTINA1, SEEK_CUR );
  gbcart_pega_cab( rom, &cabecalho_cgb );
  fclose(rom);
  printf( "Arquivo: \"%s\"\n", argv[testi] );
  info_gbc();
}

 return(0);
}
