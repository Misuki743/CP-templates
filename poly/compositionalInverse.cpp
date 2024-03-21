//#include "modint/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"
//#include "poly/kthTermOfPowers.cpp"

template<class Mint>
FPS<Mint> compositionalInverse(FPS<Mint> f, int k) {
  assert(ssize(f) >= 2 and f[0] == 0 and f[1] != 0);
  mint c = f[1];
  mint invc = 1 / c;
  for(mint &x : f)
    x *= invc;
  k -= 1;
  f = kthTermOfPowers(k, k + 1, f);
  for(int i = 1; i <= k; i++)
    f[i] *= mint(k) / i;
  ranges::reverse(f);
  f = f.log(k + 1);
  mint inv = 1 / mint(-k);
  for(mint &x : f) x *= inv;
  f = f.exp(k + 1);
  f.insert(f.begin(), Mint(0));
  f.pop_back();
  for(mint buf = 1; mint &x : f)
    x *= buf, buf *= invc;
  return f;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps f(n);
  for(mint &x : f)
    cin >> x;
  cout << compositionalInverse(f, n) << '\n';

  return 0;
}
