#include "DicPaginas.h"

void DicPaginas::insertar(Pagina nueva){
	tabla.insertar(nueva);
}

Pagina* DicPaginas::consultar(string url){
	return tabla.consultar(url);
}

int DicPaginas::numElem(){
	return tabla.numElem();
}

void DicPaginas::insertar(string palabra, Pagina *pag){
	arbol.insertar(palabra, pag);
}

list<Pagina*> DicPaginas::buscar(string palabra){
	return arbol.buscar(palabra);
}