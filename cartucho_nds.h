/* pt_BR.utf-8

Sobre os cartuchos de NDS.
*/

#define NDSCART_ENDERECO_TITULO 0x0
#define NDSCART_TAMANHO_TITULO 12
#define NDSCART_ENDERECO_CODIGO 0xC
#define NDSCART_TAMANHO_CODIGO 4
#define NDSCART_ENDERECO_PRODUTOR 0x10
#define NDSCART_TAMANHO_PRODUTOR 2
#define NDSCART_ENDERECO_DISPOSITIVO 0x12
#define NDSCART_TAMANHO_DISPOSITIVO 1
/* Base ou semente da encriptação. */
#define NDSCART_ENDERECO_ENCSEMENTE 0x13
#define NDSCART_TAMANHO_ENCSEMENTE 1
#define NDSCART_ENDERECO_TAMCART 0x14
#define NDSCART_TAMANHO_TAMCART 1
#define NDSCART_ENDERECO_RESERVA1 0x15
#define NDSCART_TAMANHO_RESERVA1 9
#define NDSCART_ENDERECO_VERSAO 0x1E
#define NDSCART_TAMANHO_VERSAO 1
#define NDSCART_ENDERECO_AUTOINI 0x1F
#define NDSCART_TAMANHO_AUTOINI 1
#define NDSCART_ENDERECO_ENDROMARM9 0x20
#define NDSCART_TAMANHO_ENDROMARM9 4
#define NDSCART_ENDERECO_ENDENTARM9 0x24
#define NDSCART_TAMANHO_ENDENTARM9 4
#define NDSCART_ENDERECO_ENDRAMARM9 0x28
#define NDSCART_TAMANHO_ENDRAMARM9 4
#define NDSCART_ENDERECO_TAMARM9 0x2C
#define NDSCART_TAMANHO_TAMARM9 4
#define NDSCART_ENDERECO_ENDROMARM7 0x30
#define NDSCART_TAMANHO_ENDROMARM7 4
#define NDSCART_ENDERECO_ENDENTARM7 0x34
#define NDSCART_TAMANHO_ENDENTARM7 4
#define NDSCART_ENDERECO_ENDRAMARM7 0x38
#define NDSCART_TAMANHO_ENDRAMARM7 4
#define NDSCART_ENDERECO_TAMARM7 0x3C
#define NDSCART_TAMANHO_TAMARM7 4
#define NDSCART_ENDERECO_ENDFNT 0x40
#define NDSCART_TAMANHO_ENDFNT 4
#define NDSCART_ENDERECO_TAMFNT 0x44
#define NDSCART_TAMANHO_TAMFNT 4
#define NDSCART_ENDERECO_ENDFAT 0x48
#define NDSCART_TAMANHO_ENDFAT 4
#define NDSCART_ENDERECO_TAMFAT 0x4C
#define NDSCART_TAMANHO_TAMFAT 4
/* Repositor (overlay). */
#define NDSCART_ENDERECO_ENDREPARM9 0x50
#define NDSCART_TAMANHO_ENDREPARM9 4
#define NDSCART_ENDERECO_TAMREPARM9 0x54
#define NDSCART_TAMANHO_TAMREPARM9 4
#define NDSCART_ENDERECO_ENDREPARM7 0x58
#define NDSCART_TAMANHO_ENDREPARM7 4
#define NDSCART_ENDERECO_TAMREPARM7 0x5C
#define NDSCART_TAMANHO_TAMREPARM7 4
/*
Configurações da porta 0x40001A4, para comandos normais e
do tipo "KEY1" (Encriptação?).
*/
#define NDSCART_ENDERECO_NORMALCFG 0x60
#define NDSCART_TAMANHO_NORMALCFG 4
#define NDSCART_ENDERECO_KEY1CFG 0x64
#define NDSCART_TAMANHO_KEY1CFG 4
/*
Endereço dos títulos internacionais exibidos juntos ao ícone dos jogos antes
de inicializar o jogo, no firmware.
*/
#define NDSCART_ENDERECO_TITULOICON 0x68
#define NDSCART_TAMANHO_TITULOICON 4
/* Dados da região segura: soma e tempo de espera. */
#define NDSCART_ENDERECO_SOMAREGSEG 0x6C
#define NDSCART_TAMANHO_SOMAREGSEG 2
#define NDSCART_ENDERECO_TEMPOREGSEG 0x6E
#define NDSCART_TAMANHO_TEMPOREGSEG 2
/*
Carregamento automático da lista de endereços da RAM, para ARM9 e ARM7.
Nem o GBATEK sabe para que serve isso...
*/
#define NDSCART_ENDERECO_CALRAMARM9 0x70
#define NDSCART_TAMANHO_CALRAMARM9 4
#define NDSCART_ENDERECO_CALRAMARM7 0x74
#define NDSCART_TAMANHO_CALRAMARM7 4
/*
Estado da região segura (ligado ou desligado), dado por "NmMdOnly" encriptado.
Verificar como a máquina carrega isso para definir também o tipo de dado!
*/
#define NDSCART_ENDERECO_ESTREGSEG 0x78
#define NDSCART_TAMANHO_ESTREGSEG 8
/* Esse é o tamanho total usado pelos dados do jogo, não o do cartucho! */
#define NDSCART_ENDERECO_TAMTOTALROM 0x80
#define NDSCART_TAMANHO_TAMTOTALROM 4
/* Tamanho total do cabeçalho, geralmente 0x4000. */
#define NDSCART_ENDERECO_TAMTOTALCAB 0x84
#define NDSCART_TAMANHO_TAMTOTALCAB 4
#define NDSCART_VALOR_TAMTOTALCAB 16384
#define NDSCART_ENDERECO_RESERVA2 0x88
#define NDSCART_TAMANHO_RESERVA2 56
/* Mesmo logo do GBA. */
#define NDSCART_ENDERECO_LOGO 0xC0
#define NDSCART_TAMANHO_LOGO 156
/*
Soma de verificação do logo, como o logo é sempre o mesmo, a soma também será.
*/
#define NDSCART_ENDERECO_SOMALOGO 0x15C
#define NDSCART_TAMANHO_SOMALOGO 2
#define NDSCART_VALOR_SOMALOGO 0xCF56
/* Soma de verificação do cabeçalho, 0x0 até 0x15D. */
#define NDSCART_ENDERECO_SOMACAB 0x15E
#define NDSCART_TAMANHO_SOMACAB 2
/* Debug que geralmente não vem no jogo... */
#define NDSCART_ENDERECO_ENDDEBUGROM 0x160
#define NDSCART_TAMANHO_ENDDEBUGROM 4
#define NDSCART_ENDERECO_TAMDEBUG 0x164
#define NDSCART_TAMANHO_TAMDEBUG 4
#define NDSCART_ENDERECO_ENDDEBUGRAM 0x168
#define NDSCART_TAMANHO_ENDDEBUGRAM 4
/* Reserva que é guardada mas não é usada, o final não é guardado na RAM. */
#define NDSCART_ENDERECO_RESERVA3 0x16C
#define NDSCART_TAMANHO_RESERVA3 4
#define NDSCART_ENDERECO_FINAL 0x170
#define NDSCART_TAMANHO_FINAL 144

