/**
 * template name: NTT
 * author: Misuki
 * last update: 2023/12/04
 * remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD
 * remark: a.size() <= 2^K must be satisfied
 * some common modulo: 998244353  = 2^23 * 119 + 1, R = 3
 *                     469762049  = 2^26 * 7   + 1, R = 3
 *                     1224736769 = 2^24 * 73  + 1, R = 3
 * verify: Library Checker - Convolution
 */

template<int32_t k, int32_t c, int32_t r>
struct NTT {

  using u32 = uint32_t;
  static const ll mod = (1ll << k) * c + 1;

  static ll binpow(ll a, ll b) {
    if (b == 0)
      return 1;
    if (a == 0)
      return 0;
    ll d = 1;
    while(b) {
      if (b & 1) d = d * a % mod;
      b >>= 1, a = a * a % mod;
    }
    return d;
  }

  static ll inv(ll a) { return binpow(a, mod - 2); }
  static constexpr ll get_mod() { return mod; }

  static void ntt(vector<ll> &a, bool inverse) {
    static array<ll, k + 1> w = {}, w_inv = {};
    if (w[k] == 0) {
      w[k] = binpow(r, c);
      for(int i = k - 1; i >= 0; i--)
        w[i] = w[i + 1] * w[i + 1] % mod;
      for(int i = 0; i <= k; i++)
        w_inv[i] = inv(w[i]);
    }
    int n = ssize(a);
    vector<ll> tmp = a;
    for(int i = 0; i < ssize(a); i++) {
      int idx = 0, lgn = bit_width((u32)n) - 1;
      for(int j = lgn - 1; j >= 0; j--)
        idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);
      a[idx] = tmp[i];
    }

    for(int l = 2; l <= n; l <<= 1) {
      const ll w_l = (inverse ? w_inv[bit_width((u32)l) - 1] : w[bit_width((u32)l) - 1]);

      for(int i = 0; i < n; i += l) {
        ll w = 1;
        for(int j = 0; j < (l >> 1); j++) {
          ll t = a[i + j + l / 2] * w % mod;
          a[i + j + l / 2] = (a[i + j] - t + mod) % mod;
          a[i + j] = (a[i + j] + t) % mod;
          w = w * w_l % mod;
        }
      }
    }

    if (inverse) {
      ll Inv = inv(n);
      for(int i = 0; i < ssize(a); i++)
        a[i] = a[i] * Inv % mod;
    }
  }

  vector<ll> conv(vector<ll> a, vector<ll> b) {
    int sz = ssize(a) + ssize(b) - 1;
    int n = bit_ceil((u32)sz);

    a.resize(n, 0);
    ntt(a, false);
    b.resize(n, 0);
    ntt(b, false);

    for(int i = 0; i < n; i++)
      a[i] = a[i] * b[i] % mod;

    ntt(a, true);

    a.resize(sz);

    return a;
  }
};
