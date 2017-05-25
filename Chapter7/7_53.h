#pragma once
//literal class
//at least one constexpr constructors
//data members all off literal type
//if data members are in-class initialized then initializer must be constexpr
//literal class members must be initialized by constexpr constructors
//class must use default definition for destructor

class Debug {

public:

	constexpr Debug(bool b) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
	constexpr bool any() const {return hw || io || other;}
	//cannot constexpr since *this is modified
	void set_hw(bool b) {hw = b;}
	void set_io(bool b) {io = b;}
	void set_other(bool b) {other = b;}

private:
	//all data members are literals
	bool hw;
	bool io;
	bool other;
};