/*
Seção dos títulos internacionais e ícones.
Endereços são relativos ao início!
Versões: 1 para original e 2 para chinesa...
*/

#define NDSCART_ENDINT_VERSAO 0x0
#define NDSCART_TAMINT_VERSAO 2
/*
Soma da versão normal ou com a chinesa (zerada se não ativada).
Vão a partir do endereço 0x20 até 0x83F ou 0x93F, dependendo da versão.
*/
#define NDSCART_ENDINT_SOMANORM 0x2
#define NDSCART_TAMINT_SOMANORM 2
#define NDSCART_ENDINT_SOMACHINA 0x4
#define NDSCART_TAMINT_SOMACHINA 2
#define NDSCART_ENDINT_RESERVADO 0x6
#define NDSCART_TAMINT_RESERVADO 26
/* Formato do ícone é 4BPP linear-inverso (GBA), 32x32. */
#define NDSCART_ENDINT_ICONE 0x20
#define NDSCART_TAMINT_ICONE 512
/*
Paleta de 4BPP (16 cores), com valores em 16 bits e, segundo o GBATEK,
indo de 0x0 até 0x7FFF.
Então é incorreto afirmar isso, pois seriam 15 bits mais a cor 0 sendo
transparente e a primeira entrada sendo ignorada. (???)
*/
#define NDSCART_ENDINT_PALETA 0x220
#define NDSCART_TAMINT_PALETA 32
/* Todos em UTF-16, chinesa só aparece ativado. (???) */
#define NDSCART_ENDINT_TJAPA 0x240
#define NDSCART_ENDINT_TINGLES 0x340
#define NDSCART_ENDINT_TFRANCES 0x440
#define NDSCART_ENDINT_TALEMAO 0x540
#define NDSCART_ENDINT_TITALIA 0x640
#define NDSCART_ENDINT_TESPANHA 0x740
#define NDSCART_ENDINT_TCHINES 0x840
#define NDSCART_TAMANHO_TITULOINT 256

