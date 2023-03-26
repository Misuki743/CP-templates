//////////////////////////////////////////////////
//template name: fastSubsetTransform
//author: __Shioko(Misuki)
//last update: 2023/03/26
//include template: FPS

vector<FPS> FST(FPS f) {
  int n = __lg(f.size());
  vector<FPS> fHat(1 << n, FPS(n + 1));
  for(int i = 0; i < (1 << n); i++)
    fHat[i][__builtin_popcount(i)] = f[i];

  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          fHat[i|1<<k][j] += fHat[i][j];

  return fHat;
}

FPS FSTinv(vector<FPS> fHat) {
  int n = __lg(fHat.size());
  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          fHat[i|1<<k][j] -= fHat[i][j];

  FPS f(1 << n);
  for(int i = 0; i < (1 << n); i++)
    f[i] = fHat[i][__builtin_popcount(i)];

  return f;
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
//////////////////////////////////////////////////
