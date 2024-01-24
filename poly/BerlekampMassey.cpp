vector<mint> BerlekampMassey(vector<mint> s) {
  vector<mint> c(1, 0), oldC(1, 0);
  int f = -1;
  for(int i = 0; i < ssize(s); i++) {
    mint delta = s[i];
    for(int j = 1; j < ssize(c); j++)
      delta -= s[i - j] * c[j];

    if (delta == 0) continue;

    if (f == -1) {
      f = i;
      c.resize(i + 2, 0);
    } else {
      vector<mint> d = oldC;
      int fp = f;
      if (i - ssize(c) > f - ssize(oldC))
        oldC = c, fp = i;
      for(mint &x : d)
        x *= -1;
      d.insert(d.begin() + 1, 1);
      mint div = 0;
      for(int j = 1; j < ssize(d); j++)
        div += s[f - j + 1] * d[j];
      mint coef = delta / div;
      for(mint &x : d)
        x *= coef;
      d.insert(d.begin() + 1, i - f - 1, 0);
      if (ssize(c) < ssize(d))
        c.resize(d.size(), 0);
      for(int j = 1; j < ssize(d); j++)
        c[j] += d[j];
      f = fp;
    }
  }

  return c;
}
