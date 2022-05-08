#include <string>
#include <iostream>
#include "logic.h"
#include <vector>
#include <new>
using namespace std;

int useAlgoritm (string &genoma1, string &genoma2){
	cout << "ENTRA A USE ALGORITHM" << endl;
	int row = genoma1.size() + 1;
	int col = genoma2.size() + 1;
	//la matriz sera de m+1 x n+1 ; con m = size del genoma1, n= size del genoma2
	casilla_t* matrix = new casilla_t[row * col];
	cout << "RESERVA MEMORIA" << endl;
	matrix[0] = { 0,{0,0,0,0} };
	cout << matrix[0].value;

	for (int i = 1; i < col; i++)
	{
		matrix[i] = { -i,{0,0,0,0} };
		cout << matrix[i].value << " ";
	}
	cout << endl;
	for (int i = 1; i < row; i++)
	{
		matrix[i*col] = { -i,{0,0,0,0} };
		cout << matrix[i * col].value << endl;
	}


	cout << "HARDCODEO TERMINADO" << endl;
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
					matrix[i*col + j].camino = {1,1,1};
				}
				else if (diagonal == up){
					matrix[i* col + j].camino = {1,1,0};
				}
				else if (diagonal == left){
					matrix[i* col + j].camino = {0,1,1};
				}
				else {
					matrix[i* col + j].camino = {0,1,0};
				}
			}
			else if (up > diagonal && up >= left){

				matrix[i* col + j].value = up;

				if (up == left){
					matrix[i * col + j].camino = {1,0,1};
				}
				else{
					matrix[i * col + j].camino = {1,0,0};
				}
			}
			else{
				matrix[i* col + j].value = left;
				matrix[i* col + j].camino = {0,0,1};
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i * col + j].value<< '\t';
		}
		cout << endl;
	}
	string gen1result;
	string gen2result;
	string middlestr;

	//Funcion que imprime
	int i = row-1;
	int j = col-1;
	while( j!=0 && i!=0){
			if (matrix[i* col + j].camino.arriba){
				gen1result += genoma1[i--];
				gen2result += "-";
				middlestr += " ";
			}
			else if (matrix[i* col + j].camino.diagonal){
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
			else if (matrix[i* col + j].camino.izquierda){
				gen1result += '-';
				gen2result += genoma2[j--]; //No se si es -- o ++. Porque estamos yendo de atras hacia adelante
				middlestr += " ";
			}
		}

	cout << gen1result << endl;
	cout << middlestr << endl;
	cout << gen2result << endl;

	return matrix[row * col -1].value;
	delete[] matrix;
}

void printAllignment (casilla_t *lastElement){
}