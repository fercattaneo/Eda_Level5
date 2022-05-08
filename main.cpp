#include <fstream>
#include <string>
#include <sstream>
#include "text.h"
#include <iostream>
#include "logic.h"
using namespace std;

int main(char argc, char* argv[]) {

	string genoma1;
	string genoma2;

	getGenoma("C:/Users/Agustin/source/repos/Eda_Level5/textoPrueba.txt", genoma1);
	//cout << "GENOMA EXTRAIDO FINAL 1: " << genoma1 << endl;

	getGenoma("C:/Users/Agustin/source/repos/Eda_Level5/textoPrueba.txt", genoma2);
	//cout << "GENOMA EXTRAIDO FINAL 2: " << genoma2 << endl;


	int coincidencia = useAlgoritm(genoma1, genoma2);
	cout << "Coincidencia: " << coincidencia << endl;



	return 0;
}

/*
		FUNCIONES MAIN:
- Funcion que guarda el string de todo el genoma
- Funcion de la matriz que devuelve coiencidencia.Tambien imprime el ADN
/*
		TESTS:

-Verificacion del archivo (X)
-Verificacion del guardado de strings. Recibe un archivo con 2 cadenas (de 10) y verifica que imprima bien
-Verificacion del valor de coincidencia. /La funcion de la matriz devuelve el valor de coincidencia
-Verificacion del resultado(dos genomas alineados). Ver que lo que se imprime llamando a la matriz es correcto
-HAY QUE PONER EL .JSON EN EL CMAKE
*/