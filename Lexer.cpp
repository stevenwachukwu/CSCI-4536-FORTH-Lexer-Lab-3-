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

void Lexer::doLex(){ 
    while(inputFile.get(currentChar)) {
        switch( state ){
	    case START: doStart(); break;

	    case SLASH_PENDING: 
		if( currentChar == ' ' ){
		    state = ACQUIRING_SLASH;
		}
		else{
		    state = ACQUIRING_TOKEN;
		}
		break;

	    case ACQUIRING_SLASH:
		outputFile << currentChar;
		do{
		    inputFile.get(currentChar);
		    outputFile << currentChar;		//OUTPUT TO FILE
		}while(currentChar != '\n');
		state = START;
		break;

	    case PAREN_PENDING:
		if( currentChar == ' ' ){
		    state = ACQUIRING_PAREN;
		} 
		else{
		    state = ACQUIRING_TOKEN;
		}
		break;

	    case ACQUIRING_PAREN:
		cout << "( ";
		do{
		    cout << currentChar;
		    inputFile.get(currentChar);
		} while(currentChar != ')');
		state = START;
		cout << " )\n";
		break;

	    case ACQUIRING_TOKEN:
	    {
		while(currentChar != ' ' && currentChar != '\n'){			// Token builder
		    tokenString += currentChar;
		    inputFile.get(currentChar);
		}

		if(tokenString == ".\""){		// String check
		    doToken(tokenString, WORD);		// WORD init
		    state = ACQUIRING_STRING;
		    break;
		}

		bool isNum = true;			// Num check
		for(char target : tokenString){
		    if(target < '0' || target > '9'){
			isNum = false;
			break;
		    }
		}					// Num set
		if(isNum == true){
		    doToken(tokenString, NUMBER);	// NUMBER init
		    state = START;
		    break;
		}
		else{
		    doToken(tokenString, WORD);			// Default set
		    state = START;
		    break;
		}
	    }
	    case ACQUIRING_STRING:
		
		while(currentChar != '\"'){
		    tokenString += currentChar;
		    inputFile.get(currentChar);
		}
		doToken(tokenString, STRING); 
		state = START;
		break;

	    default:
		cout << "Could not read state :("; break;
	}
    }
}

void Lexer::printTokens(){
    outputFile << "\nThe Symbol Table:\n" << endl;
    outputFile << "Token Name" << "\t\t\tType" << "\tReference(s)" << endl;
    for (const auto& pair : tokenMap) {
//	outputFile << pair.first << "\t";
        pair.second.print(outputFile);
	outputFile << "\n";
    }
}

void Lexer::doToken(string name, TokenType tt) {
    auto it = tokenMap.find(name);
    if (it != tokenMap.end()) {
        it ->second.incrementRefCounter();
    }
    else {
        Token newToken =  Token(name, tt);
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
            state = SLASH_PENDING;
            break;
         case '(':
            state = PAREN_PENDING;
	    break;
        default:
            state = ACQUIRING_TOKEN;
            tokenString += currentChar;
            break;
    }
}

