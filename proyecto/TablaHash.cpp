#include "TablaHash.h"

TablaHash::TablaHash(){
	B = 1009;
	T = new list<Pagina>[B];
	nElem = 0;
}

TablaHash::~TablaHash(){
	delete[] T;
}

int TablaHash::getHash(string url){
	unsigned int suma = 0;
	for(char caracter: url){
		suma += (int)caracter * (int)caracter;
	}
	return suma % B;
}

void TablaHash::insertar(Pagina nueva){
	int indiceInsercion = getHash(nueva.getURL());
	list<Pagina>::iterator EA;
	EA = T[indiceInsercion].begin();
	while (EA != T[indiceInsercion].end() and (*EA).getURL() < nueva.getURL()) {
		EA++;
	}
	if (EA != T[indiceInsercion].end() and (*EA).getURL() == nueva.getURL()) {
		(*EA).setTitulo(nueva.getTitulo());
		(*EA).setRelevancia(nueva.getRelevancia());
	}
	else {
		T[indiceInsercion].insert(EA, nueva);
		nElem++;
	}
}

Pagina* TablaHash::consultar(string url){
	int indiceConsulta = getHash(url);
	list<Pagina>::iterator EA;
	EA = T[indiceConsulta].begin();
	while(EA != T[indiceConsulta].end()){
		if((*EA).getURL() == url){
			return &(*EA);
		}
		EA++;
	}
	return nullptr;
}

int TablaHash::numElem(void){
	return nElem;
}