#ifndef ESTRUCTURE
#define ESTRUCTURE


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>

using namespace std;
typedef struct Parentesc
{
    typedef enum { mother, father} relationship;
    int generation;


    
    void setGeneration(int g) {
      generation = g;
    }

    int getGeneration() {
      return generation;
    }

} parent;




#endif