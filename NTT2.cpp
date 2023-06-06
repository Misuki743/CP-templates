//////////////////////////////////////////////////
//template name: NTT
//author: Misuki
//last update: 2022/06/05
//remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD
//remark: a.size() <= 2^K must be satisfied
//some common modulo: 998244353 = 2^23 * 119 + 1, R = 3

template<int32_t k, int32_t c, int32_t r, typename mint>
struct NTT {

  mint w[k + 1], w_inv[k + 1];

  NTT() {
    w[k] = mint(r).pow(c);
    for(int i = k - 1; i >= 0; i--)
      w[i] = w[i + 1] * w[i + 1];
    for(int i = 0; i <= k; i++)
      w_inv[i] = w[i].inverse();
  }

  void ntt(vector<mint> &a, bool inverse) {
    int n = a.size();

    vector<mint> tmp = a;
    for(int i = 0; i < (int)a.size(); i++) {
      int idx = 0, lgn = __lg(n);
      for(int j = lgn - 1; j >= 0; j--)
        idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);
      a[idx] = tmp[i];
    }

    for(int l = 2; l <= n; l <<= 1) {
      mint w_l = (inverse ? w_inv[__lg(l)] : w[__lg(l)]);

      for(int i = 0; i < n; i += l) {
        mint w(1);
        for(int j = 0; j < (l >> 1); j += 1) {
          mint t = a[i + j + l / 2] * w;
          a[i + j + l / 2] = a[i + j] - t;
          a[i + j] += t;
          w = (w * w_l);
        }
      }
    }

    if (inverse) {
      mint inv = mint(n).inverse();
      for(int i = 0; i < (int)a.size(); i++)
        a[i] *= inv;
    }
  }

  vector<mint> multiply(vector<mint> a, vector<mint> b) {
    int mxSz = (int)a.size() + (int)b.size() - 1;
    int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));

    a.resize(n, 0);
    b.resize(n, 0);

    ntt(a, false);
    ntt(b, false);

    for(int i = 0; i < n; i++)
      a[i] *= b[i];

    ntt(a, true);
    
    a.resize(mxSz);

    return a;
  }
};
//////////////////////////////////////////////////
