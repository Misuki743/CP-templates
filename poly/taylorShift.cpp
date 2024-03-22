//#include "modint/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"

template<class Mint>
FPS<Mint> taylorShift(FPS<Mint> f, Mint c) {
  int n = ssize(f);
  binomial<Mint> bn(n);
  FPS<Mint> a = f;
  for(int i = 0; i < n; i++)
    a[i] *= bn.fac(i);
  FPS<Mint> b(n);
  Mint pre = 1;
  for(int i = 0; i < n; i++, pre *= c)
    b[i] = pre * bn.faci(i);
  ranges::reverse(b);
  f = a * b;
  f.erase(f.begin(), f.begin() + n - 1);
  for(int i = 0; i < n; i++)
    f[i] *= bn.faci(i);
  return f;
}
