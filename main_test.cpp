/*
 * Creado por: Agustin Casas y Fernanda Cattaneo
 * 22.08 EDA Level 5
 * 10/05/2022
 * En este archivo se encuentran las pruebas realizadas para analizar
 * la funcionalidad del código y de las diferentes funciones que se crearon.
 */
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

int main(void)
{
    /*Test 1. Guardado de string
     * Modificando el archivo de texto pasado se prueban distintos casos limites.
     */
    cout << "Testeando el guardado de Strings..." << endl;
    string value;

    getGenoma("C:/Users/Agustin/source/repos/Eda_Level5/textoPrueba.txt", value);

    cout << "GENOMA EXTRAIDO FINAL: " << value << endl;
    string realvalue = "acgacgacgagcagcagcaa";
    int eq = 1;
    for (int i = 0; (i < realvalue.size()) && eq == 1; i++)
    {
        if (realvalue[i] != value[i])
            eq = 0;
    }
    if (eq)
    {
        pass();
    }
    else
    {
        fail();
    }
    /*Test 1.b Guardado de string
   * Modificando el archivo de texto pasado se prueban distintos casos limites.
   *
   */
    cout << "Testeando el guardado de Strings con archivo vacio..." << endl;

    value = "";
    getGenoma("C:/Users/Agustin/source/repos/Eda_Level5/emptyFileTest.txt", value);

    cout << "GENOMA EXTRAIDO FINAL: " << value << endl;
    realvalue = "";
    eq = (value == realvalue);
    if (eq) {
        pass();
    }
    else {
        fail();
    }


    // Test 2. Valor de coincidencia

    string genoma1 = "attgcgtattg";
    string genoma2 = "cattgattag";
    string gen1result;
    string gen2result;
    string middleresult;
    int coincidencia = useAlgoritm(genoma1, genoma2, gen1result, gen2result, middleresult);
    if (coincidencia == 3)
    {
        pass();
    }
    else
    {
        fail();
    }

    // Test 3. verificar que las uniones entre los genomas sean las correctas
    string gen1 = "gattaca";
    string gen2 = "cgatacg";
    string result1;
    string middle;
    string result2;
    useAlgoritm(gen1, gen2, result1, result2, middle);
    if (middle == " ||| ||*")
    {
        pass();
    }
    else
    {
        fail();
    }

    return 0;
}