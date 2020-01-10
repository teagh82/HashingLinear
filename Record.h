#pragma once
#include <stdio.h>
#include <string.h>
#define KEY_SIZE 64 
#define VALUE_SIZE 64

class Record {
  	char key[KEY_SIZE];
  	char value[VALUE_SIZE];

  public:
	Record( char *k="", char*d="" ) { set(k, d); }
	~Record() {}
	void set ( char *k, char* v="" ) {
	  strcpy(key, k);
	  strcpy(value, v);
	}
	void reset() { set("", ""); }
	char* getKey() { return key; }
	char* getValue() { return value; }
	void setKey(char *k) { strcpy(key, k); }
	bool isEmpty() { return key[0] == '\0'; }
	bool equal( char *k) { return strcmp(k, key)==0; }
	void display( ) { printf("%20s = %s\n", key, value); }
};