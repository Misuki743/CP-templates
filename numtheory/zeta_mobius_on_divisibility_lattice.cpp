//#include "numtheory/linear_sieve"

template<class T, int32_t C>
vector<T> zeta_transform_on_divisor(linear_sieve<C> &ls, vector<T> f) {
  assert(ssize(f) <= C);
  for(int64_t p : ls.prime) {
    if (p >= ssize(f)) break;
    for(int i = 1; i * p < ssize(f); i++)
      f[i * p] += f[i];
  }
  return f;
}

template<class T, int32_t C>
vector<T> mobius_transform_on_divisor(linear_sieve<C> &ls, vector<T> f) {
  assert(ssize(f) <= C);
  for(int64_t p : ls.prime) {
    if (p >= ssize(f)) break;
    for(int i = (ssize(f) - 1) / p; i > 0; i--)
      f[i * p] -= f[i];
  }
  return f;
}

template<class T, int32_t C>
vector<T> zeta_transform_on_multiple(linear_sieve<C> &ls, vector<T> f) {
  assert(ssize(f) <= C);
  for(int64_t p : ls.prime) {
    if (p >= ssize(f)) break;
    for(int i = (ssize(f) - 1) / p; i > 0; i--)
      f[i] += f[i * p];
  }
  return f;
}

template<class T, int32_t C>
vector<T> mobius_transform_on_multiple(linear_sieve<C> &ls, vector<T> f) {
  assert(ssize(f) <= C);
  for(int64_t p : ls.prime) {
    if (p >= ssize(f)) break;
    for(int i = 1; i * p < ssize(f); i++)
      f[i] -= f[i * p];
  }
  return f;
}
