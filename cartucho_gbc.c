/* pt_BR.utf-8

Sobre os cartuchos de (Super) Game Boy (Color).
*/

#include <stdio.h>

#include "cartucho_gbc.h"

/* Gambiarra até fundamentar tudo melhor... */
unsigned short int gbsoma_alt_final( unsigned short soma )
{
 soma = ( soma * 0x100 ) + ( soma / 0x100 );
 return(soma);
}

size_t gbcart_pega_cab( FILE *rom, cabecalho_gb *cabecalho_cgb )
{
 size_t teste = 0;
 teste += fread( &cabecalho_cgb->rotina, 1, GBCART_TAMANHO_ROTINA1, rom );
 teste += fread( &cabecalho_cgb->logo, 1, GBCART_TAMANHO_LOGO, rom );
 teste += fread( &cabecalho_cgb->titulo.titulo, 1, GBCCART_TAMANHO_TITULO, rom );
 teste += fread( &cabecalho_cgb->titulo.codigo, 1, GBCCART_TAMANHO_CODIGO, rom );
 teste += fread( &cabecalho_cgb->titulo.cgb, 1, 1, rom );
 teste += fread( &cabecalho_cgb->prod_novo, 1, GBCART_TAMANHO_PRODNOVO, rom );
 teste += fread( &cabecalho_cgb->sgb, 1, 1, rom );
 teste += fread( &cabecalho_cgb->tipo, 1, 1, rom );
 teste += fread( &cabecalho_cgb->tamrom, 1, 1, rom );
 teste += fread( &cabecalho_cgb->tamram, 1, 1, rom );
 teste += fread( &cabecalho_cgb->mercado, 1, 1, rom );
 teste += fread( &cabecalho_cgb->prod_velho, 1, 1, rom );
 teste += fread( &cabecalho_cgb->versao, 1, 1, rom );
 teste += fread( &cabecalho_cgb->soma_cab, 1, 1, rom );
 teste += fread( &cabecalho_cgb->soma_total, 1, GBCART_TAMANHO_SOMAROM, rom );
#ifndef _BIG_ENDIAN_
 cabecalho_cgb->soma_total = gbsoma_alt_final( cabecalho_cgb->soma_total );
#endif
 return(teste);
}
