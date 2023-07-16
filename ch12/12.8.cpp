bool b() {
  int *p = new int;
  return p; /*This is an error since when we
            return p we are actually returning
            a converted copy (where the value is
            true if p is not nullptr). The actual
            object at p is never freed. */
}