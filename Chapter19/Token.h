#pragma once
#include "19_21_Sales_data.h"
#include <string>
#include <iostream>

class Token {
public:
Token() : tok(INT), ival{0} {
	#ifdef VERBOSE
		std::cout << "Token()" << std::endl;
	#endif
}
Token(const Token& t) : tok(t.tok) {
	#ifdef VERBOSE
		std::cout << "Token(const Token& t)" << std::endl;
	#endif
	CopyUnion(t);
}
Token(Token&& t) : tok(t.tok) {
	#ifdef VERBOSE
		std::cout << "Token(Token&&)" << std::endl;
	#endif
	MoveUnion(std::move(t));
}
Token& operator=(const Token& t);
Token& operator=(Token&& t);
Token& operator=(char c);
Token& operator=(int i);
Token& operator=(double d);
Token& operator=(const std::string& s);
Token& operator=(const Sales_data& sd);
~Token() {
	DestroyIfTokStr();
	DestroyIfTokSd();
}


private:
enum {CHAR, INT, DBL, STR, SD} tok;
union {
	char cval;
	int ival;
	double dval;
	std::string sval;
	Sales_data sdval;
};
void CopyUnion(const Token& t);
void MoveUnion(Token&& t);
void DestroyIfTokStr();
void DestroyIfTokSd();

};