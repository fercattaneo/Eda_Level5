# Eda_Level5
*El programa funciona al invocarlo con los dos archivos por linea de comando. Sin embargo el .json
no nos funcionaba por lo que para probarlo y correrlo tuvimos que hardcodear los paths. 
Para los tests hicimos lo mismo.Ademas, los archivos de texto los modificamos para probar distintos casos
limites. Enviamos una sola de las versiones de los mismos.

* En el archivo logic.cpp se encuentra la funcion referidas a 
la logica del programa, es decir el uso del algoritmo de e Needleman-Wunsch.

* En el archivo Text.cpp se encuentran las funciones que se encargan del texto:
-Abrir el archivo que se le pasa por linea de comando y guardar la información
necesaria para realizar el algoritmo.
-Dar vuelta los strings
-Impresion en consola y con compilacion condicional para archivos

* El archivo resultados.txt contiene los resultados de comparar los 3 genomas
desconocidos con los respectivos 7 archivos de coparación que teníamos.

*En los archivos Mystery imprimimos los genomas que mas coincidian para cada genoma misterioso, respetando
dicho numero
