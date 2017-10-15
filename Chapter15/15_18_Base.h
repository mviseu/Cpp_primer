#pragma once
#include <iostream>

class Base {
public:
	void pub_mem() {std::cout << "Public member" << std::endl;}
protected:
	int prot_mem = 0;
private:
	int priv_mem = 0;
};