#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

char tolower(char s1);
bool is_digit(char c);
int strlen(const char* ptr);
int strnlen(const char* ptr, int max);
int tonumericdigit(char c);
int strnlen_terminator(const char* str, int max, char terminator);
int strncmp(const char* str1, const char* str2, int n);
int istrncmp(const char* s1, const char* s2, int n);
char* strcpy(char* dest, const char* src); 

#endif