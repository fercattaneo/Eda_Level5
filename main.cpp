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

	string gen1result;
	string gen2result;
	string middleresult;

	int coincidencia = useAlgoritm(genoma1, genoma2, gen1result, gen2result, middleresult);
	cout << "Coincidencia: " << coincidencia << endl;




	return 0;
}
