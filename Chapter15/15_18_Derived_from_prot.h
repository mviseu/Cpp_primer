#pragma once
#include "15_18_Prot_dev.h"

class Derived_from_prot : public Prot_dev {
	int use_base() const {return prot_mem; }
	void memfnc(Base &b) const {b = *this;}
};