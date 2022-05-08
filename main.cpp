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

	string gen1result;
	string gen2result;
	string middleresult;
	int coincidencia = useAlgoritm(genoma1, genoma2, gen1result, gen2result, middleresult);
	cout << "Coincidencia: " << coincidencia << endl;




	return 0;
}
