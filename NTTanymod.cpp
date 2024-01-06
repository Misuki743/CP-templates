/**
 * template name: NTTanyMod
 * author: Misuki
 * last update: 2023/12/04
 * reference: https://math314.hateblo.jp/entry/2015/05/07/014908
 *            https://judge.yosupo.jp/submission/15581
 * remark: n * mod^2 < prod of mods(~= 5e26) should be satisfied
 * some common modulo: 998244353  = 2^23 * 119 + 1, R = 3
 *                     469762049  = 2^26 * 7   + 1, R = 3
 *                     167772161  = 2^25 * 5   + 1, R = 3
 * verify: Library Checker - Convolution (Mod 1,000,000,007)
 */

template<class Mint>
vector<Mint> convAnyMod(vector<Mint> a, vector<Mint> b) {
  using Mint0 = MontgomeryModInt<998244353>;
  using Mint1 = MontgomeryModInt<469762049>;
  using Mint2 = MontgomeryModInt<167772161>;
  NTT<23, 119, 3, Mint0> ntt0;
  NTT<26, 7, 3, Mint1> ntt1;
  NTT<25, 5, 3, Mint2> ntt2;
  vector<Mint0> a0(ssize(a)), b0(ssize(b));
  vector<Mint1> a1(ssize(a)), b1(ssize(b));
  vector<Mint2> a2(ssize(a)), b2(ssize(b));
  for(int i = 0; i < ssize(a); i++)
    a0[i] = a[i].get(), a1[i] = a[i].get(), a2[i] = a[i].get();
  for(int i = 0; i < ssize(b); i++)
    b0[i] = b[i].get(), b1[i] = b[i].get(), b2[i] = b[i].get();
  vector<Mint0> x = ntt0.conv(a0, b0);
  vector<Mint1> y = ntt1.conv(a1, b1);
  vector<Mint2> z = ntt2.conv(a2, b2);
  vector<Mint> res(ssize(x));
  constexpr uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();
  static const Mint1 im0 = 1 / Mint1(mod0);
  static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;
  static const Mint m0 = mod0, m0m1 = m0 * mod1;
  for(int i = 0; i < ssize(x); i++) {
    int y0 = x[i].get();
    int y1 = (im0 * (y[i] - y0)).get();
    int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();
    res[i] = y0 + m0 * y1 + m0m1 * y2;
  }

  return res;
}
