#include "Interprete.h"

int main(void) {
	string comando;
	while(cin>>comando) {
		Interprete(comando);
	}
	return 0;
}
