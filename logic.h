#include <string>
using namespace std;
#ifndef LOGIC_H
#define LOGIC_H
typedef struct {
	int valor;
	char camino;
}casilla_t;

void printAllignment(casilla_t* lastElement);
int useAlgoritm(string& genoma1, string& genoma2);

#endif // !LOGIC_H
