#include "base.h"
void main1518() {
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd1;
	Derived_from_Protected dd1;

	Base* p = &d1; //Legal, d1 is publicly derived and can be dynamically binded to a pointer to the base class type
	p = &d2; //Illegal, d2 is privately derived so it can't be dynamically binded to base class
	p = &d3; //Illegal, same as above (since protected).
	p = &dd1; //legal, dd1 is still publicly derived from Pub_derv and thus d2
	p = &dd2; //Illegal, derived publicly but from a private class so base class members inaccessible
	p = &dd3; //Illegal, same as above excepted protected.
}