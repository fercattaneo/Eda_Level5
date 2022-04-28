#include <fstream>
#include <string>

using namespace std;
int main(char argc, char* argv[]) {

	ifstream fileIn1(argv[1]);
	string linea, genoma1, genoma2;
	do(getline(fileIn1, linea)){
		while(!linea.find("ORIGIN"))
    }
	return 0;
}