%{
#include <stdio.h>
#include "estructure.h"
#include "engine.tab.h"
void showError();
%}

//Defining the entitys
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
.           {showError(); return (ERROR);}
%%

// Controling errors
void showError(){
    printf("No match \n");
}