#include "15_18_Base.h"
#include "15_18_Pub_dev.h"
#include "15_18_Priv_dev.h"
#include "15_18_Prot_dev.h"
#include "15_18_Derived_from_pub.h"
#include "15_18_Derived_from_priv.h"
#include "15_18_Derived_from_prot.h"

int main() {
	Pub_dev d1;
	Priv_dev d2;
	Prot_dev d3;
	Derived_from_pub dd4;
	Derived_from_priv dd5;
	Derived_from_prot dd6;
  	Base * p = &d1;
  	//p = &d2;
  	//p = &d3;
  	p = &dd4;
   	//p = &dd5;

   	//p = &dd6;

	return 0;
}
