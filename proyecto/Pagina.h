// modulo Pagina //
#ifndef _PAGINA_
#define _PAGINA_
#include <iostream>
#include <string>

using namespace std;

class Pagina{
	private:
		int relevancia;
		string titulo;
		string url;
	public:
		string getURL();
		string getTitulo();
		int getRelevancia();
		void setTitulo(string titulo);
		void setRelevancia(int relevancia);
		void leer();
		void escribir();
};
#endif