#include <iostream>
#include "estructure.hpp"
using namespace std;


int yyerror(char *s){
    cout << "Syntax error " << s << endl;
    return 0;
}

Parentesc *mo(){
    Parentesc *node;
    node->countGen = 1;
    node->typeOf = mother;
    return node;
}


Parentesc *PreMo(){
    Parentesc *node;
    node->countGen = 0;
    node->typeOf = mother;
    return node;
}

Parentesc *PreFa(){
    Parentesc *node;
    node->countGen = 0;
    node->typeOf = father;
    return node;
}

Parentesc *fa(){
    Parentesc *node;
    node->countGen = 1;
    node->typeOf = father;
    return node;
}
//g
Parentesc *countingGenerations(Parentesc *node){
    node->countGen++;
    return node;
}
//G
Parentesc *g(Parentesc *node,relationship parent ){
    node->countGen++;
    node->typeOf = parent;
    return node;
}
relationship getParent(Parentesc *node){
    return node->typeOf;
}

inline string checkTypes(Parentesc *node,string value1,string value2){
    string s = node->typeOf == mother ? value1 : value2;
    return s;
}

void solution(Parentesc *node){
    if(node->countGen == 2){
    cout << "gross"<< checkTypes(node, "mutter","vatter");
        return;
    }
   if(node->countGen >= 3){
       while(node->countGen>1){
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
        cout << checkTypes(node, "Die ", "Dier ");
    }else{
        cout << checkTypes(node, "Eine ", "Ein ");
    }
    solution(node);

    cout << " von ";

    cout << checkTypes(node, "María","Johann");
}
