#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "text.h"

using namespace std;


void getGenoma(char* file, string& genoma) {
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

		do
		{
			found = linea.find("//");
			char addedChar;
			for (int i = 0; i < linea.size(); i++) 
			{
				addedChar = linea[i];
				
				switch (addedChar)
				{
				case 'a':
				case 'c':
				case 'g':
				case 't':
					genoma += addedChar;
					cout << "Caracter Agregado al genoma: " << addedChar;
					break;
				default:
					cout << "Caracter Invalido no agregado: " << addedChar;
					break;
				}
			}
			//leo un maximo de 6 strings. Si hay menos strings paro de leer

		} while ((getline(fileIn1, linea)) && (found == string::npos));
	}
}