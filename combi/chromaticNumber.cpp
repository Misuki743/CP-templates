//#include "modint/dynamicMontgomeryModInt.cpp"
//#include "numtheory/fastFactorize.cpp"

template<> uint32_t MontgomeryModInt<123>::mod = 0;
template<> uint32_t MontgomeryModInt<123>::n2 = 0;
template<> uint32_t MontgomeryModInt<123>::r = 0;
int chromatic_number(vector<vector<bool>> g) {
  const int n = ssize(g);

  mt19937 rng(clock);
  uniform_int_distribution<int> unif(1 << 29, 1 << 30);
  int p = 4;
  while(!isPrime(p)) p = unif(rng);
  using Mint = MontgomeryModInt<123>;
  Mint::set_mod(p);

  vector<Mint> I(1 << n);
  I[0] = 1;
  for(unsigned msk = 1; msk < (1 << n); msk++) {
    int v = countr_zero(bit_floor(msk));
    I[msk] = I[msk ^ (1 << v)];
    unsigned msk2 = msk ^ (1 << v);
    for(int x = 0; x < n; x++)
      if (g[v][x] and (msk2 >> x & 1))
        msk2 ^= 1 << x;
    I[msk] += I[msk2];
  }

  auto check = [&](int c) {
    if (c == n) return true;
    Mint cnt = 0;
    for(unsigned msk = 0; msk < (1 << n); msk++)
      cnt += I[msk].pow(c) * (popcount(msk ^ ((1 << n) - 1)) % 2 == 1 ? -1 : 1);
    return cnt != 0;
  };

  int c = 1;
  while(!check(c)) c++;

  return c;
}
