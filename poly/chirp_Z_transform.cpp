template<NTT Ntt, class Mint>
vector<Mint> chirp_Z_transform(vector<Mint> P, Mint a, Mint r, int m) {
  const int n = ssize(P);
  const int sz = bit_ceil((unsigned)(2 * (n - 1) + m + 1));

  if (r == Mint(0)) {
    vector<Mint> Q(m, P[0]);
    mint prod_a = a;
    for(int i = 1; i < n; i++, prod_a *= a)
      Q[0] += P[i] * prod_a;
    return Q;
  }

  vector<Mint> pw_r(n + m), pw_ri(n + m);
  pw_r[0] = 1;
  for(int i = 1; i < n + m; i++)
    pw_r[i] = pw_r[i - 1] * r;
  pw_ri.back() = 1 / pw_r.back();
  for(int i = n + m - 2; i >= 0; i--)
    pw_ri[i] = pw_ri[i + 1] * r;

  vector<Mint> F(sz), G(sz);
  {
    mint prod_a = 1, prod_ri = 1;
    for(int i = 0; i < n; prod_a *= a, prod_ri *= pw_ri[i++])
      F[(sz - i) % sz] = P[i] * prod_a * prod_ri;
    mint prod_r = 1;
    for(int i = 0; i < n + m - 1; prod_r *= pw_r[i++])
      G[i] = prod_r;
  }

  Ntt.ntt(F, false), Ntt.ntt(G, false);
  for(int i = 0; i < sz; i++)
    F[i] *= G[i];
  Ntt.ntt(F, true);

  vector<Mint> Q(m);
  mint prod_ri = 1;
  for(int i = 0; i < m; prod_ri *= pw_ri[i++])
    Q[i] = F[i] * prod_ri;

  return Q;
}
