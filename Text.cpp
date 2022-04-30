#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


string getGenoma(char* file, string& genoma) {
	ifstream fileIn1(file);
	string linea;
	size_t found = string::npos;
	long int geneNumber = 0;

	//la evaluacion es lazy asi que en el caso que se encuentre ORIGIN, no se evalua el siguiente getline
	while ((found == string::npos) && (getline(fileIn1, linea)))
	{
		found = linea.find("ORIGIN");
	}
	//si el archivo contiente ORIGIN...
	if (found != string::npos)
	{
		found = string::npos;

		//busco el numero 1 para empezar a llenar el genoma
		while ((found == string::npos) && (getline(fileIn1, linea)))
		{
			found = linea.find("1");
		}

		found = string::npos;

		/*
		*leo 6 strings y los almaceno en genoma. Paro cuando encuentro la doble barra o 
		* se termina el archivo
		*/
		do
		{
			found = linea.find("//");

			istringstream iss(linea);
			iss >> geneNumber;
			cout << "Numero de caracter inicial: " << geneNumber << endl;

			int i = 0;
			string palabraAux;

			//leo un maximo de 6 strings. Si hay menos strings paro de leer
			while ((i < 6) && (iss >> palabraAux))
			{
				cout << "String Agregado al genoma: " << palabraAux;
				genoma += palabraAux;
			}

		} while (getline(fileIn1, linea) && (found == string::npos));
	}
}