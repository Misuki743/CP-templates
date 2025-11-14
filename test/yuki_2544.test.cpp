#define PROBLEM "https://yukicoder.me/problems/no/2544"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../combi/binom.cpp"
#include "../poly/NTTmint.cpp"

NTT<23, 119, 3, mint> ntt;
binomial<mint> bn(1 << 20);

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;

  vector<mint> A(n + 1), B(n + 1);
  for(int i = 0; i <= n; i++)
    A[i] = bn.fac(i), B[i] = bn.faci(n - i);

  A = ntt.conv(A, B);

  mint ans = 0;
  for(int l = 1; l <= n; l++)
    ans += (n - l + 1) * bn.fac(n - l) * A[l + n];

  cout << ans * mint((ll)n * (n + 1) / 2).pow(q - 1) * q << '\n';

  return 0;
}
