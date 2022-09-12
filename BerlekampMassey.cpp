//////////////////////////////////////////////////
//template name: Berlekamp-Massey
//author: __Shioko(Misuki)
//last update: 2022/09/12
//include: math
//verify: library checker - Find Linear Recurrence

vector<int> BerlekampMassey(vector<int> s) {
  vector<int> c(1, 0), oldc(1, 0);
  int f = -1;
  for(int i = 0; i < s.size(); i++) {
    int delta = s[i];
    for(int j = 1; j < c.size(); j++)
      delta = (delta - (long long)s[i - j] * c[j]) % MOD;

    if (delta == 0)
      continue;

    if (f == -1) {
      f = i;
      c.resize(i + 2, 0);
    } else {
      vector<int> d = oldc;
      int fp = f;
      if (i - (int)c.size() + 1 > f - (int)oldc.size() + 1)
        oldc = c, fp = i;
      for(int &X : d)
        X = -X;
      d.insert(d.begin() + 1, 1);
      int div = 0;
      for(int j = 1; j < d.size(); j++)
        div = (div + (long long)s[f + 1 - j] * d[j]) % MOD;
      int coef = ((long long)delta * inv(div)) % MOD;
      for(int &X : d)
        X = ((long long)X * coef) % MOD;
      d.insert(d.begin() + 1, i - f - 1, 0);
      if (c.size() < d.size())
        c.resize(d.size(), 0);
      for(int j = 1; j < d.size(); j++)
        c[j] = (c[j] + d[j]) % MOD;

      f = fp;
    }
  }

  for(int &X : c)
    X = (X + MOD) % MOD;

  return c;
}
//////////////////////////////////////////////////
