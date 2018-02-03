#include "Token.h"

Token& Token::operator=(const Token& t) {
	if(tok == STR && t.tok != STR) {
		using std::string;
		sval.~string();
	}
	if(tok == STR && t.tok == STR) {
		sval = t.sval;
	} else {
		CopyUnion(t);
	}
	tok = t.tok;
	return *this;
}

Token& Token::operator=(Token&& t) {
	if(tok == STR && t.tok != STR) {
		using std::string;
		sval.~string();
	}
	if(tok == STR && t.tok == STR) {
		sval = std::move(t.sval);
	} else {
		MoveUnion(std::move(t));
	}
	tok = std::move(t.tok);
	return *this;
}

Token& Token::operator=(char c) {
	DestroyIfTokStr();
	tok = CHAR;
	cval = c;
	return *this;
}

Token& Token::operator=(int i) {
	DestroyIfTokStr();
	tok = INT;
	ival = i;
	return *this;
}

Token& Token::operator=(double d) {
	DestroyIfTokStr();
	tok = DBL;
	dval = d;
	return *this;
}

Token& Token::operator=(const std::string& s) {
	if(tok == STR) {
		sval = s;
	} else {
		new(&sval) std::string(s);
		tok = STR;
	}
	return *this;	
}

Token& Token::operator=(const Sales_data &sd) {
	DestroyIfTokStr();
	tok = SD;
	sdval = sd;
	return *this;
}

void Token::CopyUnion(const Token& t) {
	switch(t.tok) {
		case CHAR: 
			cval = t.cval;
			break;
		case INT:
			ival = t.ival;
			break;
		case DBL:
			dval = t.dval;
			break;
		case STR:
			new(&sval) std::string(t.sval);
			break;
		case SD:
			sdval = t.sdval;
	}
}

void Token::MoveUnion(Token&& t) {
	switch(t.tok) {
		case CHAR: 
			cval = std::move(t.cval);
			break;
		case INT:
			ival = std::move(t.ival);
			break;
		case DBL:
			dval = std::move(t.dval);
			break;
		case STR:
			new(&sval) std::string(std::move(t.sval));
			break;
		case SD:
			sdval = std::move(t.sdval);
	}
}

void Token::DestroyIfTokStr() {
	if(tok == STR) {
		using std::string;
		sval.~string();
	}	
}