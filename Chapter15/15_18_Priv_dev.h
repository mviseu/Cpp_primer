#pragma once
#include "15_18_Base.h"

class Priv_dev : private Base {
private:
	int f1() const {return prot_mem;}
	//void memfnc(Base &b) const {b = *this;}
};
