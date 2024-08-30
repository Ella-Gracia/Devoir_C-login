#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void choice();
void getdata(char** name, char** pwd);
void save_file(FILE* f, char* name, char* pwd);
void compare(char* name, char* pwd);
