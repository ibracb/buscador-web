#include "ArbolTrie.h"

ArbolTrie::ArbolTrie(){
	nElem = 0;
	raiz = new NodoTrie();
}

ArbolTrie::~ArbolTrie(){
	delete raiz;
}

void ArbolTrie::insertar(string palabra, Pagina *pag){
	NodoTrie* nodoActual = raiz;
	for (char caracter : palabra) {
		NodoTrie* nodoSiguiente = nodoActual->consulta(caracter);
		if (nodoSiguiente == nullptr) {
			nodoActual->inserta(caracter);
			nodoSiguiente = nodoActual->consulta(caracter);
		}
		nodoActual = nodoSiguiente;
	}
	if (not nodoActual->hayMarca()) {
		nodoActual->ponMarca();
	}
	nodoActual->ponEnLista(pag);
	nElem++;
}

list<Pagina*> ArbolTrie::buscar(string palabra){
	NodoTrie* nodoActual = raiz;
	for (char caracter : palabra) {
		nodoActual = nodoActual->consulta(caracter);
		if (nodoActual == nullptr) {
			return {};
		}
	}
	if (nodoActual->hayMarca()) {
		return nodoActual->getLista();
	}
	return {};
}

int ArbolTrie::numElem(){
	return nElem;
}