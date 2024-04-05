//#include<poly/NTTmint.cpp>
//#include<modint/MontgomeryModInt.cpp>
//#include<numtheory/sqrtMod.cpp>

template<class Mint>
FPS<Mint> FPSsqrt(FPS<Mint> F, int k) {
  assert(!F.empty());
  if (F[0] == 0) {
    for(int i = 1; i < ssize(F); i++) {
      if (F[i] != 0) {
        if (i & 1) return {}; //no solution
        if (i / 2 >= k) break;
        auto Q = FPSsqrt(FPS<Mint>(F.begin() + i, F.end()), k - i / 2);
        if (Q.empty()) return {}; //no solution
        Q.resize(k, 0);
        ranges::rotate(Q, Q.begin() + k - i / 2);
        return Q;
      }
    }
    return FPS<Mint>(k, 0);
  }

  Mint sqr = sqrt(F[0].get(), Mint::get_mod()), inv2 = 1 / Mint(2);
  if (sqr == -1) return {}; //no solution
  FPS<Mint> Q(1, sqr);
  for(int i = 1; (1 << (i - 1)) < k; i++) {
    FPS<Mint> P(1 << i, 0);
    copy(F.begin(), F.begin() + min(1 << i, (int)F.size()), P.begin());
    FPS<Mint> R = P * Q.inv(1 << i);
    for(int j = 0; Mint &x : Q)
      R[j++] += x;
    for(Mint &x : R)
      x *= inv2;
    R.resize(1 << i);
    R.swap(Q);
  }
  Q.resize(k);
  return Q;
}
