/*
 * Creado por: Agustin Casas y Fernanda Cattaneo
 * 22.08 EDA Level 5
 * 10/05/2022
 * Main. Archivo principal. Al colocar dos arcivos este programa
 * devuelve como queda la secuencia con los respectivos enlases
 * y el valor de coincidencia de dicha union.
 */
#include <fstream>
#include <string>
#include <sstream>
#include "text.h"
#include <iostream>
#include "logic.h"
using namespace std;

int main()
{

	string genoma1;
	string genoma2;

	getGenoma("C:/Users/catta/Documents/EDA/Eda_Level5/5. DNATool - Datasets/resources/reference/Alpha B.1.1.7 - MZ314997.txt", genoma1);

	getGenoma("C:/Users/catta/Documents/EDA/Eda_Level5/5. DNATool - Datasets/resources/test/Mystery genome 3 - OU772970.txt", genoma2);

	string gen1result;
	string gen2result;
	string middleresult;

	int coincidencia = useAlgoritm(genoma1, genoma2, gen1result, gen2result, middleresult);
	cout << "Coincidencia: " << coincidencia << endl;

	return 0;
}

/*Otra forma de hacer el main utilizando json para no colocar los path a mano es la siguiente:

int main (char argc, char* argv[]){
	string genoma1;
	string genoma2;

	getGenoma(argv[1], genoma1);

	getGenoma(argv[2], genoma2);

	string gen1result;
	string gen2result;
	string middleresult;

	int coincidencia = useAlgoritm(genoma1, genoma2, gen1result, gen2result, middleresult);
	cout << "Coincidencia: " << coincidencia << endl;

}
*/