#include "Token.h"

Token& Token::operator=(const Token& t) {
	#ifdef VERBOSE
		std::cout << "operator=(const Token& t)" << std::endl;
	#endif
	if(tok == STR && t.tok != STR) {
		using std::string;
		sval.~string();
	}
	if(tok == SD && t.tok != SD) {
		sdval.~Sales_data();
	}
	if(tok == STR && t.tok == STR) {
		sval = t.sval;
	} else {
		if(tok == SD && t.tok == SD) {
			sdval = t.sdval;
		} else {
			CopyUnion(t);			
		}
	}
	tok = t.tok;
	return *this;
}

Token& Token::operator=(Token&& t) {
	#ifdef VERBOSE
		std::cout << "operator=(Token&&)" << std::endl;
	#endif
	if(tok == STR && t.tok != STR) {
		using std::string;
		sval.~string();
	}
	if(tok == SD && t.tok != SD) {
		sdval.~Sales_data();
	}
	if(tok == STR && t.tok == STR) {
		sval = std::move(t.sval);
	} else {
		if(tok == SD && t.tok == SD) {
			sdval = std::move(t.sdval);
		} else {
			MoveUnion(std::move(t));			
		}
	}
	tok = t.tok;
	return *this;
}

Token& Token::operator=(char c) {
	#ifdef VERBOSE
		std::cout << "operator=(char c)" << std::endl;
	#endif
	DestroyIfTokStr();
	DestroyIfTokSd();
	tok = CHAR;
	cval = c;
	return *this;
}

Token& Token::operator=(int i) {
	#ifdef VERBOSE
		std::cout << "operator=(int i)" << std::endl;
	#endif
	DestroyIfTokStr();
	DestroyIfTokSd();
	tok = INT;
	ival = i;
	return *this;
}

Token& Token::operator=(double d) {
	#ifdef VERBOSE
		std::cout << "operator=(double d)" << std::endl;
	#endif
	DestroyIfTokStr();
	DestroyIfTokSd();
	tok = DBL;
	dval = d;
	return *this;
}

Token& Token::operator=(const std::string& s) {
	#ifdef VERBOSE
		std::cout << "operator=(string s)" << std::endl;
	#endif
	DestroyIfTokSd();
	if(tok == STR) {
		sval = s;
	} else {
		new(&sval) std::string(s);
		tok = STR;
	}
	return *this;	
}

Token& Token::operator=(const Sales_data &sd) {
	#ifdef VERBOSE
		std::cout << "operator=(const Sales_data &sd)" << std::endl;
	#endif
	DestroyIfTokStr();
	if(tok == SD) {
		sdval = sd;
	} else {
		new(&sdval) Sales_data(sd);
		tok = SD;
	}
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
			new(&sdval) Sales_data(t.sdval);
			break;
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
			new(&sdval) Sales_data(std::move(t.sdval));
	}
}

void Token::DestroyIfTokStr() {
	if(tok == STR) {
		using std::string;
		sval.~string();
	}	
}

void Token::DestroyIfTokSd() {
	if(tok == SD) {
		sdval.~Sales_data();
	}
}