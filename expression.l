%{
#include <stdio.h>
#include "estructure.hpp"
#include "y.tab.h"
void show_error();
%}


%%
"mother"    {return MOTHER;}
"Mother"    {return MOTHER;}
"Father"    {return FATHER;}
"father"    {return FATHER;}
"grand"     {return GRAND;}
"Grand"     {return GRAND;}
"Great"     {return GREAT;}
"great"     {return GREAT;}
"The"       {return THE;}
"the"       {return THE;}
"of"        {return OF;}
"Of"        {return OF;}
"Mary"      {return MARY;}
"mary"      {return MARY;}
"Jhon"      {return JHON;}
"jhon"      {return JHON;}
\n 			{return LINE;}
[ \t]       {};
.           {show_error(); return (ERROR);}
%%


void show_error(){
    printf("No match \n");
}