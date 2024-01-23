#define PROBLEM "https://yukicoder.me/problems/no/2613"

#include "../default/t.cpp";
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../numtheory/fastFactorize.cpp"
#include "../numtheory/primitiveRoot.cpp"
#include "../poly/mulConvolution.cpp"

int p;
int fac[200000], facInv[200000];
int C(int a, int b) {
  if (b > a or b < 0) return 0;
  else return (ll)fac[a] * facInv[b] % p * facInv[a - b] % p;
}

NTT ntt;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll n; cin >> n >> p;

  fac[0] = 1;
  for(int i = 1; i < p; i++)
    fac[i] = (ll)fac[i - 1] * i % p;
  facInv[p - 1] = modpow(fac[p - 1], p - 2, p);
  for(int i = p - 2; i >= 0; i--)
    facInv[i] = (ll)facInv[i + 1] * (i + 1) % p;

  mulConvolution mu(p);

  vector<mint> f(p);
  f[1] = 1;
  while(n) {
    int nd = n % p; n /= p;
    vector<mint> g(p);
    for(int i = 0; i < p; i++)
      g[C(nd, i)] += 1;
    f = mu.mulConv(f, g, ntt.conv);
  }

  mint ans = 0;
  for(int i = 1; i < p; i++)
    ans += f[i] * i;

  cout << ans << '\n';

  return 0;
}
