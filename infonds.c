/* pt_BR.utf-8

Informador de ROOMs.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "cartucho_nds.h"
#include "codigos.h"
#include "codigos_letras.h"
#include "codigos_nds.h"
#include "tempo.h"
#include "transcrever.h"

cabecalho_nds cabecalho_ntr;
internacional_nds cabecalho_int;

void info_nds( void )
{
 unsigned int ind_prod = 0, ind_reg = 0;

 ind_prod = trans36( cabecalho_ntr.produtor );
 ind_reg = trans36( &cabecalho_ntr.codigo[3] );

 printf( "Título: %s.\n" , cabecalho_ntr.titulo );
 printf( "Código: %s.\n", cabecalho_ntr.codigo );

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

 printf( " (%s).\n", cabecalho_ntr.produtor );
 printf( "Dispositivo: %d.\n", cabecalho_ntr.dispositivo );
 printf( "Semente da encriptação: %d.\n", cabecalho_ntr.encsemente );
/* "128KB << n" ou... */
 printf( "Tamanho do cartucho: %d Megabit(s).\n", 1 << cabecalho_ntr.tamcart );
 printf( "Reservado 1...\n" );
 imprime_hexa_ate( cabecalho_ntr.reserva1, NDSCART_TAMANHO_RESERVA1 );
 printf( "Versão: 1.%d.\n", cabecalho_ntr.versao );
 printf( "Início automático: %d.\n", cabecalho_ntr.autoini );
 printf( "Endereço da ROM do ARM9: 0x%X.\n", cabecalho_ntr.endromarm9 );
 printf( "Endereço de entrada do ARM9: 0x%X.\n", cabecalho_ntr.endentarm9 );
 printf( "Endereço na RAM do ARM9: 0x%X.\n", cabecalho_ntr.endramarm9 );
 printf( "Tamanho da ROM do ARM9: %d bytes.\n", cabecalho_ntr.tamarm9 );
 printf( "Endereço da ROM do ARM7: 0x%X.\n", cabecalho_ntr.endromarm7 );
 printf( "Endereço de entrada do ARM7: 0x%X.\n", cabecalho_ntr.endentarm7 );
 printf( "Endereço na RAM do ARM7: 0x%X.\n", cabecalho_ntr.endramarm7 );
 printf( "Tamanho da ROM do ARM7: %d bytes.\n", cabecalho_ntr.tamarm7 );
 printf( "Endereço da seção FNT: 0x%X.\n", cabecalho_ntr.endfnt );
 printf( "Tamanho da seção FNT: %d bytes.\n", cabecalho_ntr.tamfnt );
 printf( "Endereço da seção FAT: 0x%X.\n", cabecalho_ntr.endfat );
 printf( "Tamanho da seção FAT: %d bytes.\n", cabecalho_ntr.tamfat );
 printf( "Endereço do repositor ARM9: 0x%X.\n", cabecalho_ntr.endreparm9 );
 printf( "Tamanho do repositor ARM9: %d bytes.\n", cabecalho_ntr.tamreparm9 );
 printf( "Endereço do repositor ARM7: 0x%X.\n", cabecalho_ntr.endreparm7 );
 printf( "Tamanho do repositor ARM7: %d bytes.\n", cabecalho_ntr.tamreparm7 );
 printf( "Configurações da porta 0x40001A4...\n");
 printf( "\t-Para comandos normais: 0x%X.\n", cabecalho_ntr.normalcfg );
 printf( "\t-Para comandos \"KEY1\": 0x%X.\n", cabecalho_ntr.key1cfg );
 printf( "Endereço da seção do ícone e títulos internacionais: 0x%X.\n", cabecalho_ntr.tituloicon );
 printf( "Soma de verificação da região segura: 0x%X.\n", cabecalho_ntr.somaregseg );
 printf( "Tempo de espera da região segura: 0x%X.\n", cabecalho_ntr.temporegseg );
 printf( "Carregamento automático da lista de endereços da RAM...\n" );
 printf( "\t-Para ARM9: 0x%X.\n", cabecalho_ntr.calramarm9 );
 printf( "\t-Para ARM7: 0x%X.\n", cabecalho_ntr.calramarm7 );
 printf( "Estado da região segura...\n" );
 imprime_hexa_ate( cabecalho_ntr.estregseg, NDSCART_TAMANHO_ESTREGSEG );
 printf( "Tamanho total usado no cartucho, pela ROM: %d bytes.\n", cabecalho_ntr.tamtotalrom );
 printf( "Tamanho total desse cabeçalho: %d bytes.\n", cabecalho_ntr.tamtotalcab );
 printf( "Reservado 2...\n" );
 imprime_hexa_ate( cabecalho_ntr.reserva2, NDSCART_TAMANHO_RESERVA2 );
 printf( "Logo...\n" );
 imprime_hexa_ate( cabecalho_ntr.logo, NDSCART_TAMANHO_LOGO );
 printf( "Soma de verificação do logo: 0x%X.\n", cabecalho_ntr.somalogo );
 printf( "Soma de verificação do cabeçalho: 0x%X.\n", cabecalho_ntr.somacab );
 printf( "Endereço do DEBUG na ROM: 0x%X.\n", cabecalho_ntr.enddebugrom );
 printf( "Tamanho do DEBUG: %d bytes.\n", cabecalho_ntr.tamdebug );
 printf( "Endereço do DEBUG na RAM: 0x%X.\n", cabecalho_ntr.enddebugram );
 printf( "Reservado 3: 0x%X.\n", cabecalho_ntr.reserva3 );
 printf( "Final...\n" );
 imprime_hexa_ate( cabecalho_ntr.final, NDSCART_TAMANHO_FINAL );
}

