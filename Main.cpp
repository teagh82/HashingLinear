#include "HashMap.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
  HashMap hash;

  hash.addLinearProb( "do", "반복" );
  hash.addLinearProb( "for", "반복" );
  hash.addLinearProb( "if", "분기" );
  hash.addLinearProb( "case", " 분기 " );
  hash.addLinearProb( "else", "분기" );
  hash.addLinearProb( "return", "반환" );
  hash.addLinearProb( "function", "함수" );
  hash.display();
  hash.searchLinearProb ( "return" );
  hash.searchLinearProb( "function" );
  hash.searchLinearProb( "class" );

  system("pause");
}
