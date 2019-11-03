#ifndef ESTRUCTURE
#define ESTRUCTURE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


typedef enum{
    mother,
    father
}relationship;
typedef struct Parents
{
  // mother/father
  relationship typeOf;
  // Count of generatations the mother of the mother
  int countGen;
  // is male o female
  char entity;
}Parentesc;



#endif