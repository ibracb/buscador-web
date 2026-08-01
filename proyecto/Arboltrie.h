// modulo ArbolTrie //
#ifndef _ARBOL_TRIE_
#define _ARBOL_TRIE_
#include "NodoTrie.h"

class ArbolTrie{
	private:
		NodoTrie *raiz;
		int nElem;
	public:
		ArbolTrie();
		~ArbolTrie();
		void insertar(string palabra, Pagina *pag);
		list<Pagina*> buscar(string palabra);
		int numElem(void);
};
#endif