/* pt_BR.utf-8

Sobre os cartuchos de GBA.
*/

#define GBACART_ENDERECO_ROTINA1 0x0
#define GBACART_TAMANHO_ROTINA1 4
#define GBACART_ENDERECO_LOGO 0x4
#define GBACART_TAMANHO_LOGO 156
#define GBACART_ENDERECO_TITULO 0xA0
#define GBACART_TAMANHO_TITULO 12
#define GBACART_ENDERECO_CODIGO 0xAC
#define GBACART_TAMANHO_CODIGO 4
#define GBACART_ENDERECO_PRODUTOR 0xB0
#define GBACART_TAMANHO_PRODUTOR 2
#define GBACART_VALOR_FIXO 0x96
#define GBACART_ENDERECO_VALOR_FIXO 0xB2
#define GBACART_TAMANHO_VALOR_FIXO 1
#define GBACART_ENDERECO_UNIDADE 0xB3
#define GBACART_TAMANHO_UNIDADE 1
#define GBACART_ENDERECO_DISPOSITIVO 0xB4
#define GBACART_TAMANHO_DISPOSITIVO 1
#define GBACART_ENDERECO_RESERVADO 0xB5
#define GBACART_TAMANHO_RESERVADO 7
#define GBACART_ENDERECO_VERSAO 0xBC
#define GBACART_TAMANHO_VERSAO 1
#define GBACART_ENDERECO_SOMA 0xBD
#define GBACART_TAMANHO_SOMA 1
#define GBACART_ENDERECO_FINAL 0xBE
#define GBACART_TAMANHO_FINAL 2

typedef struct
{
 unsigned char rotina[GBACART_TAMANHO_ROTINA1];
 unsigned char logo[GBACART_TAMANHO_LOGO];
 char titulo[GBACART_TAMANHO_TITULO + 1];
 char codigo[GBACART_TAMANHO_CODIGO + 1];
 char produtor[GBACART_TAMANHO_PRODUTOR + 1];
 unsigned char valor_fixo;
 unsigned char unidade;
 unsigned char dispositivo;
 unsigned char reservado[GBACART_TAMANHO_RESERVADO];
 unsigned char versao;
 unsigned char soma;
 unsigned char final[GBACART_TAMANHO_FINAL];
} cabecalho_gba;

int gbacart_checa_fixo( unsigned char fixo );
size_t gbacart_pega_cab( FILE *rom, cabecalho_gba *cabecalho_agb );
