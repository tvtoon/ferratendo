/* pt_BR.utf-8
Códigos usados nos cartuchos de (Super) Game Boy (Color).
*/

/* É uma operação espelho, limitando os índices em 1 byte, depois alterando os nibbles! */
const byte_explicado cgb_marca[3] =
{
 { 0x0, "incompatível" },
 { 0x80, "compatível" },
 { 0xc0, "somente CGB" }
};

const char *sgb_marca[4] = { "Sem suporte ao SGB.", "\0", "\0", "Suporta as funções do SGB." };

const byte_explicado gbcart_tipo[30] =
{
 { 0x0, "ROM" },
 { 0x1, "ROM + MBC1" },
 { 0x2, "ROM + MBC1 + RAM" },
 { 0x3, "ROM + MBC1 + RAM + BATERIA" },
 { 0x5, "ROM + MBC2" },
 { 0x6, "ROM + MBC2 + BATERIA" },
 { 0x8, "ROM + RAM" },
 { 0x9, "ROM + RAM + BATERIA" },
 { 0xB, "ROM + MMM01" },
 { 0xC, "ROM + MMM01 + RAM" },
 { 0xD, "ROM + MMM01 + RAM + BATERIA" },
 { 0xF, "ROM + MBC3 + TEMPORIZADOR + BATERIA" },
 { 0x10, "ROM + MBC3 + TEMPORIZADOR + RAM + BATERIA" },
 { 0x11, "ROM + MBC3" },
 { 0x12, "ROM + MBC3 + RAM" },
 { 0x13, "ROM + MBC3 + RAM + BATERIA" },
 { 0x15, "ROM + MBC4" },
 { 0x16, "ROM + MBC4 + RAM" },
 { 0x17, "ROM + MBC4 + RAM + BATERIA" },
 { 0x19, "ROM + MBC5" },
 { 0x1A, "ROM + MBC5 + RAM" },
 { 0x1B, "ROM + MBC5 + RAM + BATERIA" },
 { 0x1C, "ROM + MBC5 + RUMBLE" },
 { 0x1D, "ROM + MBC5 + RUMBLE + RAM" },
 { 0x1E, "ROM + MBC5 + RUMBLE + RAM + BATERIA" },
/* Kirby Tilt N Tumble */
 { 0x22, "ROM + MBC7 + SENSOR DE MOVIMENTOS + BATERIA" },
 { 0xFC, "POCKET CAMERA" },
 { 0xFD, "BANDAI TAMA5" },
 { 0xFE, "HuC3" },
 { 0xFF, "HuC1 + RAM + BATERIA" }
};

/* Cálculo: "32KB << índice" */
const byte_explicado gbcart_tamrom[12] =
{
 { 0x0, "32 KBytes" },
 { 0x1, "64 KBytes" },
 { 0x2, "128 KBytes" },
 { 0x3, "256 KBytes" },
 { 0x4, "512 KBytes" },
 { 0x5, "1 MByte" },
 { 0x6, "2 MBytes" },
 { 0x7, "4 MBytes" },
 { 0x8, "8 MBytes" },
/* 1,1MB ...*/
 { 0x52, "1,1 MBytes" },
 { 0x53, "1,2 MBytes" },
 { 0x54, "1,5 MBytes" }
};

const char *gbcart_tamram[6] =
{ "0 KB", "2 KB", "8 KB", "32 KB", "128 KB",
/* De acordo com o VBA... */
  "64 KB"
};

const char *gbcart_mercado[2] = { "Japão", "outros" };