void info_inds( void )
{
 char tcjapa[NDSCART_TAMANHO_TITULOINT * 2], tcingles[NDSCART_TAMANHO_TITULOINT * 2],
  tcfrances[NDSCART_TAMANHO_TITULOINT * 2], tcalemao[NDSCART_TAMANHO_TITULOINT * 2],
  tcitalia[NDSCART_TAMANHO_TITULOINT * 2], tcespanha[NDSCART_TAMANHO_TITULOINT * 2],
  tcchines[NDSCART_TAMANHO_TITULOINT * 2];

 ndscart_convint( cabecalho_int.tjapa, tcjapa );
 ndscart_convint( cabecalho_int.tingles, tcingles );
 ndscart_convint( cabecalho_int.tfrances, tcfrances );
 ndscart_convint( cabecalho_int.talemao, tcalemao );
 ndscart_convint( cabecalho_int.titalia, tcitalia );
 ndscart_convint( cabecalho_int.tespanha, tcespanha );
 ndscart_convint( cabecalho_int.tchines, tcchines );

 if ( cabecalho_int.versao < 3 )
{
  printf( "Versão: %s.\n", versao_inter[cabecalho_int.versao] );
}
 else
{
  printf( "Versão internacional desconhecida.\n" );
}

 printf( "Soma de verificação normal: 0x%X.\n", cabecalho_int.somanorm );
 printf( "Soma de verificação chinesa: 0x%X.\n", cabecalho_int.somachina );
 printf( "Dados reservados...\n" );
 imprime_hexa_ate( cabecalho_int.reservado, NDSCART_TAMINT_RESERVADO );
#ifdef TESTE
 printf( "Dados do ícone...\n" );
 imprime_hexa_ate( cabecalho_int.icone, NDSCART_TAMINT_ICONE );
 printf( "Dados da paleta...\n" );
 imprime_hexa_ate( cabecalho_int.paleta, NDSCART_TAMINT_PALETA );
#endif
 printf( "Título japonês...\n\n%s\n\n", tcjapa );
 printf( "Título inglês...\n\n%s\n\n", tcingles );
 printf( "Título francês...\n\n%s\n\n", tcfrances );
 printf( "Título alemão...\n\n%s\n\n", tcalemao );
 printf( "Título italiano...\n\n%s\n\n", tcitalia );
 printf( "Título espanhol...\n\n%s\n\n", tcespanha );
 printf( "Título chinês...\n\n%s\n\n", tcchines );
}

/* Principal */

int main ( int argc, char *argv[] )
{
 FILE *rom = 0;
 int testi = 0;
 size_t teste = 0;

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

  teste = ndscart_pega_cab( rom, &cabecalho_ntr );
  printf( "Arquivo: \"%s\".\n", argv[testi] );
  info_nds();

  if ( cabecalho_ntr.tituloicon != 0 )
{
   printf( "Títulos internacionais...\n\n" );
   fseek( rom, cabecalho_ntr.tituloicon - teste, SEEK_CUR );
   ndscart_pega_internacional( rom, &cabecalho_int );
   info_inds();
}

  fclose(rom);
}

 return(0);
}
