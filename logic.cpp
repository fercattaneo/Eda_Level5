#include <string>
using namespace std;
#include "logic.h"
#include <vector>
#include <new>

int useAlgoritm (string &genoma1, string &genoma2){
	int row = genoma1.size() + 1;
	int col = genoma2.size() + 1;
	//la matriz sera de m+1 x n+1 ; con m = size del genoma1, n= size del genoma2
	casilla_t* matrix = new casilla_t[row * col];
	matrix[0] = { 0,{0,0,0,0} };

	for (int i = 1; i < col; i++)
	{
		matrix[i*col] = { -i,{0,0,0,0} };
	}
	for (int i = 1; i < row; i++)
	{
		matrix[i*row] = { -i,{0,0,0,0} };
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
				diagonal = matrix[(i-1)*row + (j-1)*col].value + MATCH;
			}
			else {
				diagonal = matrix[(i-1)*row + (j-1)*col].value + SUST;
			}
			up = matrix[(i-1)*row + j*col].value + INDEL;
			left = matrix[i*row + (j-1)*col].value + INDEL;

			if (diagonal >= up && diagonal >= left){

				matrix[i+row + j*col].value = diagonal;

				if (diagonal == up && diagonal == left){
					matrix[i+row + j*col].camino = {1,1,1};
				}
				else if (diagonal == up){
					matrix[i+row + j*col].camino = {1,1,0};
				}
				else if (diagonal == left){
					matrix[i+row + j*col].camino = {0,1,1};
				}
				else {
					matrix[i+row + j*col].camino = {0,1,0};
				}
			}
			else if (up > diagonal && up >= left){

				matrix[i+row + j*col].value = up;

				if (up == left){
					matrix[i+row + j*col].camino = {1,0,1};
				}
				else{
					matrix[i+row + j*col].camino = {1,0,0};
				}
			}
			else{
				matrix[i+row + j*col].value = left;
				matrix[i+row + j*col].camino = {0,0,1};
			}
		}
	}

	string gen1result;
	string gen2result;
	string middlestr;

	//Funcion que imprime
	int i = row;
	int j = col;
	while(i!=0 && j!=0){
			if (matrix[i+row + j*col].camino.arriba){
				gen1result += genoma1[i--];
				gen2result += "-";
				middlestr += " ";
			}
			else if (matrix[i+row + j*col].camino.diagonal){
				gen1result += genoma1[i--];
				gen2result += genoma2[j--];
				if (genoma1[i]==genoma2[j]){
					middlestr += '|';
				}
				else{
					middlestr += '*';
				}
				i--;
				j--;
			}
			else if (matrix[i+row + j*col].camino.izquierda){
				gen1result += '-';
				gen2result += genoma2[j--]; //No se si es -- o ++. Porque estamos yendo de atras hacia adelante
				middlestr += " ";
			}
		}

	//cout << matrix;
	return matrix[row + col].value;
}

void printAllignment (casilla_t *lastElement){
}