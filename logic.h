#include <string>
using namespace std;
#ifndef LOGIC_H
#define LOGIC_H

#define MATCH 1
#define SUST -1
#define INDEL -1

typedef struct {
	char arriba : 1;
	char diagonal : 1;
	char izquierda : 1;
	char unused : 5;
}caminos_t;
typedef struct {
	int value;
	caminos_t camino;
}casilla_t;

void printAllignment(casilla_t* lastElement);
int useAlgoritm(string& genoma1, string& genoma2);

#endif // !LOGIC_H
