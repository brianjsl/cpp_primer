#include <iostream>

//Illegal since the second is a high level
//const which is indistinguishable from the
//One without const
int calc(int, int);
int calc(const int, const int);

//Illegal since simply having different return
//type still makes the function indistinguishable
int get();
double get();

//Legal.
int *reset(int *);
double *reset(double *);