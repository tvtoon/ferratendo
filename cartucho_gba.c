/* pt_BR.utf-8

Sobre os cartuchos de GBA.
*/

#include <stdio.h>

#include "cartucho_gba.h"

int gbacart_checa_fixo( unsigned char fixo )
{

 if ( fixo == GBACART_VALOR_FIXO )
{
  return(0);
}
 else
{
  return(1);
}

}

size_t gbacart_pega_cab( FILE *rom, cabecalho_gba *cabecalho_agb )
{
 size_t teste = 0;
 teste += fread( &cabecalho_agb->rotina, 1, GBACART_TAMANHO_ROTINA1, rom );
 teste += fread( &cabecalho_agb->logo, 1, GBACART_TAMANHO_LOGO, rom );
 teste += fread( &cabecalho_agb->titulo, 1, GBACART_TAMANHO_TITULO, rom );
 teste += fread( &cabecalho_agb->codigo, 1, GBACART_TAMANHO_CODIGO, rom );
 teste += fread( &cabecalho_agb->produtor, 1, GBACART_TAMANHO_PRODUTOR, rom );
 teste += fread( &cabecalho_agb->valor_fixo, 1, 1, rom );
 teste += fread( &cabecalho_agb->unidade, 1, 1, rom );
 teste += fread( &cabecalho_agb->dispositivo, 1, 1, rom );
 teste += fread( &cabecalho_agb->reservado, 1, GBACART_TAMANHO_RESERVADO, rom );
 teste += fread( &cabecalho_agb->versao, 1, 1, rom );
 teste += fread( &cabecalho_agb->soma, 1, 1, rom );
 teste += fread( &cabecalho_agb->final, 1, GBACART_TAMANHO_FINAL, rom );
 return(teste);
}
