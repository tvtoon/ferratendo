#define N64C_VALID_TAM 2
#define N64C_COMP_TAM 1
#define N64C_DESC1_TAM 1
#define N64C_FREQ_TAM 4
#define N64C_CONTADOR_TAM 4
#define N64C_LANCA_TAM 4
#define N64C_CRCs_TAM 4
#define N64C_DESC2_TAM 8
#define N64C_TITULO_TAM 20
#define N64C_DESC3_TAM 7
#define N64C_CODIGO_TAM 4
#define N64C_VERSAO_TAM 1
#define N64C_TAM 64

typedef struct
{
 unsigned short validacao;
 unsigned char compressao;
 unsigned char desc1;
 unsigned int frequencia;
 unsigned int conta_prog;
 unsigned int lancamento;
 unsigned int crc1;
 unsigned int crc2;
 unsigned char desc2[N64C_DESC2_TAM];
 char titulo[N64C_TITULO_TAM + 1];
 unsigned char desc3[N64C_DESC3_TAM];
 char codigo[N64C_CODIGO_TAM + 1];
 unsigned char versao;
} cabecalho_n64;

size_t n64c_pegacab( FILE *rom, cabecalho_n64 *cabecalho_ult );
