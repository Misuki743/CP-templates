//compute det(M0 + M1x) with N/MOD probability to fail
template<class Mint>
auto det_poly(matrix<Mint> M0, matrix<Mint> M1) {
  const int N = ssize(M0);
  assert(N > 0 and ssize(M1) == N and ssize(M0[0]) == N and ssize(M1[0]) == N);

  mt19937_64 rng(clock);

  Mint a = rng() % Mint::get_mod();
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      M0[i][j] += a * M1[i][j];
  swap(M0, M1);

  auto [ok, M1I] = M1.inv();
  if (!ok) return pair(false, vc<Mint>(N + 1, 0));

  auto p = characteristic_polynomial(-M1I * M0);
  Mint inv_det = M1I.det().inverse();
  for(Mint &x : p) x *= inv_det;

  vc<Mint> q(N + 1);
  for(int i = 0; i < ssize(p); i++)
    q[N - i] = p[i];

  binomial<Mint> bn(N + 1);

  vc<Mint> r(N + 1);
  for(int i = 0; i < ssize(q); i++) {
    Mint mul = 1;
    for(int j = 0; j <= i; j++, mul *= -a)
      r[i - j] += q[i] * mul * bn.binom(i, j);
  }

  return pair(true, r);
}
