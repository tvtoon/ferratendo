/* pt_BR.utf-8

Sobre os cartuchos de (Super) Game Boy (Color).
*/

#define GBCART_ENDERECO_ROTINA1 0x100
#define GBCART_TAMANHO_ROTINA1 4
#define GBCART_ENDERECO_LOGO 0x104
#define GBCART_TAMANHO_LOGO 48
#define GBCART_ENDERECO_TITULO 0x134
/* Tamanho varia dependendo da época. */
#define GBCART_TAMANHO_TITULO 16
#define GBCCART_TAMANHO_TITULO 11
/* Código e outro da era GBC. */
#define GBCCART_ENDERECO_CODIGO 0x13F
#define GBCCART_TAMANHO_CODIGO 4
#define GBCCART_ENDERECO_CGB 0x143
#define GBCCART_TAMANHO_CGB 1
/* Novo endereço das produtoras, da época do SGB. */
#define GBCART_ENDERECO_PRODNOVO 0x144
#define GBCART_TAMANHO_PRODNOVO 2
#define GBCART_ENDERECO_SGB 0x146
#define GBCART_TAMANHO_SGB 1
#define GBCART_ENDERECO_TIPO 0x147
#define GBCART_TAMANHO_TIPO 1
#define GBCART_ENDERECO_TAMROM 0x148
#define GBCART_TAMANHO_TAMROM 1
#define GBCART_ENDERECO_TAMRAM 0x149
#define GBCART_TAMANHO_TAMRAM 1
#define GBCART_ENDERECO_MERCADO 0x14A
#define GBCART_TAMANHO_MERCADO 1
#define GBCART_ENDERECO_PRODVELHO 0x14B
#define GBCART_TAMANHO_PRODVELHO 1
#define GBCART_ENDERECO_VERSAO 0x14C
#define GBCART_TAMANHO_VERSAO 1
#define GBCART_ENDERECO_SOMACAB 0x14D
#define GBCART_TAMANHO_SOMACAB 1
#define GBCART_ENDERECO_SOMAROM 0x14E
#define GBCART_TAMANHO_SOMAROM 2

typedef struct
{
 char titulo[GBCCART_TAMANHO_TITULO + 1];
 char codigo[GBCCART_TAMANHO_CODIGO + 1];
 unsigned char cgb;
} titulo_gbx;

typedef struct
{
 unsigned char rotina[GBCART_TAMANHO_ROTINA1];
 unsigned char logo[GBCART_TAMANHO_LOGO];
 titulo_gbx titulo;
 char prod_novo[GBCART_TAMANHO_PRODNOVO + 1];
 unsigned char sgb;
 unsigned char tipo;
 unsigned char tamrom;
 unsigned char tamram;
 unsigned char mercado;
 unsigned char prod_velho;
 unsigned char versao;
 unsigned char soma_cab;
 unsigned short int soma_total;
} cabecalho_gb;

unsigned short int gbsoma_alt_final( unsigned short soma );
size_t gbcart_pega_cab( FILE *rom, cabecalho_gb *cabecalho_cgb );
