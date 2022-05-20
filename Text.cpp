/*
 * Creado por: Agustin Casas y Fernanda Cattaneo
 * 22.08 EDA Level 5
 * 10/05/2022
 * En este archivo se encuentra la función que se encarga de leer e interpretar el
 * archivo con los genomas a analizar.
 */
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "text.h"
//#define FILE_PRINT

#include <filesystem>

using namespace std;

// Funcion que se encarga de leer el archivo que se le pasa y guardar los genomas en un string
void getGenoma(char *file, string &genoma)
{
	ifstream fileIn1(file);
	string linea;
	size_t found = string::npos;
	long int geneNumber = 0;

#ifdef DEBUG
	if (fileIn1.is_open())
	{
		cout << "Open!!!\n";
	}
	else
	{
		cout << "noup\n";
	}
#endif

	// la evaluacion es lazy asi que en el caso que se encuentre ORIGIN, no se evalua el siguiente getline
	while ((found == string::npos) && (getline(fileIn1, linea)))
	{
		found = linea.find("ORIGIN");
	}
	// si el archivo contiente ORIGIN...
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
					break;
				default:
					break;
				}
			}
			// se lee un maximo de 6 strings. Si hay menos strings se deja de leer

		} while ((getline(fileIn1, linea)) && (found == string::npos));
	}
}

/*Funcion que invierte los string. Se utiliza dado que la matriz se recorre desde
el ultimo elemento al primer elemento*/
void invertString(string& originalString)
{
	string invertedString;
	for (int i = originalString.size() - 1; i >= 0; i--)
	{
		invertedString += originalString[i];
	}
	originalString = invertedString;
}

/*Funcion que se utiliza para imprimir los string respetando que no sean mas
de 60 acaracteres por linea*/
void printStrings(string& gen1result, string& gen2result, string& middlestr)
{
	ofstream fileout("output.txt");
	for (int x = 0; x < gen1result.size(); x += 59)
	{
		cout << gen1result.substr(x, 60) << endl;
		cout << middlestr.substr(x, 60) << endl;
		cout << gen2result.substr(x, 60) << endl;

#ifdef FILE_PRINT
		//Para impresion de genomas en archivos
		fileout << gen1result.substr(x, 60) << endl;
		fileout << middlestr.substr(x, 60) << endl;
		fileout << gen2result.substr(x, 60) << endl;
#endif // FILE_PRINT

	}
}