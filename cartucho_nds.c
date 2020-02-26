/* pt_BR.utf-8

Sobre os cartuchos de NDS.
*/

#include <iconv.h>
#include <stdio.h>

#include "cartucho_nds.h"

int ndscart_convint( char *titulo_ent, char *titulo_sai )
{
 iconv_t iconman = 0;
 size_t falta_ent = NDSCART_TAMANHO_TITULOINT, falta_sai = NDSCART_TAMANHO_TITULOINT * 2, teste = 0;

 iconman = iconv_open( "UTF-8", "UTF-16" );

 if ( iconman == (iconv_t) -1 )
{
#ifdef TESTE
  fprintf( stderr, "Não foi possível realizar a conversão para UTF-8!\n" );
#endif
  return(1);
}

#ifdef TESTE
 printf( "Convertendo...\n" );
#endif
 teste = iconv( iconman, &titulo_ent, &falta_ent, &titulo_sai, &falta_sai );
 iconv_close(iconman);

 if ( teste == (size_t) -1 )
{
#ifdef TESTE
  fprintf( stderr, "Problemas durante a conversão!\n" );
#endif
  return(2);
}

 return(0);
}

size_t ndscart_pega_cab( FILE *rom, cabecalho_nds *cabecalho_ntr )
{
 size_t teste = 0;
 teste += fread( &cabecalho_ntr->titulo, 1, NDSCART_TAMANHO_TITULO, rom );
 teste += fread( &cabecalho_ntr->codigo, 1, NDSCART_TAMANHO_CODIGO, rom );
 teste += fread( &cabecalho_ntr->produtor, 1, NDSCART_TAMANHO_PRODUTOR, rom );
 teste += fread( &cabecalho_ntr->dispositivo, 1, 1, rom );
 teste += fread( &cabecalho_ntr->encsemente, 1, 1, rom );
 teste += fread( &cabecalho_ntr->tamcart, 1, 1, rom );
 teste += fread( &cabecalho_ntr->reserva1, 1, NDSCART_TAMANHO_RESERVA1, rom );
 teste += fread( &cabecalho_ntr->versao, 1, 1, rom );
 teste += fread( &cabecalho_ntr->autoini, 1, 1, rom );
 teste += fread( &cabecalho_ntr->endromarm9, 1, NDSCART_TAMANHO_ENDROMARM9, rom );
 teste += fread( &cabecalho_ntr->endentarm9, 1, NDSCART_TAMANHO_ENDENTARM9, rom );
 teste += fread( &cabecalho_ntr->endramarm9, 1, NDSCART_TAMANHO_ENDRAMARM9, rom );
 teste += fread( &cabecalho_ntr->tamarm9, 1, NDSCART_TAMANHO_TAMARM9, rom );
 teste += fread( &cabecalho_ntr->endromarm7, 1, NDSCART_TAMANHO_ENDROMARM7, rom );
 teste += fread( &cabecalho_ntr->endentarm7, 1, NDSCART_TAMANHO_ENDENTARM7, rom );
 teste += fread( &cabecalho_ntr->endramarm7, 1, NDSCART_TAMANHO_ENDRAMARM7, rom );
 teste += fread( &cabecalho_ntr->tamarm7, 1, NDSCART_TAMANHO_TAMARM7, rom );
 teste += fread( &cabecalho_ntr->endfnt, 1, NDSCART_TAMANHO_ENDFNT, rom );
 teste += fread( &cabecalho_ntr->tamfnt, 1, NDSCART_TAMANHO_TAMFNT, rom );
 teste += fread( &cabecalho_ntr->endfat, 1, NDSCART_TAMANHO_ENDFAT, rom );
 teste += fread( &cabecalho_ntr->tamfat, 1, NDSCART_TAMANHO_TAMFAT, rom );
 teste += fread( &cabecalho_ntr->endreparm9, 1, NDSCART_TAMANHO_ENDREPARM9, rom );
 teste += fread( &cabecalho_ntr->tamreparm9, 1, NDSCART_TAMANHO_TAMREPARM9, rom );
 teste += fread( &cabecalho_ntr->endreparm7, 1, NDSCART_TAMANHO_ENDREPARM7, rom );
 teste += fread( &cabecalho_ntr->tamreparm7, 1, NDSCART_TAMANHO_TAMREPARM7, rom );
 teste += fread( &cabecalho_ntr->normalcfg, 1, NDSCART_TAMANHO_NORMALCFG, rom );
 teste += fread( &cabecalho_ntr->key1cfg, 1, NDSCART_TAMANHO_KEY1CFG, rom );
 teste += fread( &cabecalho_ntr->tituloicon, 1, NDSCART_TAMANHO_TITULOICON, rom );
 teste += fread( &cabecalho_ntr->somaregseg, 1, NDSCART_TAMANHO_SOMAREGSEG, rom );
 teste += fread( &cabecalho_ntr->temporegseg, 1, NDSCART_TAMANHO_TEMPOREGSEG, rom );
 teste += fread( &cabecalho_ntr->calramarm9, 1, NDSCART_TAMANHO_CALRAMARM9, rom );
 teste += fread( &cabecalho_ntr->calramarm7, 1, NDSCART_TAMANHO_CALRAMARM7, rom );
 teste += fread( &cabecalho_ntr->estregseg, 1, NDSCART_TAMANHO_ESTREGSEG, rom );
 teste += fread( &cabecalho_ntr->tamtotalrom, 1, NDSCART_TAMANHO_TAMTOTALROM, rom );
 teste += fread( &cabecalho_ntr->tamtotalcab, 1, NDSCART_TAMANHO_TAMTOTALCAB, rom );
 teste += fread( &cabecalho_ntr->reserva2, 1, NDSCART_TAMANHO_RESERVA2, rom );
 teste += fread( &cabecalho_ntr->logo, 1, NDSCART_TAMANHO_LOGO, rom );
 teste += fread( &cabecalho_ntr->somalogo, 1, NDSCART_TAMANHO_SOMALOGO, rom );
 teste += fread( &cabecalho_ntr->somacab, 1, NDSCART_TAMANHO_SOMACAB, rom );
 teste += fread( &cabecalho_ntr->enddebugrom, 1, NDSCART_TAMANHO_ENDDEBUGROM, rom );
 teste += fread( &cabecalho_ntr->tamdebug, 1, NDSCART_TAMANHO_TAMDEBUG, rom );
 teste += fread( &cabecalho_ntr->enddebugram, 1, NDSCART_TAMANHO_ENDDEBUGRAM, rom );
 teste += fread( &cabecalho_ntr->reserva3, 1, NDSCART_TAMANHO_RESERVA3, rom );
 teste += fread( &cabecalho_ntr->final, 1, NDSCART_TAMANHO_FINAL, rom );
 return(teste);
}

