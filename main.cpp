#include <fstream>
#include <string>

using namespace std;
int main(char argc, char* argv[]) {

	ifstream fileIn1(argv[1]);
	string linea, genoma1, genoma2;
	size_t found= string::npos;
	long int geneNumber = 0;
	while((getline(fileIn1, linea)) && (found==string::npos)) 
	{
		found = linea.find("ORIGIN");

    }
	if (found != string::npos) {
		while()
	}
	//busco el numero
	//leo 6 strings y los almaceno en genoma1
	//l
	genoma1 += genoma1 tiraADN
	return 0;
}

/*
		TESTS:

-Verificacion del archivo
-Verificacion del guardado de strings
-Verificacion del valor de coincidencia
-Verificacion del resultado(dos genomas alineados)

*/