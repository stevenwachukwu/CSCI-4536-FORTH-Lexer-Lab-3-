//Written by Steve Nwachukwu and Tyler Burzenski

#include "Lexer.hpp"

Lexer::Lexer(string inputFileName) : state(START), currentChar(' '), tokenString("") {
    inputFile.open(inputFileName);
    if (!inputFile) throw "Sorry but your input file can't be opened!";

    outputFile.open(inputFileName + ".output");
    if (!outputFile) throw "Sorry but your output file can't be opened!";

    outputFile << "Steve Nwachukwu and Tyler Burzenski" << endl;
    outputFile << "Lab 3: FORTH Lexer" << endl;
    outputFile << "The lexed file: " << inputFileName << '\n' << endl;
    outputFile << "------------------------------------" << endl;
    outputFile << "Comments: " << '\n' << endl;
}

Lexer::~Lexer(){
    inputFile.close();
    outputFile.close();
}

Lexer::doLex(){} //Tyler's part

void Lexer::printTokens(){
    outputFile << "The Symbol Table:\n";
    for (const auto& pair : tokenMap) {
        pair.second.print(outputFile);
    }
}

void Lexer::doToken(string name, TokenType tt) {
    auto it = tokenMap.find(name);
    if (it != tokenMap.end()) {
        it ->second.incrementRefCounter();
    }
    else {
        Token newToken(name, tt);
        tokenMap[name] = newToken;
    }
    tokenString = ""; //resets the token string after processing
} //helper function for doToken

void Lexer::doStart() {
switch (currentChar) {
    case ' ':
    case '\t':
    case '\n':
     //case statements deal with spacing, newlines, and tabs
        break;
    case '\\':
        type = SLASH_PENDING;
        break;
    case '(':
        type = PAREN_PENDING;
    default:
        type = ACQUIRING_TOKEN;
        tokenString += currentChar;
        break;
    }
}
