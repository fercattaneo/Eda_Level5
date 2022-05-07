#include <string>
using namespace std;
#ifndef LOGIC_H
#define LOGIC_H

typedef struct {
	char arriba : 1;
	char diagonal : 1;
	char izquierda : 1;
	char unused : 5;
}caminos_t;
typedef struct {
	int valor;
	caminos_t camino;
}casilla_t;

void printAllignment(casilla_t* lastElement);
int useAlgoritm(string& genoma1, string& genoma2);

#endif // !LOGIC_H
