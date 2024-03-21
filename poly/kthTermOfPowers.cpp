//#include "modint/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"

//compute [x^k]f(x)^i for all i in [0, n) in O(klg^2k)
//reference: https://noshi91.hatenablog.com/entry/2024/03/16/224034
template<class Mint>
FPS<Mint> kthTermOfPowers(int k, int n, FPS<Mint> g, FPS<Mint> f = FPS<Mint>(1, 1)) {
  assert(g[0] == 0);
  auto remap = [](FPS<Mint> f, int x0, int x1) -> FPS<Mint> {
    int y0 = (ssize(f) + x0 - 1) / x0;
    FPS<Mint> g(y0 * x1);
    for(int y = 0; y < y0; y++)
      for(int x = 0; x < x0 and y * x0 + x < ssize(f); x++)
        g[y * x1 + x] = f[y * x0 + x];
    return g;
  };

  FPS<Mint> P(k + 1), Q(2 * (k + 1));
  for(int i = 0; i < ssize(f) and i <= k; i++)
    P[i] = f[i];
  Q[0] = 1;
  for(int i = 0; i < ssize(g) and i <= k; i++)
    Q[i + k + 1] = -g[i];

  while(k) {
    int yp = (ssize(Q) + k) / (k + 1) * 2 - 1, x0 = 2 * k + 1;
    P = remap(P, k + 1, x0), Q = remap(Q, k + 1, x0);
    int sz = bit_ceil((unsigned)yp * x0);
    P.resize(sz), Q.resize(sz);
    FPS<Mint> Qneg = Q;
    for(int y = 0; y < yp; y++)
      for(int x = 1; x < x0; x += 2)
        Qneg[y * x0 + x] *= -1;
    FPS<Mint>::dft(P, false), FPS<Mint>::dft(Q, false), FPS<Mint>::dft(Qneg, false);
    FPS<Mint> U(sz), V(sz);
    for(int i = 0; i < sz; i++)
      U[i] += P[i] * Qneg[i], V[i] = Q[i] * Qneg[i];
    FPS<Mint>::dft(U, true), FPS<Mint>::dft(V, true);
    int xp = k / 2 + 1;
    FPS<Mint> UU(yp * xp);
    for(int y = 0; y < yp; y++)
      for(int x = k & 1; x / 2 < xp and y * x0 + x < ssize(U); x += 2)
        UU[y * xp + x / 2] = U[y * x0 + x];
    FPS<Mint> VV(yp * xp);
    for(int y = 0; y < yp; y++)
      for(int x = 0; x / 2 < xp and y * x0 + x < ssize(V); x += 2)
        VV[y * xp + x / 2] = V[y * x0 + x];
    P.swap(UU), Q.swap(VV);
    k /= 2;
  }

  FPS<Mint> res = P * Q.inv(n);
  res.resize(n);

  return res;
}
