#include <string>
#include <vector>
#include "logic.h"
#include <iostream>

using namespace std;

int useAlgoritm(string& genoma1, string& genoma2) {
	//la matriz sera de m+1 x n+1 ; con m = size del genoma1, n= size del genoma2
	vector < vector <casilla_t> > matrix;
	matrix[0].push_back({ 0,{0,0,0,0} });
}

	//Otra forma de hacerlo
	casilla_t* mat2 = new casilla_t[(genoma1.size() + 1) * (genoma2.size() + 1)];

	for (int i = 1; i < genoma1.size()+1; i++)
	{
		matrix[0].push_back({ -i,{0,0,0,0} });
	}
	for (int i = 1; i < genoma1.size() + 1; i++)
	{
		matrix[i].push_back({ -i,{0,0,0,0} });
	}
	//cout << matrix;
	return 0;
}

void printAllignment (casilla_t *lastElement){

}