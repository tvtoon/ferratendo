/* pt_BR.utf-8
Transcreve códigos para exibição.
*/
#include <stdlib.h>

#include "codigos.h"

int trans_byte_explicado( const byte_explicado *bytes_exp, unsigned char byte, int indice_max )
{
 int conta = 0;

 for ( ; conta < indice_max; conta++ )
{

  if ( bytes_exp[conta].byte == byte )
{
   return(conta);
}

}

 return(-1);
}

unsigned int trans36( const char *codigo )
{
 char *fimca = "\0";
 unsigned int conta = 0;

 conta = strtoul( codigo, &fimca, 36 );

 if ( fimca[0] != '\0' )
{
  conta = 0;
}

 return(conta);
}
