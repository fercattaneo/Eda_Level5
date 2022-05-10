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

	getGenoma("C:/Users/catta/Documents/EDA/Eda_Level5/5. DNATool - Datasets/resources/reference/Alpha B.1.1.7 - MZ314997.txt", genoma1);

	getGenoma("C:/Users/catta/Documents/EDA/Eda_Level5/5. DNATool - Datasets/resources/test/Mystery genome 3 - OU772970.txt", genoma2);

	string gen1Final;
	string gen2Final;
	string middleFinal;

	int coincidencia = useAlgoritm(genoma1, genoma2, gen1Final, gen2Final, middleFinal);
	

	printStrings(gen1Final, gen2Final, middleFinal);
	cout << endl << "COINCIDENCIA ENTRE GENOMAS: " << coincidencia << endl;

	return 0;
}
