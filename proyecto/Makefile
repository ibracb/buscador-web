a.out: Pagina.o TablaHash.o NodoTrie.o ArbolTrie.o DicPaginas.o Interprete.o Main.o
	g++ Pagina.o TablaHash.o NodoTrie.o ArbolTrie.o DicPaginas.o Interprete.o Main.o

Pagina.o: Pagina.cpp Pagina.h
	g++ -c Pagina.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Pagina.h
	g++ -c TablaHash.cpp

NodoTrie.o: NodoTrie.cpp NodoTrie.h Pagina.h
	g++ -c NodoTrie.cpp

ArbolTrie.o: ArbolTrie.cpp ArbolTrie.h NodoTrie.h
	g++ -c ArbolTrie.cpp

DicPaginas.o: DicPaginas.cpp DicPaginas.h TablaHash.h ArbolTrie.h
	g++ -c DicPaginas.cpp

Interprete.o: Interprete.cpp Interprete.h DicPaginas.h
	g++ -c Interprete.cpp

Main.o: Main.cpp Interprete.h
	g++ -c Main.cpp

clean:
	rm -f *.o a.out a.exe
