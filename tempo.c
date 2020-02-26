/* pt_BR.utf-8
Temporariz, cacildiz.
*/

#include <stdio.h>

void imprime_hexa_ate( unsigned char *de, const size_t ate )
{
 size_t conta = 0;
 unsigned int coluna = 1;

 for ( ; conta < ate; conta++ )
{
  printf( "%02X", de[conta] );

  if ( coluna == 16 )
{
   printf( "\n" );
   coluna = 1;
}
  else
{
   printf( " " );
   coluna++;
}

}

 printf( "\n" );
}
