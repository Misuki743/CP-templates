//#include "modint/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"
//#include "combi/binom.cpp"

template<class Mint>
FPS<Mint> stirling_number_second(int n) {
  binomial<Mint> bn(n + 1);
  FPS<Mint> f(n + 1), g(n + 1);
  for(int i = 0; i <= n; i++) {
    f[i] = bn.faci(i) * (i % 2 == 1 ? -1 : 1);
    g[i] = bn.faci(i) * mint(i).pow(n);
  }
  auto h = f * g;
  h.resize(n + 1);
  return h;
}
