#pragma once
#include "15_18_Priv_dev.h"

class Derived_from_priv : public Priv_dev {
	int not_use_base() const;
};