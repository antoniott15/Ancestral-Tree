all: expression.l engine.y
	@bison -d engine.y
	@flex expression.l
	@c++ -c main.cpp engine.tab.c lex.yy.c
	@c++ main.o engine.tab.o lex.yy.o -o main -ll
