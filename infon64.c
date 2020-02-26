/* pt_BR.utf-8

Informador de ROOMs.
*/

#include <stdio.h>
#include <unistd.h>

#include "cartucho_n64.h"
#include "codigos.h"
#include "codigos_letras.h"
#include "tempo.h"
#include "transcrever.h"

cabecalho_n64 cabecalho_ult;

void info_n64( void )
{
 unsigned int ind_reg = 0;
 ind_reg = trans36( &cabecalho_ult.codigo[3] );

 printf( "Validação: 0x%X?\n", cabecalho_ult.validacao );
 printf( "Compressão: 0x%X?\n", cabecalho_ult.compressao );
 printf( "Desconhecido 1: 0x%X?\n", cabecalho_ult.desc1 );
 printf( "Frequência: %d.\n", cabecalho_ult.frequencia );
 printf( "Contador do programa: %d.\n", cabecalho_ult.conta_prog );
 printf( "Lançamento: %d?\n", cabecalho_ult.lancamento );
 printf( "CRC 1: 0x%X.\n", cabecalho_ult.crc1 );
 printf( "CRC 2: 0x%X.\n", cabecalho_ult.crc2 );
 printf( "Desconhecido 2...\n" );
 imprime_hexa_ate( cabecalho_ult.desc2, N64C_DESC2_TAM );
 printf( "Título: %s.\n", cabecalho_ult.titulo );
 printf( "Desconhecido 3...\n" );
 imprime_hexa_ate( cabecalho_ult.desc3, N64C_DESC3_TAM );
 printf( "Código: %s.\n", cabecalho_ult.codigo );
 printf( "Versão: 1.%d.\n", cabecalho_ult.versao );
 printf( "Região: " );

 if ( ind_reg != 0 )
{
  printf( "%s.\n", regioes[ind_reg] );
}
 else
{
  printf( "desconhecida.\n" );
}

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

  n64c_pegacab( rom, &cabecalho_ult );
  fclose(rom);
  printf( "Arquivo: \"%s\"\n", argv[testi] );
  info_n64();
}

 return(0);
}
