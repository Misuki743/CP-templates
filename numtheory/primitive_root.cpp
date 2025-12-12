//#include "numtheory/fastFactorize.cpp"

ull primitiveRoot(ull p) {
  auto fac = factor(p - 1);
  ranges::sort(fac);
  fac.resize(unique(fac.begin(), fac.end()) - fac.begin());
  auto test = [p, fac](ull x) {
    for(ull d : fac)
      if (modpow(x, (p - 1) / d, p) == 1)
        return false;
    return true;
  };
  static mt19937_64 rng(clock);
  uniform_int_distribution<ull> unif(1, p - 1);
  ull root;
  while(!test(root = unif(rng)));
  return root;
}
