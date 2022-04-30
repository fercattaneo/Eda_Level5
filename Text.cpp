#include <fstream>
#include <string>
#include <sstream>

using namespace std;


string getGenoma(char* file) {
	ifstream fileIn1(file);
	string linea, genoma1, genoma2;
	size_t found = string::npos;
	long int geneNumber = 0;
	while ((getline(fileIn1, linea)) && (found == string::npos))
	{
		found = linea.find("ORIGIN");

	}
	//si el archivo contiente ORIGIN...
	if (found != string::npos)
	{
		//busco el numero 1 para empezar a llenar el genoma
		found = string::npos;

		while ((getline(fileIn1, linea)) && (found == string::npos))
		{
			found = linea.find("1");

		}
		do
		{

		} while
	}
	//busco el numero
	//leo 6 strings y los almaceno en genoma1
	//l
	genoma1 += tiraADN;
}