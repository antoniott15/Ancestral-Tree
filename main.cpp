#include <iostream>
#include "estructure.h"
using namespace std;


// Control error
int yyerror(char *s){
    cout << "Syntax error " << s << endl;
    return 0;
}

// Instance of is a MOTHER
Parentesc *mo(){
    Parentesc *node = new Parentesc();
    node->countGen = 1;
    node->typeOf = mother;
    return node;
}

// Instance of is MARY OR JHON MARY=M
Parentesc *PreMo(){
    Parentesc *node = new Parentesc();
    node->countGen = 0;
    node->entity = 'M';
    return node;
}

// Instance of Jhonn JHON = F
Parentesc *PreFa(){
    Parentesc *node= new Parentesc();
    node->countGen = 0;
    node->entity = 'F';
    return node;
}

// Instance of is a Father
Parentesc *fa(){
    Parentesc *node= new Parentesc();
    node->countGen = 1;
    node->typeOf = father;
    return node;
}

// Counting times of Mother of mother of mother
Parentesc *countingGenerations(Parentesc *node){
    node->countGen++;
    return node;
}

//Setting the type of parent mother/father 
Parentesc *g(Parentesc *node,relationship parent ){
    node->countGen++;
    node->typeOf = parent;
    return node;
}
// Getting the type of the parent
relationship getParent(Parentesc *node){
    return node->typeOf;
}

// Helping to print the type of the Parent
inline char* checkTypes(Parentesc *node,char* value1,char* value2){
    char* s = node->typeOf == mother ? value1 : value2;
    return s;
}

// Setting and printin the mother of the mother
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

// Final util function to give the answer
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


