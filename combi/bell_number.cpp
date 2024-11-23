//#include "modint/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"
//#include "combi/binom.cpp"

template<class Mint>
FPS<Mint> bell_number(int n) {
  binomial<Mint> bn(n);
  FPS<Mint> f(n);
  for(int i = 1; i < n; i++) f[i] = bn.faci(i);
  f = f.exp(n);
  for(int i = 0; i < n; i++) f[i] *= bn.fac(i);
  return f;
}
