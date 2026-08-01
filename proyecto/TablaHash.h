// modulo TablaHash //
#ifndef _TABLA_HASH_
#define _TABLA_HASH_
#include "Pagina.h"
#include <list>

class TablaHash{
	private:
		list<Pagina> *T;
		int B;
		int nElem;
	public:
		TablaHash();
		~TablaHash();
		void insertar(Pagina nueva);
		Pagina* consultar(string url);
		int numElem (void);
		int getHash(string url);
};
#endif