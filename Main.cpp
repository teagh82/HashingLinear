#include "HashMap.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
  HashMap hash;

  hash.addLinearProb( "do", "�ݺ�" );
  hash.addLinearProb( "for", "�ݺ�" );
  hash.addLinearProb( "if", "�б�" );
  hash.addLinearProb( "case", " �б� " );
  hash.addLinearProb( "else", "�б�" );
  hash.addLinearProb( "return", "��ȯ" );
  hash.addLinearProb( "function", "�Լ�" );
  hash.display();
  hash.searchLinearProb ( "return" );
  hash.searchLinearProb( "function" );
  hash.searchLinearProb( "class" );

  system("pause");
}
