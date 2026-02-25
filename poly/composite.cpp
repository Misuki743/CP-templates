//7sec on N = 2^17
template<class Mint>
vc<FPS<Mint>> inner(FPS<Mint> g, vc<FPS<Mint>> Q, int n, int k) {
  if (n == 0) {
    FPS<Mint> h = g * Q[0].inv(ssize(Q[0])).rev();
    vc<FPS<Mint>> P(n + 1, FPS<Mint>(k + 1));
    for(int i = 0; i < ssize(g); i++)
      P[0][i] = h[i + ssize(Q[0]) - 1];
    return P;
  }
  auto R = Q;
  for(int i = 1; i <= n; i += 2)
    for(mint &x : R[i])
      x = -x;
  auto T = convolution_2d(Q, R);
  vc V(n / 2 + 1, FPS<Mint>(k * 2 + 1));
  for(int i = 0; i <= n / 2; i++) V[i] = T[i * 2];
  auto U = inner(g, V, n / 2, k * 2);
  vc S(n * 2 + 1, FPS<Mint>(k * 2 + 1));
  for(int i = 0; i <= n / 2; i++) S[i * 2 + n % 2] = U[i];
  vc revR(n + 1, FPS<Mint>(k + 1));
  for(int i = 0; i <= n; i++) revR[i] = R[n - i].rev();
  auto Pshift = convolution_2d(S, revR);
  vc P(n + 1, FPS<Mint>(k + 1));
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= k; j++)
      P[i][j] = Pshift[i + n][j + k];
  return P;
}

//calculate g(f(x)) mod x^{n + 1}, assume [x^0]f(x) = 0.
template<class Mint>
FPS<Mint> composite(FPS<Mint> f, FPS<Mint> g) {
  assert(ssize(f) == ssize(g));
  int n = ssize(f) - 1, k = 1;
  vc Q(n + 1, FPS<Mint>(k + 1));
  Q[0][0] = 1;
  for(int i = 0; i < n + 1; i++) Q[i][1] = -f[i];
  auto P = inner(g, Q, n, k);
  FPS<Mint> h(n + 1);
  for(int i = 0; i <= n; i++) h[i] = P[i][0];
  return h.rev();
}
