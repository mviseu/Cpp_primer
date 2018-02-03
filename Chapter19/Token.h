#pragma once
#include "19_21_Sales_data.h"
#include <string>

class Token {
public:
Token() : tok(INT), ival{0} {}
Token(const Token& t) : tok(t.tok) {CopyUnion(t);}
Token(Token&& t) : tok(t.tok) {MoveUnion(std::move(t));}
Token& operator=(const Token& t);
Token& operator=(Token&& t);
Token& operator=(char c);
Token& operator=(int i);
Token& operator=(double d);
Token& operator=(const std::string& s);
Token& operator=(const Sales_data& sd);
~Token() {
	DestroyIfTokStr();
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

};