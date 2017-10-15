#pragma once
#include "15_18_Pub_dev.h"

class Derived_from_pub : public Pub_dev {
	int use_base() const {return prot_mem; }
	void memfnc(Base &b) const {b = *this;}

};