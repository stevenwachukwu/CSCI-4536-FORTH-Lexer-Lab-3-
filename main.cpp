#include <iostream>
#include "Lexer.hpp"
using namespace std;

//USE: ./main inputFile.f
int main(int argc, char* argv[]) {
    try{
	if(argv[1]){
		string inFileName = argv[1];
		Lexer lexer(inFileName);
		lexer.doLex();
		lexer.printTokens();
	}else{
		cout << "Error: Input file argument not provided." << endl;
	}
    }
    catch(const char* e){
	cerr << "\nCaught exception: " << e << "\n";
    }
    return 0;

}
