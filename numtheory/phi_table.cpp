template<class T, int32_t C>
array<T, C> phi_table(linear_sieve<C> &ls) {
  array<T, C> phi = {};
  if (C > 1) phi[1] = T(1);
  auto &mpf = ls.mpf;
  for(int i = 2; i < C; i++)
    phi[i] = phi[i / mpf[i]] * (mpf[i] == mpf[i / mpf[i]] ? mpf[i] : T(mpf[i] - 1));
  return phi;
}
