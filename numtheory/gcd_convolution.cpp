//#include "numtheory/linear_sieve.cpp"
//#include "numtheory/zeta_mobius_on_divisibility_lattice.cpp"

template<class T, int32_t C>
vector<T> gcd_convolution(linear_sieve<C> &ls, vector<T> a, vector<T> b) {
  assert(ssize(a) == ssize(b));
  a = zeta_transform_on_multiple(ls, a);
  b = zeta_transform_on_multiple(ls, b);
  for(int i = 0; i < ssize(a); i++)
    a[i] *= b[i];
  return mobius_transform_on_multiple(ls, a);
}
