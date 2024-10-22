//Written by Steve Nwachukwu and Tyler Burzenski

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Types.hpp"
#include "Token.hpp"

using namespace std;

class Lexer {
private:
    StateType type;
    ifstream inputFile;
    ofstream outputFile;
    map<string, Token> tokenMap;
    char currentChar;
    string tokenString;
    TokenType currentToken;

public:
     Lexer(string inputFileName); //lexer constructor
     ~Lexer(); //lexer destructor
     doLex();
     void printTokens(); //function used to print tokenMap contents
     void doToken(string name, TokenType tt); //helper function for token identifier
     void doStart(); //helper function to help with the state switching

    StateType state;
};


#endif
