#include <algorithm>

int main() {
  replace(beg, end, old_val,
          new_val); // Replaces all elements in the original container with
                    // value old_val to new_val
  replace_if(beg, end, pred,
             new_val); // Same as above, except replaces all values that return
                       // true under the predicate pred
  replace_copy(beg, end, dest, old_val,
               new_val); // Same as 1 except copies the elements into a new
                         // container dest
  replace_copy_if(beg, end, dest, pred,
                  new_val); // Same as above except replaces all values that
                            // return true under the predicate pred
  return 0;
}