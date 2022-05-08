/*
* Creado por: Agustin Casas y Fernanda Cattaneo
* 22.08 EDA Level 5
* 10/05/2022
* Main. Archivo principal
*/
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

	getGenoma("C:/Users/catta/Documents/EDA/Eda_Level5/textoPrueba.txt", genoma1);

	getGenoma("C:/Users/catta/Documents/EDA/Eda_Level5/txtP.txt", genoma2);

	string gen1Final;
	string gen2Final;
	string middleFinal;

	int coincidenciaFinal = useAlgoritm(genoma1, genoma2, gen1Final, gen2Final, middleFinal);
	cout << "Coincidencia: " << coincidenciaFinal << endl;

	string gen1Current;
	string gen2Current;
	string middleCurrent;
	int coincidenciaCurrent = 0;
	int numGenoma = 2;

	getGenoma(argv[1], genoma1);
	for (int i = 2; i < 8; i++) {
		getGenoma(argv[i], genoma2);
		coincidenciaCurrent = useAlgoritm(genoma1, genoma2, gen1Current, gen2Current, middleCurrent);
		if (coincidenciaCurrent > coincidenciaFinal) {
			gen1Final = gen1Current;
			gen2Final = gen2Current;
			middleFinal = middleCurrent;
			coincidenciaFinal = coincidenciaCurrent;
			numGenoma = i;

		}
	}
	printStrings(gen1Final, gen2Final, middleFinal);
	cout << "GENOMA MAS PARECIDO: " << argv[numGenoma];

	return 0;
}
