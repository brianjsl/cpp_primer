#include "../ch11/Sales_data.hpp"

bool fcn(const Sales_data *trans, Sales_data accum) {
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
} //*trans is destroyed, accum is destroyed, item1 is destroyed, as is item2
  // so 4.(The destructor call for *trans doesn't destroy the underlying
  // object)