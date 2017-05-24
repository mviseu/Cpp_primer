#pragma once

class NoDefault {
public:
	NoDefault(int i) {}
};

class C {
public:
	//C cannot use the synthesized default constructor since its data member is not using the default constructor.
	//default constructor has to explicitly initialize X.
	C() : X(0) {}

private:
	NoDefault X;
};