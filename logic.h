#include <string>
using namespace std;
#ifndef LOGIC_H
#define LOGIC_H

#define MATCH 1
#define SUST -1
#define INDEL -1

typedef struct {
	unsigned char arriba : 1;
	unsigned char diagonal : 1;
	unsigned char izquierda : 1;
	unsigned char unused : 5;
}caminos_t;
typedef struct {
	int value;
	caminos_t camino;
}casilla_t;


int useAlgoritm(string& genoma1, string& genoma2, string&  gen1result, string& gen2result, string& middlestr);
void invertString(string& originalString);
void printStrings(string& gen1result, string& gen2result, string& middlestr);
#endif // !LOGIC_H
