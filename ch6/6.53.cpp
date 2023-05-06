// Takes a reference to a const int
// Second one can accept both consts and
// non consts unlike the first
int calc(int &, int &);
int calc(const int &, const int &);

// Same as above but for pointers
int calc(char *, char *);
int calc(const char *, const char *);

// The declaration is illegal since we 
// have a top level const which is ambigous
int calc(char *, char *);
int calc(char *const, char *const);