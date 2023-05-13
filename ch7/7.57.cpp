class Account {
public:
  static double rate() { return interestRate; }
  Account(double ir): interestRate(ir) {}
private:
  static constexpr int period = 30;
  static double interestRate;
  double daily_tbl[period];
}