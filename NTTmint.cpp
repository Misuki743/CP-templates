/**
 * template name: NTTmint
 * reference: https://judge.yosupo.jp/submission/69896
 * last update: 2024/01/07
 * include: mint
 * remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD
 * remark: a.size() <= 2^K must be satisfied
 * some common modulo: 998244353  = 2^23 * 119 + 1, R = 3
 *                     469762049  = 2^26 * 7   + 1, R = 3
 *                     1224736769 = 2^24 * 73  + 1, R = 3
 * verify: Library Checker - Convolution
 */

template<int32_t k = 23, int32_t c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>
struct NTT {

  using u32 = uint32_t;
  static constexpr u32 mod = (1 << k) * c + 1;
  static constexpr u32 get_mod() { return mod; }

  static void ntt(vector<Mint> &a, bool inverse) {
    static array<Mint, 30> w, w_inv;
    if (w[0] == 0) {
      Mint root = 2;
      while(root.pow((mod - 1) / 2) == 1) root += 1;
      for(int i = 0; i < 30; i++)
        w[i] = -(root.pow((mod - 1) >> (i + 2))), w_inv[i] = 1 / w[i];
    }
    int n = ssize(a);
    if (not inverse) {
      for(int m = n; m >>= 1; ) {
        Mint ww = 1;
        for(int s = 0, l = 0; s < n; s += 2 * m) {
          for(int i = s, j = s + m; i < s + m; i++, j++) {
            Mint x = a[i], y = a[j] * ww;
            a[i] = x + y, a[j] = x - y;
          }
          ww *= w[__builtin_ctz(++l)];
        }
      }
    } else {
      for(int m = 1; m < n; m *= 2) {
        Mint ww = 1;
        for(int s = 0, l = 0; s < n; s += 2 * m) {
          for(int i = s, j = s + m; i < s + m; i++, j++) {
            Mint x = a[i], y = a[j];
            a[i] = x + y, a[j] = (x - y) * ww;
          }
          ww *= w_inv[__builtin_ctz(++l)];
        }
      }
      Mint inv = 1 / Mint(n);
      for(Mint &x : a) x *= inv;
    }
  }

  vector<Mint> conv(vector<Mint> a, vector<Mint> b) {
    int sz = ssize(a) + ssize(b) - 1;
    int n = bit_ceil((u32)sz);

    a.resize(n, 0);
    ntt(a, false);
    b.resize(n, 0);
    ntt(b, false);

    for(int i = 0; i < n; i++)
      a[i] *= b[i];

    ntt(a, true);

    a.resize(sz);

    return a;
  }
};
