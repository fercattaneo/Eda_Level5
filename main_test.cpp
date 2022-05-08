#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "logic.h"
#include "text.h"
using namespace std;


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


/*int main2(int argc, char * argv[]) {
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }


    return 0;
}*/

int main() {
    /*Test 1. Guardado de string
    * Modificando el archivo de texto pasado se prueban distintos casos limites.  
    *
    */ 
    cout << "Testeando el guardado de Strings..." << endl;
    string value;
   
    
    getGenoma("C:/Users/Agustin/source/repos/Eda_Level5/textoPrueba.txt", value);
    cout << "GENOMA EXTRAIDO FINAL: " << value << endl;
    string realvalue = "acgacgacgagcagcagcaa";
    int eq = 1;
    for (int i = 0; (i < realvalue.size()) && eq == 1; i++) {
        if (realvalue[i] != value[i])
            eq = 0;
    }
    if(eq){
         pass();
    }
    else{
         fail();
    }

    // Test 2. Valor de coincidencia
    string genoma1 = "gattaca";
    string genoma2 = "cgatacg";
    int coincidencia = useAlgoritm (genoma1, genoma2);
    if (coincidencia == 2){
        pass();     
    }
    else{
        fail();
    }

    //Test 3. verificar el valor de cada casilla del camino optimo
    
    return 0;
}