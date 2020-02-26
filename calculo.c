/* pt_BR.utf-8
Cálculos de soma de verificação e afins...
*/
#include <stdio.h>

unsigned char calc_soma1byte( FILE *rom, const unsigned int quantia )
{
 int byte = 0;
 unsigned char soma = 0;
 unsigned int pos = 0;

 for ( ; pos < quantia; pos++ )
{
  byte = getc(rom);
  soma = soma - byte;
}

 soma = ( soma - 0x19 ) % 0x100;
 return(soma);
}

unsigned char calc_somagb( FILE *rom, const unsigned int quantia )
{
 int byte = 0;
 unsigned char soma = 0;
 unsigned int pos = 0;

 for ( ; pos < quantia; pos++ )
{
  byte = getc(rom);
  soma = soma - byte - 1;
}

 return(soma);
}
