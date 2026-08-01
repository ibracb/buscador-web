// modulo NodoTrie //
#ifndef _NODO_TRIE_
#define _NODO_TRIE_
#include "Pagina.h"
#include <list>

class NodoTrie{
	private:
		char car;
		NodoTrie *sig, *ptr;
		list<Pagina*> lista;
		bool isMarca;
	public:
		NodoTrie();
		~NodoTrie();
		NodoTrie* consulta(char letra);
		void inserta(char l);
		bool hayMarca();
		void ponMarca();
		void ponEnLista(Pagina* pag);
		list<Pagina*> getLista();
};
#endif