#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "logic.h"
#include "text.h"
using namespace std;
/*
-HAY QUE PONER EL .JSON EN EL CMAKE
*/


int fail()
{
    cout << "FAIL" << endl;
    return 1;
}

int pass()
{
    cout << "PASS" << endl;
    return 0;
}


int main (int argc, char * argv[]) {
    /*Test 1. Guardado de string
    * Modificando el archivo de texto pasado se prueban distintos casos limites.  
    *
    */ 
    cout << "Testeando el guardado de Strings..." << endl;
        string value;
        getGenoma("textoPrueba.txt", value);
        if(value == "acgacgacgagcagcagcaa"){
            pass();
        }
        else{
            fail();
        }
    }

    //Test 2. Valor de coincidencia
    string genoma1 = "gattaca";
    string genoma2 = "cgatacg";
    int value = useAlgoritm (string &genoma1, string &genoma2){
        if (value == 2){
            pass();
        }
        else{
            fail();
        }
    }

    //Test 3. verificar el valor de cada casilla del camino optimo

}