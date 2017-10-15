#pragma once
#include "15_18_Base.h"

class Prot_dev : protected Base {
private:
	int f2() const {return prot_mem;}
	//void memfnc(Base &b) const {b = *this;}
};
