// header.h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void putd(int d);
size_t getlnlen(char* line);
void reverse(char str[]);

// Prints a signed integer to stdout
void putd(int d) {
  printf("%d\n", d);
}

// Returns the length of a line of characters
size_t getlnlen(char* line) {
  size_t i;
  for (i = 0; line[i] != '\n' && line[i] != '\0'; i++);
  return i;
}

// Reverses a string in place
void reverse(char str[]) {
  size_t len = getlnlen(str);
  for (size_t i = 0, j = len - 1; (i < (len / 2)) && (j >= (len / 2)); i++, j--) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}
