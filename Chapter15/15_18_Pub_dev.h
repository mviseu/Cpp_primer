#pragma once
#include "15_18_Base.h"

class Pub_dev : public Base {
private:
	int f() const {return prot_mem;}
	//void memfnc(Base &b) const {b = *this;}
};
