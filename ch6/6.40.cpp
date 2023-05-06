// Legal
int ff(int a, int b = 0, int c = 0);

// Error: The default initialized values must go at the end
char *init(int hd = 35, int wd, char bckgrnd);