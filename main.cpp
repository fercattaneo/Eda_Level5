#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(char argc, char* argv[]) {

	ifstream fileIn1(argv[1]);
	
	return 0;
}

/*
		FUNCIONES MAIN:
- Funcion que guarda el string de todo el genoma
- Funcion de la matriz que devuelve coiencidencia.Tambien imprime el ADN
/*
		TESTS:

-Verificacion del archivo (X)
-Verificacion del guardado de strings. Recibe un archivo con 2 cadenas (de 10) y verifica que imprima bien
-Verificacion del valor de coincidencia. /La funcion de la matriz devuelve el valor de coincidencia
-Verificacion del resultado(dos genomas alineados). Ver que lo que se imprime llamando a la matriz es correcto
-HAY QUE PONER EL .JSON EN EL CMAKE
*/