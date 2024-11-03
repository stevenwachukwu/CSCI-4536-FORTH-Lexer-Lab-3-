//Written by Steve Nwachukwu and Tyler Burzenski

#include "Token.hpp"
#include "Lexer.hpp"

Token::Token(string name, TokenType type): name(name), type(type), refCount(1) {}

ostream& Token::print(ostream& out) const {
    string typePrint;
    switch(type){		//enum translator
	case WORD:
	    typePrint = "Word";
	    break;
	case NUMBER:
	    typePrint = "Number";
	    break;
	case STRING:
	    typePrint = "String";
	    break;
	default:
	    typePrint = "Unknown";
	    break;
    }
    out << left << setw(35) << name << setw(15) << typePrint << setw(10) << refCount; 
    typePrint = "";
    return out;
} //definition for the print function

void Token::incrementRefCounter() {
    refCount++;
}
