class numbered {
public:
  numbered() { 
    mysn = syncount;
    ++syncount;
  }

  int mysn;

private:
  static int syncount;
}