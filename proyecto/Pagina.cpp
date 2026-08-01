#include "Pagina.h"

string Pagina::getURL(){
	return url;
}

string Pagina::getTitulo(){
	return titulo;
}

int Pagina::getRelevancia(){
	return relevancia;
}

void Pagina::setTitulo(string titulo){
	this->titulo = titulo;
}

void Pagina::setRelevancia(int relevancia){
	this->relevancia = relevancia;
}

void Pagina::leer(){
	cin>>relevancia;
	cin.ignore();
	getline(cin,url);
	getline(cin,titulo);
}

void Pagina::escribir(){
	cout<<url<<", "<<titulo<<", "<<"Rel. "<<relevancia<<endl;
}