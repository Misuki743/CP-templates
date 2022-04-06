//////////////////////////////////////////////////
//template name: NTT
//author: __Shioko(Misuki)
//last update: 2022/04/07

const int K = 23, C = 7 * 17, R = 62;
const long long MOD = 998244353;
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

vector<long long> NTT(vector<long long> a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }

  vector<long long> a_odd(n / 2), a_even(n / 2);
  for(int i = 0; i < n; i += 2)
    a_even[i / 2] = a[i];
  for(int i = 0; i < n; i += 2)
    a_odd[i / 2] = a[i + 1];
  a_even = NTT(a_even);
  a_odd = NTT(a_odd);

  const long long w_n = w[__lg(n)];
  long long w_k = 1;
  for(int i = 0; i < n / 2; i++, w_k = (w_k * w_n) % MOD)
    a[i] = (a_even[i] + a_odd[i] * w_k) % MOD;
  for(int i = n / 2; i < n; i++, w_k = (w_k * w_n) % MOD)
    a[i] = (a_even[i - n / 2] + w_k * a_odd[i - n / 2]) % MOD;

  return a;
}

vector<long long> INTT(vector<long long> a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }

  vector<long long> a_odd(n / 2), a_even(n / 2);
  for(int i = 0; i < n; i += 2)
    a_even[i / 2] = a[i];
  for(int i = 0; i < n; i += 2)
    a_odd[i / 2] = a[i + 1];
  a_even = INTT(a_even);
  a_odd = INTT(a_odd);

  const long long w_n = w_inv[__lg(n)];
  long long w_k = 1;
  for(int i = 0; i < n / 2; i++, w_k = (w_k * w_n) % MOD)
    a[i] = (a_even[i] + a_odd[i] * w_k) % MOD;
  for(int i = n / 2; i < n; i++, w_k = (w_k * w_n) % MOD)
    a[i] = (a_even[i - n / 2] + w_k * a_odd[i - n / 2]) % MOD;

  return a;
}

vector<long long> convolution(vector<long long> a, vector<long long> b) {
  for(int i = 0; i < a.size(); i++) 
    a[i] = (a[i] * b[i]) % MOD;
  return a;
}

vector<long long> multiply(vector<long long> a, vector<long long> b) {
  int mxSz = (int)a.size() + (int)b.size() - 1;
  int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 2));

  vector<long long> c(n, 0), d(n, 0);
  for(int i = 0; i < a.size(); i++)
    c[i] = a[i];
  for(int i = 0; i < b.size(); i++)
    d[i] = b[i];

  vector<long long> cp = NTT(c), dp = NTT(d);
  cp = convolution(cp, dp);
  cp = INTT(cp);

  const int inv_n = inv(n);
  for(int i = 0; i < cp.size(); i++)
    cp[i] = (cp[i] * inv_n) % MOD;

  cp.resize(mxSz);

  return cp;
}
//////////////////////////////////////////////////
