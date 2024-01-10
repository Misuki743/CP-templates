/**
 * template name: fastSubsetTransform
 * author: Misuki
 * last update: 2024/01/10
 * include template: FPS
 * verify: Library Checker - Subset Convolution
 */

template<class FPS>
vector<FPS> FST(FPS f) {
  assert(popcount(f.size()) == 1);
  int n = bit_width(f.size()) - 1;
  vector<FPS> fHat(1 << n, FPS(n + 1));
  for(unsigned i = 0; i < (1 << n); i++)
    fHat[i][popcount(i)] = f[i];

  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          fHat[i|1<<k][j] += fHat[i][j];

  return fHat;
}

template<class FPS>
FPS FSTinv(vector<FPS> fHat) {
  int n = bit_width(fHat.size()) - 1;
  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          fHat[i|1<<k][j] -= fHat[i][j];

  FPS f(1 << n);
  for(unsigned i = 0; i < (1 << n); i++)
    f[i] = fHat[i][popcount(i)];

  return f;
}

template<class FPS>
FPS conv(FPS f, FPS g) {
  assert(ssize(f) == ssize(g));
  auto fHat = FST(f), gHat = FST(g);
  for(int i = 0; i < ssize(fHat); i++) {
    fHat[i] *= gHat[i];
    fHat[i].resize(ssize(gHat[i]));
  }
  return FSTinv(fHat);
}

/* OMG this is so slowwwwwwwwwwwwwwwww
FPS subsetPow(FPS f, long long idx) {
  int n = __lg(f.size());
  vector<FPS> fHat = FST(f);
  for(int i = 0; i < fHat.size(); i++)
    fHat[i] = fHat[i].pow(idx, n + 1);
  f = FSTinv(fHat);
  return f;
}
*/
