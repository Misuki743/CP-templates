//////////////////////////////////////////////////
//template name: subsetConvolution
//author: __Shioko(Misuki)
//last update: 2023/03/26
//verify: Library Checker - Subset Convolution

template<class T>
vector<T> subsetConvolution(vector<T> &f, vector<T> &g) {
  int n = __lg(f.size());
  vector fHat(1 << n, vector<T>(n + 1)), gHat(1 << n, vector<T>(n + 1));
  for(int i = 0; i < (1 << n); i++)
    fHat[i][__builtin_popcount(i)] = f[i];
  for(int i = 0; i < (1 << n); i++)
    gHat[i][__builtin_popcount(i)] = g[i];

  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          fHat[i|1<<k][j] += fHat[i][j];
  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          gHat[i|1<<k][j] += gHat[i][j];

  for(int i = 0; i < (1 << n); i++) {
    for(int j = n; j >= 0; j--) {
      for(int k = 1; k <= n - j; k++)
        fHat[i][j + k] += fHat[i][j] * gHat[i][k];
      fHat[i][j] *= gHat[i][0];
    }
  }

  for(int k = 0; k < n; k++)
    for(int i = 0; i < (1 << n); i++)
      if (!(i >> k & 1))
        for(int j = 0; j <= n; j++)
          fHat[i|1<<k][j] -= fHat[i][j];

  vector<T> res(1 << n);
  for(int i = 0; i < (1 << n); i++)
    res[i] = fHat[i][__builtin_popcount(i)];

  return res;
}
//////////////////////////////////////////////////
