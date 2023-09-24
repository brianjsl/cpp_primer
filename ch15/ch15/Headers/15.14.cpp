#include "base.h"

void main1514() {
	base bobj;
	derived dobj;

	base* bp1 = &bobj;
	base* bp2 = &dobj;

	base& br1 = bobj;
	base& br2 = dobj;

	bobj.print(); //base class print
	dobj.print(); //uses the derived class print

	bp1->name(); //Uses the base class name
	bp2->name(); //Uses the base class print (not a virtual function)
	
	br1.print(); //Uses the base class print
	br2.print(); //Uses the derived class print (virtual function and reference variable used)
}