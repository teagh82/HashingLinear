#pragma once
#include "Record.h"
#define TABLE_SIZE 13 


inline int transform(char *key) { // 문자열 키를 숫자로 변환
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

  hashValue = i = HashFunction( key ) ; // hash 주소를 찾는다.
  while( table[i].isEmpty() == false ){  // empty를 찾는다.
	if(table[i].equal( key ) ){ // 탐색키가 이미 있음
	  printf("[%s] 탐색키가 중복되었습니다.\n", key);
	  return;
  	}
    	i = (i+1) % TABLE_SIZE;
    	if(i == hashValue){  // i를 1씩 더해 나가면서 처음 값으로 돌아오는지 체크
	  printf("[%s] 테이블이 가득 찼습니다..\n", key);
	  return;
    	}
  }
  table[i].set( key, value );  // empty 테이블에 key와 value 저장
}

  Record* searchLinearProb( char *key ) {
  int i, hashValue;

  hashValue = i = HashFunction( key );
  while( table[i].isEmpty() == false ){ // 테이블이 empty가 아닌 동안 계속 search
	if(table[i].equal( key ) ){
	  printf("[%s] 탐색 성공 [%d]", key, i);
 	  table[i].display();
	  return table+i;
	}
	i = (i+1) % TABLE_SIZE;   // index 증가시켜가면서 key search
	if (i == hashValue) break;// 테이블의 처음으로 돌아오면 종료
  }
  printf("[%s] 탐색 실패 : 찾는 값이 테이블에 없음\n", key);
  return NULL;
}
}; // end of class HashMap