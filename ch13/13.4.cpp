class Point {};

Point global;

Point foo_bar(Point arg) { // Copy initialization of the parameter
  Point local = arg,
        *heap = new Point(global); // copy initialization of both local and the
                                   // element inside heap
  *heap = local;
  Point pa[4] = {local,
                 *heap}; // copy initialization of the array (memberwise copy)
  return *heap;          // copy initialization of the return value
}