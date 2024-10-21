//Written by Steve Nwachukwu and Tyler Burzenski

#include "Token.hpp"

Token::Token(string name, TokenType type): name(name), type(type), refCount(1) {}

ostream& Token::print(ostream& out) const {
    cout << "Token Name: " << name << "| Type: " << type << "| Reference(s): " << refCount;
} //definition for the print function

void Token::incrementRefCounter() {
    refCount++;
}
