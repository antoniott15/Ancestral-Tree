

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum{
    mother,
    father
}relationship;
typedef struct Parents
{
  relationship typeOf;
  int countGen;
  char entity;
}Parentesc;



