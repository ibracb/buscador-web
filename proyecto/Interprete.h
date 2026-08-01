// modulo Interprete//
#ifndef _INTERPRETE_
#define _INTERPRETE_
#include "DicPaginas.h"

extern DicPaginas dic;

string normalizar(string cadena);

void INSERTAR();
void BUSCAR_URL();
void BUSCAR_PALABRA();
void BUSCAR_AND();
void BUSCAR_OR();
void AUTOCOMPLETAR();
void SALIR();
void Interprete(string comando);

#endif