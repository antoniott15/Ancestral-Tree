%{
#include <stdio.h>
#include <estructure.hpp>

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
[\d\W]      {error(); return ERROR;}
%%


void error(){
    printf("No match \n");
}