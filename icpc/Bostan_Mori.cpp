//#include "polyope"
ll BostanMori(vl P, vl Q, ll k) {
  assert(!P.empty() and !Q.empty() and Q[0] != 0);

  int d = max(ssize(P), ssize(Q) - 1);
  P.resize(d, 0), Q.resize(d + 1, 0);

  int size = 1 << (bit_width((unsigned)d) + 1);
  ll inv = modpow(size, mod - 2);
  while(k) {
    vl Qneg(size);
    for(int i = 0; i < ssize(Q); i++)
      Qneg[i] = Q[i] * ((i & 1) ? mod - 1 : 1) % mod;
    ntt(Qneg);

    vl U(size), V(size);
    ranges::copy(P, U.begin());
    ranges::copy(Q, V.begin());
    ntt(U), ntt(V);
    for(int i = 0; i < size; i++) {
      U[i] = U[i] * Qneg[i] % mod * inv % mod;
      V[i] = V[i] * Qneg[i] % mod * inv % mod;
    }
    ranges::reverse(U), ranges::reverse(V);
    ranges::rotate(U, prev(U.end()));
    ranges::rotate(V, prev(V.end()));
    ntt(U), ntt(V);

    for(int i = k & 1; i < 2 * d; i += 2)
      P[i >> 1] = U[i];
    for(int i = 0; i <= 2 * d; i += 2)
      Q[i >> 1] = V[i];
    k >>= 1;
  }
  return P[0] * modpow(Q[0], mod - 2) % mod;
}

ll calc_linear_recurrence(vl a, vl c, ll k) {
  assert(ssize(a) >= ssize(c) - 1);
  a.resize(ssize(c) - 1);
  for(ll &x : c) x = (mod - x) % mod;
  c[0] = 1;
  a = conv(a, c);
  a.resize(ssize(c) - 1);
  return BostanMori(a, c, k);
}
