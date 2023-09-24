class Base { };

//a)
class Derived: public Derived {}; //Illegal, can't derive a class from itself

//b)
class Derived : private Base {}; //Legal

//c)
class Derived : public Base; //Illegal, derivation list can't appear in a declaration.


