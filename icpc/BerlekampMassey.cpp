void modadd(ll &a, ll b) { a = (a + b % mod + mod) % mod; }
vector<ll> BerlekampMassey(vector<ll> s) {
  for(ll &x : s) x = (x % mod + mod) % mod;
  vector<ll> c(1), c0(1);
  int f = -1;
  for(int i = 0; i < ssize(s); i++) {
    ll del = s[i];
    for(int j = 1; j < ssize(c); j++)
      modadd(del, -s[i - j] * c[j]);
    if (del == 0) continue;
    if (f == -1) {
      f = i, c.resize(i + 2, 0);
    } else {
      vector<ll> d = c0;
      int fp = f;
      if (i - ssize(c) > f - ssize(c0))
        c0 = c, fp = i;
      for(ll &x : d) x = (-x + mod) % mod;
      d.insert(d.begin() + 1, 1);
      ll div = 0;
      for(int j = 1; j < ssize(d); j++)
        modadd(div, s[f - j + 1] * d[j]);
      ll coef = del * modpow(div, mod - 2) % mod;
      for(ll &x : d) x = x * coef % mod;
      d.insert(d.begin() + 1, i - f - 1, 0);
      if (ssize(c) < ssize(d)) c.resize(d.size(), 0);
      for(int j = 1; j < ssize(d); j++) modadd(c[j], d[j]);
      f = fp;
    }
  }
  return c;
}
