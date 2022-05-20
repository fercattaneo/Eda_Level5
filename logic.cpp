/*
 * Creado por: Agustin Casas y Fernanda Cattaneo
 * 22.08 EDA Level 5
 * 10/05/2022
 * En este archivo se encuentran las funciones que tienen que ver con el
 * funcionamiento del algoritmo de Needleman-Wunsch y la impresion de los
 * genomas enlazados.
 */

#include <string>
#include <iostream>
#include <fstream>
#include "logic.h"
#include "text.h"
#include <vector>
#include <new>
using namespace std;

/*Funcion que se encarga de realizar la matriz del algoritmo needlman-
y de guardar como quedan enlazados los genomas*/
int useAlgoritm(string &genoma1, string &genoma2, string &gen1result, string &gen2result, string &middlestr)
{
	int row = genoma1.size() + 1;
	int col = genoma2.size() + 1;
	casilla_t *matrix = new casilla_t[row * col];

	matrix[0] = {0, {0, 0, 0, 0}};

	// Se cargan los elementos de la fila 1 columna 0 y fila 0 columna 1
	for (int i = 1; i < col; i++)
	{
		matrix[i] = {-i, {0, 0, 1, 0}};
	}
	cout << endl;
	for (int i = 1; i < row; i++)
	{
		matrix[i * col] = {-i, {1, 0, 0, 0}};
	}

	int up = 0;
	int left = 0;
	int diagonal = 0;

	/*Este bucle arranca en 1 dado que las primeras posiciones ya están colocadas
	y se analiza desde la celda (1,1)*/
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (genoma1[i - 1] == genoma2[j - 1])
			{ /*Se resta uno en ambos casos dado que arranca
contando desde 1 pero esa celda coincide con el 0 del string */
				diagonal = matrix[(i - 1) * col + (j - 1)].value + MATCH;
			}
			else
			{
				diagonal = matrix[(i - 1) * col + (j - 1)].value + SUST;
			}
			up = matrix[(i - 1) * col + j].value + INDEL;
			left = matrix[i * col + (j - 1)].value + INDEL;

			// Se analiza desde qué direccion el resultado es más alto
			if (diagonal >= up && diagonal >= left)
			{

				matrix[i * col + j].value = diagonal;

				if (diagonal == up && diagonal == left)
				{
					matrix[i * col + j].camino = {1, 1, 1, 0};
				}
				else if (diagonal == up)
				{
					matrix[i * col + j].camino = {1, 1, 0, 0};
				}
				else if (diagonal == left)
				{
					matrix[i * col + j].camino = {0, 1, 1, 0};
				}
				else
				{
					matrix[i * col + j].camino = {0, 1, 0, 0};
				}
			}
			else if (up > diagonal && up >= left)
			{

				matrix[i * col + j].value = up;

				if (up == left)
				{
					matrix[i * col + j].camino = {1, 0, 1, 0};
				}
				else
				{
					matrix[i * col + j].camino = {1, 0, 0, 0};
				}
			}
			else
			{
				matrix[i * col + j].value = left;
				matrix[i * col + j].camino = {0, 0, 1, 0};
			}
		}
	}

#ifdef DEBUG
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i * col + j].value << '\t';
		}
		cout << endl;
	}
#endif

	// Se guada como se enlanzan los genomas y se muestra en pantalla
	int i = row - 1;
	int j = col - 1;
	while (j >= 0 && i >= 0)
	{
		if (matrix[i * col + j].camino.arriba)
		{
			gen1result += genoma1[--i];
			gen2result += "-";
			middlestr += " ";
		}
		else if (matrix[i * col + j].camino.diagonal)
		{
			gen1result += genoma1[i - 1];
			gen2result += genoma2[j - 1];
			if (genoma1[i - 1] == genoma2[j - 1])
			{
				middlestr += '|';
			}
			else
			{
				middlestr += '*';
			}
			i--;
			j--;
		}
		else if (matrix[i * col + j].camino.izquierda)
		{
			gen1result += '-';
			gen2result += genoma2[--j]; // No se si es -- o ++. Porque estamos yendo de atras hacia adelante
			middlestr += " ";
		}
		if (i == 0 && j == 0)
			break;
	}

	invertString(gen1result);
	invertString(gen2result);
	invertString(middlestr);

	// Se muestra en pantalla
	printStrings(gen1result, gen2result, middlestr);
	int coincidenciafinal= matrix[row * col - 1].value;
	delete[] matrix;
	return coincidenciafinal;
}

