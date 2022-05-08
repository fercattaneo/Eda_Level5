#include <string>
#include "logic.h"
#include <vector>
#include <iostream>
using namespace std;

int useAlgoritm (string &genoma1, string &genoma2){
	int row = genoma1.size();
	int col = genoma2.size();
	//la matriz sera de m+1 x n+1 ; con m = size del genoma1, n= size del genoma2
	vector < vector <casilla_t> > matrix;
	matrix[0].push_back({ 0,{0,0,0,0} });
	cout << "HASTA ACA BIEN" << endl;

	for (int i = 1; i < col + 1; i++)
	{
		matrix[0].push_back({ -i,{0,0,0,0} });
	}
	for (int i = 1; i < row + 1; i++)
	{
		matrix[i].push_back({ -i,{0,0,0,0} });
	}

	
	int up = 0;
	int left = 0;
	int diagonal = 0;


	for (int i= 0; i<row+1; i++)
	{
		for (int j=0; j<col+1; j++)
		{
			if(genoma1[i]==genoma2[j]){
				diagonal = matrix[i-1][j-1].value + MATCH;
			}
			else {
				diagonal = matrix[i-1][j-1].value + SUST;
			}
			up = matrix[i-1][j].value + INDEL;
			left = matrix[i][j-1].value + INDEL;

			if (diagonal >= up && diagonal >= left){
				if (diagonal == up && diagonal == left){
					matrix[i][j].camino = {1,1,1};
				}
				else if (diagonal == up){
					matrix[i][j].camino = {1,1,0};
				}
				else if (diagonal == left){
					matrix[i][j].camino = {0,1,1};
				}
				else {
					matrix[i][j].camino = {0,1,0};
				}
			}
			else if (up > diagonal && up >= left){
				if (up == left){
					matrix[i][j].camino = {1,0,1};
				}
				else{
					matrix[i][j].camino = {1,0,0};
				}
			}
			else{
				matrix[i][j].camino = {0,0,1};
			}
		}
	}

	string gen1result;
	string gen2result;
	string middlestr;

	//Funcion que imprime
	int i = row + 1;
	int j = col + 1;
	while(i!=0 && j!=0){
			if (matrix[i][j].camino.arriba){
				gen1result += genoma1[i--];
				gen2result += "-";
				middlestr += " ";
			}
			else if (matrix[i][j].camino.diagonal){
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
			else if (matrix[i][j].camino.izquierda){
				gen1result += '-';
				gen2result += genoma2[j--];
				middlestr += " ";
			}
		}

	//cout << matrix;
	return matrix[row + 1][col + 1].value;
}

void printAllignment (casilla_t *lastElement){
}