template<NTT Ntt, class Mint>
mint BostanMori(vector<Mint> P, vector<Mint> Q, ll k) {
  assert(!P.empty() and !Q.empty() and Q[0] != 0);
  
  int d = max(ssize(P), ssize(Q) - 1);
  P.resize(d, 0), Q.resize(d + 1, 0);

  int size = 1 << (bit_width((unsigned)d) + 1);
  while(k) {
    vector<Mint> Qneg(size);
    for(int i = 0; i < ssize(Q); i++)
      Qneg[i] = Q[i] * ((i & 1) ? -1 : 1);
    Ntt.ntt(Qneg, false);

    vector<Mint> U(size), V(size);
    copy(P.begin(), P.end(), U.begin());
    copy(Q.begin(), Q.end(), V.begin());

    Ntt.ntt(U, false), Ntt.ntt(V, false);
    for(int i = 0; i < size; i++)
      U[i] *= Qneg[i], V[i] *= Qneg[i];
    Ntt.ntt(U, true), Ntt.ntt(V, true);

    for(int i = k & 1; i < 2 * d; i += 2)
      P[i >> 1] = U[i];
    for(int i = 0; i <= 2 * d; i += 2)
      Q[i >> 1] = V[i];
    k >>= 1;
  }

  return P[0] / Q[0];
}
