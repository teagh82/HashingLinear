#pragma once
#include "Record.h"
#define TABLE_SIZE 13 


inline int transform(char *key) { // ���ڿ� Ű�� ���ڷ� ��ȯ
	int number=0;
	while (*key)
	number += (128 + *key++);
	return number;
}

inline int HashFunction(char *key) { // Hash function = modulo
	return transform(key) % TABLE_SIZE;
} 

class HashMap {
  protected:
  	Record table[TABLE_SIZE];

  public:
	HashMap(void) { reset(); }
	~HashMap(void){ }
	void reset() {
	  for ( int i=0 ; i<TABLE_SIZE ; i++ )
	    table[i].reset();
 	}

  void display( ) {
	for( int i=0 ; i<TABLE_SIZE ; i++ ) {
	  printf("[%2d] ", i); 
	  table[i].display();
 	}
  }

  void addLinearProb( char* key, char* value ) {
  int i, hashValue;

  hashValue = i = HashFunction( key ) ; // hash �ּҸ� ã�´�.
  while( table[i].isEmpty() == false ){  // empty�� ã�´�.
	if(table[i].equal( key ) ){ // Ž��Ű�� �̹� ����
	  printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key);
	  return;
  	}
    	i = (i+1) % TABLE_SIZE;
    	if(i == hashValue){  // i�� 1�� ���� �����鼭 ó�� ������ ���ƿ����� üũ
	  printf("[%s] ���̺��� ���� á���ϴ�..\n", key);
	  return;
    	}
  }
  table[i].set( key, value );  // empty ���̺� key�� value ����
}

  Record* searchLinearProb( char *key ) {
  int i, hashValue;

  hashValue = i = HashFunction( key );
  while( table[i].isEmpty() == false ){ // ���̺��� empty�� �ƴ� ���� ��� search
	if(table[i].equal( key ) ){
	  printf("[%s] Ž�� ���� [%d]", key, i);
 	  table[i].display();
	  return table+i;
	}
	i = (i+1) % TABLE_SIZE;   // index �������Ѱ��鼭 key search
	if (i == hashValue) break;// ���̺��� ó������ ���ƿ��� ����
  }
  printf("[%s] Ž�� ���� : ã�� ���� ���̺� ����\n", key);
  return NULL;
}
}; // end of class HashMap