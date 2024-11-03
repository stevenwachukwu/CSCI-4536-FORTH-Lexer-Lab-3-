//Written by Steve Nwachukwu and Tyler Burzenski

#pragma once
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Types.hpp"

using namespace std;

class Token {
private:
    string name;
    TokenType type;
    int refCount; //initialized to be 1 later

public:
  Token() = default;
  Token(string name, TokenType type);
  ostream& print(ostream& out) const;
  void incrementRefCounter();
};


#endif