typedef struct
{
 char titulo[NDSCART_TAMANHO_TITULO + 1];
 char codigo[NDSCART_TAMANHO_CODIGO + 1];
 char produtor[NDSCART_TAMANHO_PRODUTOR + 1];
 unsigned char dispositivo;
 unsigned char encsemente;
 unsigned char tamcart;
 unsigned char reserva1[NDSCART_TAMANHO_RESERVA1];
 unsigned char versao;
 unsigned char autoini;
 int endromarm9;
 int endentarm9;
 int endramarm9;
 unsigned int tamarm9;
 int endromarm7;
 int endentarm7;
 int endramarm7;
 unsigned int tamarm7;
 int endfnt;
 unsigned int tamfnt;
 int endfat;
 unsigned int tamfat;
 int endreparm9;
 unsigned int tamreparm9;
 int endreparm7;
 unsigned int tamreparm7;
 unsigned int normalcfg;
 unsigned int key1cfg;
 int tituloicon;
 unsigned short int somaregseg;
 unsigned short int temporegseg;
 int calramarm9;
 int calramarm7;
 unsigned char estregseg[NDSCART_TAMANHO_ESTREGSEG];
 unsigned int tamtotalrom;
 unsigned int tamtotalcab;
 unsigned char reserva2[NDSCART_TAMANHO_RESERVA2];
 unsigned char logo[NDSCART_TAMANHO_LOGO];
 unsigned short int somalogo;
 unsigned short int somacab;
 int enddebugrom;
 unsigned int tamdebug;
 int enddebugram;
 unsigned int reserva3;
 unsigned char final[NDSCART_TAMANHO_FINAL];
} cabecalho_nds;


typedef struct
{
 unsigned short versao;
 unsigned short somanorm;
 unsigned short somachina;
 unsigned char reservado[NDSCART_TAMINT_RESERVADO];
 unsigned char icone[NDSCART_TAMINT_ICONE];
 unsigned char paleta[NDSCART_TAMINT_PALETA];
 char tjapa[NDSCART_TAMANHO_TITULOINT + 1];
 char tingles[NDSCART_TAMANHO_TITULOINT + 1];
 char tfrances[NDSCART_TAMANHO_TITULOINT + 1];
 char talemao[NDSCART_TAMANHO_TITULOINT + 1];
 char titalia[NDSCART_TAMANHO_TITULOINT + 1];
 char tespanha[NDSCART_TAMANHO_TITULOINT + 1];
 char tchines[NDSCART_TAMANHO_TITULOINT + 1];
} internacional_nds;

int ndscart_convint( char *titulo_ent, char *titulo_sai );
size_t ndscart_pega_cab( FILE *rom, cabecalho_nds *cabecalho_ntr );
size_t ndscart_pega_internacional( FILE *rom, internacional_nds *cabecalho_int );
