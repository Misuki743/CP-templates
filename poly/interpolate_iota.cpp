template<class Mint>
Mint interpolate_iota(vc<Mint> ys, Mint x) {
  const int n = size(ys);
  binomial<Mint> bn(n);

  vc<Mint> suf(n + 1, Mint(1));
  for(int i = n - 1; i >= 0; i--)
    suf[i] = suf[i + 1] * (x - i);

  Mint ans = 0, pre = 1;
  for(int i = 0; i < n; i++) {
    ans += ys[i] * pre * suf[i + 1] * bn.faci(i) *
           bn.faci(n - 1 - i) * Mint((n - 1 - i) % 2 == 1 ? -1 : 1);
    pre *= (x - i);
  }

  return ans;
}
