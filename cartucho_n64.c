/*
Cartuchos de Nintendo 64.
*/

#include <stdio.h>

#include "cartucho_n64.h"

size_t n64c_pegacab( FILE *rom, cabecalho_n64 *cabecalho_ult )
{
 size_t teste = 0;
 teste += fread( &cabecalho_ult->validacao, 1, N64C_VALID_TAM, rom );
 teste += fread( &cabecalho_ult->compressao, 1, N64C_COMP_TAM, rom );
 teste += fread( &cabecalho_ult->desc1, 1, N64C_DESC1_TAM, rom );
 teste += fread( &cabecalho_ult->frequencia, 1, N64C_FREQ_TAM, rom );
 teste += fread( &cabecalho_ult->conta_prog, 1, N64C_CONTADOR_TAM, rom );
 teste += fread( &cabecalho_ult->lancamento, 1, N64C_LANCA_TAM, rom );
 teste += fread( &cabecalho_ult->crc1, 1, N64C_CRCs_TAM, rom );
 teste += fread( &cabecalho_ult->crc2, 1, N64C_CRCs_TAM, rom );
 teste += fread( &cabecalho_ult->desc2, 1, N64C_DESC2_TAM, rom );
 teste += fread( &cabecalho_ult->titulo, 1, N64C_TITULO_TAM, rom );
 teste += fread( &cabecalho_ult->desc3, 1, N64C_DESC3_TAM, rom );
 teste += fread( &cabecalho_ult->codigo, 1, N64C_CODIGO_TAM, rom );
 teste += fread( &cabecalho_ult->versao, 1, N64C_VERSAO_TAM, rom );
 return(teste);
}
