class NoDefault {
public:
  NoDefault(int);
};

class C {
public:
  C() : nd(NoDefault(0)) {}

private:
  NoDefault nd;
};