size_t ndscart_pega_internacional( FILE *rom, internacional_nds *cabecalho_int )
{
 size_t teste = 0;
 teste += fread( &cabecalho_int->versao, 1, NDSCART_TAMINT_VERSAO, rom );
 teste += fread( &cabecalho_int->somanorm, 1, NDSCART_TAMINT_SOMANORM, rom );
 teste += fread( &cabecalho_int->somachina, 1, NDSCART_TAMINT_SOMACHINA, rom );
 teste += fread( &cabecalho_int->reservado, 1, NDSCART_TAMINT_RESERVADO, rom );
 teste += fread( &cabecalho_int->icone, 1, NDSCART_TAMINT_ICONE, rom );
 teste += fread( &cabecalho_int->paleta, 1, NDSCART_TAMINT_PALETA, rom );
 teste += fread( &cabecalho_int->tjapa, 1, NDSCART_TAMANHO_TITULOINT, rom );
 teste += fread( &cabecalho_int->tingles, 1, NDSCART_TAMANHO_TITULOINT, rom );
 teste += fread( &cabecalho_int->tfrances, 1, NDSCART_TAMANHO_TITULOINT, rom );
 teste += fread( &cabecalho_int->talemao, 1, NDSCART_TAMANHO_TITULOINT, rom );
 teste += fread( &cabecalho_int->titalia, 1, NDSCART_TAMANHO_TITULOINT, rom );
 teste += fread( &cabecalho_int->tespanha, 1, NDSCART_TAMANHO_TITULOINT, rom );
 teste += fread( &cabecalho_int->tchines, 1, NDSCART_TAMANHO_TITULOINT, rom );
 return(teste);
}
