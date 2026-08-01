#include "NodoTrie.h"

NodoTrie::NodoTrie(){
	car = '\0';
	isMarca = false;
	sig = nullptr;
	ptr = nullptr;
}

NodoTrie::~NodoTrie(){
	if(sig != nullptr){
		delete sig;
	}
	if(ptr != nullptr){
		delete ptr;
	}
}

NodoTrie* NodoTrie::consulta(char letra){
	NodoTrie* aux = ptr;
	while(aux != nullptr and aux->car != letra){
		aux = aux->sig;
	}
	return aux;
}

void NodoTrie::inserta(char l){
	NodoTrie* nodoNuevo = new NodoTrie();
	nodoNuevo->car = l;
	nodoNuevo->sig = ptr;
	ptr = nodoNuevo;
}

bool NodoTrie::hayMarca(){
	return isMarca;
}

void NodoTrie::ponMarca(){
	isMarca = true;
}

void NodoTrie::ponEnLista(Pagina* pag) {
	list<Pagina*>::iterator EA = lista.begin();
	while (EA != lista.end() and ((*EA)->getRelevancia() > pag->getRelevancia()
	or ((*EA)->getRelevancia() == pag->getRelevancia() and (*EA)->getURL() < pag->getURL()))) {
		EA++;
	}
	if (EA != lista.end() and (*EA)->getRelevancia() == pag->getRelevancia()
	and (*EA)->getURL() == pag->getURL()) {
		(*EA)->setTitulo(pag->getTitulo());
	}
	else {
		lista.insert(EA, pag);
	}
}

list<Pagina*> NodoTrie::getLista(){
	return lista;
}