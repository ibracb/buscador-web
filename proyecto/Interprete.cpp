#include "Interprete.h"

DicPaginas dic;

string normalizar(string cadena){
	string cadenaFinal;
	for (unsigned int i=0; i<cadena.length(); i++) {
		if (cadena[i]>='A' and cadena[i]<='Z') {
			cadenaFinal += (char)tolower(cadena[i]);
		}
		else if(cadena[i] == (char)0xC3) {
			switch (cadena[i + 1]) {
				case (char)0xA1: //a minuscula con tilde
					cadenaFinal += 'a';
					i++;
					break;
				case (char)0x81: //a mayuscula con tilde
					cadenaFinal += 'a';
					i++;
					break;
				case (char)0xA9: //e minuscula con tilde
					cadenaFinal += 'e';
					i++;
					break;
				case (char)0x89: //e mayuscula con tilde
					cadenaFinal += 'e';
					i++;
					break;
				case (char)0xAD: //i minuscula con tilde
					cadenaFinal += 'i';
					i++;
					break;
				case (char)0x8D: //e mayuscula con tilde
					cadenaFinal += 'i';
					i++;
					break;
				case (char)0xB3: //o minuscula con tilde
					cadenaFinal += 'o';
					i++;
					break;
				case (char)0x93: //o mayuscula con tilde
					cadenaFinal += 'o';
					i++;
					break;
				case (char)0xBA: //u minuscula con tilde
					cadenaFinal += 'u';
					i++;
					break;
				case (char)0x9A: //u mayuscula con tilde
					cadenaFinal += 'u';
					i++;
					break;
				case (char)0xBC: //u minuscula con dieresis
					cadenaFinal += 'u';
					i++;
					break;
				case (char)0x9C: //u mayuscula con dieresis
					cadenaFinal += 'u';
					i++;
					break;
				case (char)0x91: //egne mayuscula
					cadenaFinal += (char)0xC3;
					cadenaFinal += (char)0xB1;
					i++;
					break;
				default: //Si no encontramos vocales con tilde
					cadenaFinal += (char)0xC3;
					break;
			}
		}
		else {
			cadenaFinal += cadena[i]; //Resto de caracteres, los mantenemos
		}
	}
	return cadenaFinal;
}

void INSERTAR() {
	Pagina nueva;
	string palabra;
	int cont = 0;
	nueva.leer();
	Pagina* existente = dic.consultar(nueva.getURL());
	if (existente != nullptr) {
		existente->setTitulo(nueva.getTitulo());
	}
	else {
		dic.insertar(nueva);
		existente = dic.consultar(nueva.getURL());
	}
	Pagina *ref = existente;
	while (cin >> palabra and normalizar(palabra) != "findepagina") {
		dic.insertar(normalizar(palabra), ref);
		cont++;
	}
	cout << dic.numElem() << ". ";
	ref->escribir();
	cout<<cont<<" palabras"<<endl;
}

void BUSCAR_URL(){
	string url;
	cin>>url;
	int contadorPagina = 0;
	cout<<"u "<<url<<endl;
	if (dic.consultar(url)==nullptr) {
		cout<<"Total: 0 resultados"<<endl;
	}
	else {
		Pagina* pagina = dic.consultar(url);
		cout<<"1. ";
		pagina->escribir();
		cout<<"Total: 1 resultados"<<endl;
	}
}

void BUSCAR_PALABRA(){
	string palabra;
	cin>>palabra;
	int numPaginas = 0;
	list<Pagina*> paginas = dic.buscar(normalizar(palabra));
	cout<<"b "<<normalizar(palabra)<<endl;
	if (not paginas.empty()) {
		list<Pagina*>::iterator EA;
		EA = paginas.begin();
		while(EA != paginas.end()) {
			cout<<numPaginas+1<<". ";
			(*EA)->escribir();
			numPaginas++;
			EA++;
		}
		cout<<"Total: "<<numPaginas<<" resultados"<<endl;
	}
	else {
		cout<<"Total: 0 resultados"<<endl;
	}
}

void BUSCAR_AND() {
	string palabra;
	string resultado = "a";
	bool puedeSeguir = true;
	while (puedeSeguir) {
		cin >> palabra;
		resultado += " " + normalizar(palabra);
		if (cin.peek() == '\n') {
			puedeSeguir = false;
		}
	}
	cout << resultado << endl;
	cout << "Total: 0 resultados" << endl;
}

void BUSCAR_OR() {
	string palabra;
	string resultado = "o";
	bool puedeSeguir = true;
	while (puedeSeguir) {
		cin >> palabra;
		resultado += " " + normalizar(palabra);
		if (cin.peek() == '\n') {
			puedeSeguir = false;
		}
	}
	cout << resultado << endl;
	cout << "Total: 0 resultados" << endl;
}

void AUTOCOMPLETAR(){
	string prefijo;
	cin>>prefijo;
	cout<<"p "<<normalizar(prefijo)<<endl;
	cout<<"Total: 0 resultados"<<endl;
}

void SALIR() {
	cout<<"Saliendo..."<<endl;
	exit(0);
}

void Interprete(string comando) {
	if(comando=="i"){
		INSERTAR();
	}
	else if(comando=="u"){
		BUSCAR_URL();
	}
	else if(comando=="b"){
		BUSCAR_PALABRA();
	}
	else if(comando=="a"){
		BUSCAR_AND();
	}
	else if(comando=="o"){
		BUSCAR_OR();
	}
	else if(comando=="p"){
		AUTOCOMPLETAR();
	}
	else if(comando=="s"){
		SALIR();
	}
}