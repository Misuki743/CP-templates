//////////////////////////////////////////////////
//template name: NTT
//author: __Shioko(Misuki)
//last update: 2022/04/07
//remark: remember to call init() before doing NTT()!!!
//remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD
//remark: a.size() <= 2^K must be satisfied
//some common modulo: 998244353 = 2^23 * 119 + 1, R = 3

const long long K = 23, C = 119, R = 3;
const long long MOD = (1ll << K) * C + 1;
long long w[K + 1], w_inv[K + 1];

long long POW(long long base, long long index) {
  if (index == 0)
    return 1ll;
  int res = (base == 0ll ? 0ll : 1ll);
  while(index) {
    if (index & 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    index >>= 1;
  }

  return res;
}

long long inv(long long val) {
  return POW(val, MOD - 2);
}

void init() {
  w[K] = POW(R, C);
  for(int i = K - 1; i >= 0; i--)
    w[i] = (w[i + 1] * w[i + 1]) % MOD;
  for(int i = 0; i <= K; i++)
    w_inv[i] = inv(w[i]);
}

void NTT(vector<long long> &a, bool inverse) {
  int n = a.size();

  vector<long long> tmp = a;
  for(int i = 0; i < a.size(); i++) {
    int idx = 0;
    int lgn = __lg(n);
    for(int j = lgn - 1; j >= 0; j--) {
      idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);
    }
    a[idx] = tmp[i];
  }

  for(int l = 2; l <= n; l <<= 1) {
    const long long w_l = (inverse ? w_inv[__lg(l)] : w[__lg(l)]);

    for(int i = 0; i < n; i += l) {
      long long w = 1;
      for(int j = 0; j < (l >> 1); j += 1) {
        long long t = (a[i + j + l / 2] * w) % MOD;  
        a[i + j + l / 2] = (a[i + j] - t + MOD) % MOD;
        a[i + j] = (a[i + j] + t) % MOD;
        w = (w * w_l) % MOD;
      }
    }
  }

  if (inverse) {
    const long long INV = inv(n);
    for(int i = 0; i < n; i++)
      a[i] = (a[i] * INV) % MOD;
  }
}

vector<int> multiply(vector<long long> a, vector<long long> b) {
  int mxSz = (int)a.size() + (int)b.size() - 1;
  int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));

  vector<long long> c(n, 0), d(n, 0);
  for(int i = 0; i < a.size(); i++)
    c[i] = a[i];
  for(int i = 0; i < b.size(); i++)
    d[i] = b[i];

  NTT(c, false);
  NTT(d, false);

  for(int i = 0; i < n; i++)
    c[i] = (c[i] * d[i]) % MOD;

  NTT(c, true);
  
  c.resize(mxSz);

  return c;
}
//////////////////////////////////////////////////
