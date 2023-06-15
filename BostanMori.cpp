/**
 * template name: Bostan-Mori
 * author: Misuki
 * last update: 2023/01/25
 * include: mint(with NTT-able MOD), FPS
 * usage: compute k-th term of P(x)/Q(x) in O(dlgdlgk)
 * verify: Library Checker - Kth term of Linearly Recurrent Sequence
 */

mint BostanMori(FPS P, FPS Q, long long k) {
  assert(!P.empty() and !Q.empty() and Q[0] != 0);

  int d = max((int)P.size(), (int)Q.size() - 1);
  P.resize(d, 0);
  Q.resize(d + 1, 0); 

  int sz = (2 * d + 1 == 1 ? 2 : (1 << __lg(2 * d) + 1));
  while(k) {
    FPS Qneg(sz);
    for(int i = 0; i < Q.size(); i++)
      Qneg[i] = Q[i] * ((i & 1) ? -1 : 1);
    Qneg.NTT(false);

    FPS U(sz), V(sz);
    for(int i = 0; i < P.size(); i++)
      U[i] = P[i];
    for(int i = 0; i < Q.size(); i++)
      V[i] = Q[i];

    U.NTT(false);
    V.NTT(false);
    for(int i = 0; i < sz; i++)
      U[i] *= Qneg[i];
    for(int i = 0; i < sz; i++)
      V[i] *= Qneg[i];
    U.NTT(true);
    V.NTT(true);

    for(int i = k & 1; i <= 2 * d - 1; i += 2)
      P[i >> 1] = U[i];
    for(int i = 0; i <= 2 * d; i += 2)
      Q[i >> 1] = V[i];
    k >>= 1;
  }

  return P[0] / Q[0];
}
