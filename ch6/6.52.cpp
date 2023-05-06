void manip(int, int);
double dobj;

int main() {
  manip('a', 'z');   // 3 -> promotion
  manip(55.4, dobj); // 4 -> arithmetic conversion
}