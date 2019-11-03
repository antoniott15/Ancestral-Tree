%{
#include <stdio.h>
#include "estructure.h"
#include "engine.tab.h"
void showError();
%}


%%
"mother"|"Mother"   {return MOTHER;}  
"Father"|"father"   {return FATHER;}
"grand"|"Grand"     {return GRAND;}
"Great"|"great"     {return GREAT;}
"The"|"the"         {return THE;}
"of"|"Of"           {return OF;}
"Mary"|"mary"       {return MARY;}
"John"|"john"       {return JOHN;}
\n 			        {return LINE;}
[ \t]               {};
.                   {showError(); return (ERROR);}
%%

// Controling errors
void showError(){
    printf("No match \n");
}