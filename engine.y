%{
    #include "main.cpp"

	//HERE COMES THE METHODS OR UTIL FUNCTIONS
    int yylex();
    int yyerror(char *s);
     Parentesc *mo();
     Parentesc *PreMo();
     Parentesc *PreFa();
     Parentesc *fa();
     Parentesc *countingGenerations( Parentesc *node);
     Parentesc *g( Parentesc *node, char parent );
     char getParent( Parentesc *node);
	inline char* checkTypes(Parentesc *node,char* value1,char* value2);
    void solution( Parentesc *node);
    void globalResult( Parentesc *node);
%}



//INSTANCE OF PARENT 
%union{
     Parentesc *node;
}

//DEFINING TOKENS
%token MOTHER FATHER GRAND GREAT THE OF MARY JHON LINE ERROR

//statements statement parent repeatOneStatementTOken RepeatOneToken TheNameOfEntity
%type <node> stmts stmt parent repeatToken repeatOne name




//DEFINING GRAMATIC
%%
program:
        function                	    { exit(0); }
        ;
function:
	| function stmt LINE 			    {solution($2); printf("\n");}
	| function stmts LINE				{globalResult($2);}
	;

stmts:
	THE parent OF name 			        {$$ = g($4, getParent($2));}
	| THE parent OF repeatToken		    {$$ = g($4, getParent($2));}
	;
stmt:
	parent							    {$$ = $1;}
	| GRAND parent					    {$$ = countingGenerations($2);}
	| GREAT repeatOne 					{$$ = countingGenerations($2);}
	;	
repeatToken:
	THE parent OF name 			        {$$ = g($4, getParent($2));}
	| THE parent OF repeatToken 		{$$ = g($4, getParent($2));}
	;
repeatOne:
	GREAT repeatOne						{$$ = countingGenerations($2);}
	| GRAND parent					    {$$ = countingGenerations($2);}
	;
name:
	JHON							    {$$ = PreFa();}
	| MARY							    {$$ = PreMo();}
	;
parent:
	MOTHER 							    {$$ = mo();}
	| FATHER 						    {$$ = fa();}
	;

%%


int main(){
    yyparse();
    return 0;
}