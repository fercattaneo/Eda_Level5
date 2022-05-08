#include <string>
#include <iostream>
#include "logic.h"
#include <vector>
#include <new>
using namespace std;

int useAlgoritm(string& genoma1, string& genoma2, string& gen1result, string& gen2result, string& middlestr) {
	cout << "ENTRA A USE ALGORITHM" << endl;
	int row = genoma1.size() + 1;
	int col = genoma2.size() + 1;
	//la matriz sera de m+1 x n+1 ; con m = size del genoma1, n= size del genoma2
	casilla_t* matrix = new casilla_t[row * col];

	matrix[0] = { 0,{0,0,0,0} };


	for (int i = 1; i < col; i++)
	{
		matrix[i] = { -i,{0,0,1,0} };
	}
	cout << endl;
	for (int i = 1; i < row; i++)
	{
		matrix[i*col] = { -i,{1,0,0,0} };
	}

	int up = 0;
	int left = 0;
	int diagonal = 0;

//Este bucle arranca en 1 dado que las primeras posiciones ya están colocadas 
//y se analiza desde la celda (1,1)
	for (int i=1; i < row; i++) 
	{
		for (int j=1; j < col; j++)
		{
			if(genoma1[i-1]==genoma2[j-1]){  /*Resto uno en ambos casos dado que arranco 
			contando desde 1 pero esa celda coincide con el 0 del string */
				diagonal = matrix[(i-1)*col + (j-1)].value + MATCH;
			}
			else {
				diagonal = matrix[(i-1)*col + (j-1)].value + SUST;
			}
			up = matrix[(i-1)*col + j].value + INDEL;
			left = matrix[i*col + (j-1)].value + INDEL;

			if (diagonal >= up && diagonal >= left){

				matrix[i*col + j].value = diagonal;

				if (diagonal == up && diagonal == left){
					matrix[i*col + j].camino = {1,1,1,0};
				}
				else if (diagonal == up){
					matrix[i* col + j].camino = {1,1,0,0};
				}
				else if (diagonal == left){
					matrix[i* col + j].camino = {0,1,1,0};
				}
				else {
					matrix[i* col + j].camino = {0,1,0,0};
				}
			}
			else if (up > diagonal && up >= left){

				matrix[i* col + j].value = up;

				if (up == left){
					matrix[i * col + j].camino = {1,0,1,0};
				}
				else{
					matrix[i * col + j].camino = {1,0,0,0};
				}
			}
			else{
				matrix[i* col + j].value = left;
				matrix[i* col + j].camino = {0,0,1,0};
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i * col + j].value<< '\t';
		}
		cout << endl;
	}


	//Funcion que imprime
	int i = row-1;
	int j = col-1;
	while( j>=0 && i>=0) {
			if (matrix[i* col + j].camino.arriba){
				gen1result += genoma1[--i];
				gen2result += "-";
				middlestr += " ";
			}
			else if (matrix[i* col + j].camino.diagonal){
				gen1result += genoma1[i-1];
				gen2result += genoma2[j-1];
				if (genoma1[i-1]==genoma2[j-1]){
					middlestr += '|';
				}
				else{
					middlestr += '*';
				}
				i--;
				j--;
			}
			else if (matrix[i* col + j].camino.izquierda){
				gen1result += '-';
				gen2result += genoma2[--j]; //No se si es -- o ++. Porque estamos yendo de atras hacia adelante
				middlestr += " ";
			}
			if (i == 0 && j == 0)
				break;
		}
	invertString(gen1result);
	invertString(gen2result);
	invertString(middlestr);
	
	printStrings(gen1result, gen2result, middlestr);

	return matrix[row * col -1].value;
	delete[] matrix;
}

void invertString (string &originalString){
	string invertedString;
	for (int i = originalString.size()-1; i >=0; i--) {
		invertedString += originalString[i];
	}
	originalString = invertedString;
}
void printStrings(string& gen1result, string& gen2result, string& middlestr) {
	//Tienen largos iguales
	for (int x = 0; x < gen1result.size(); x += 59) {
		cout << gen1result.substr(x, 60) << endl;
		cout << middlestr.substr(x, 60) << endl;
		cout << gen2result.substr(x, 60) << endl;
	}
}