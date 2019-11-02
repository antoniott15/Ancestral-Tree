#include <iostream>
#include "estructure.h"
using namespace std;


int yyerror(char *s){
    cout << "Syntax error " << s << endl;
    return 0;
}

Parentesc *mo(){
    Parentesc *node = new Parentesc();
    node->countGen = 1;
    node->typeOf = mother;
    return node;
}


Parentesc *PreMo(){
    Parentesc *node = new Parentesc();
    node->countGen = 0;
    node->entity = 'M';
    return node;
}

Parentesc *PreFa(){
    Parentesc *node= new Parentesc();
    node->countGen = 0;
    node->entity = 'F';
    return node;
}

Parentesc *fa(){
    Parentesc *node= new Parentesc();
    node->countGen = 1;
    node->typeOf = father;
    return node;
}

Parentesc *countingGenerations(Parentesc *node){
    node->countGen++;
    return node;
}

Parentesc *g(Parentesc *node,relationship parent ){
    node->countGen++;
    node->typeOf = parent;
    return node;
}
relationship getParent(Parentesc *node){
    return node->typeOf;
}

inline char* checkTypes(Parentesc *node,char* value1,char* value2){
    char* s = node->typeOf == mother ? value1 : value2;
    return s;
}

void solution(Parentesc *node){
    if(node->countGen == 2){
    cout << "gross"<< checkTypes(node, "mutter","vatter");
        return;
    }
   if(node->countGen >= 3){
       while(node->countGen-1>1){
           cout << "ur";
           node->countGen--;
       }
            cout << "gross" << checkTypes(node, "mutter","vatter");
       return;
   }
   cout << checkTypes(node, "mutter","vatter");
}

void globalResult(Parentesc *node){
    if(node->countGen >= 2){
        cout << checkTypes(node, "Eine ", "Ein ");
    }else{
        cout << checkTypes(node, "Die ", "Dier ");
    }
    solution(node);

    cout << " von ";

    string entity = node->entity == 'M' ? "Maria" : "Jhonn";
    cout << entity;
}


