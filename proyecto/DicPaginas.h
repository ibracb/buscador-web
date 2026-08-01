// modulo DicPaginas //
#ifndef _DIC_PAGINAS_
#define _DIC_PAGINAS_
#include "TablaHash.h"
#include "ArbolTrie.h"

class DicPaginas {
	private:
		TablaHash tabla;
		ArbolTrie arbol;
	public:
		void insertar(Pagina nueva);
		Pagina* consultar(string url);
		int numElem(void);
		void insertar(string palabra, Pagina *pag);
		list<Pagina*> buscar(string palabra);
};
#endif