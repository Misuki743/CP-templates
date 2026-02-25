//the result should not exceed long long
vll convolution_ll(vll a, vll b) {
  assert(ssize(a) + ssize(b) - 1 <= (1 << 23));
  using Mint0 = MontgomeryModInt<998244353>;
  using Mint1 = MontgomeryModInt<469762049>;
  using Mint2 = MontgomeryModInt<167772161>;
  NTT<23, 119, 3, Mint0> ntt0;
  NTT<26, 7, 3, Mint1> ntt1;
  NTT<25, 5, 3, Mint2> ntt2;
  vector<Mint0> a0(size(a)), b0(size(b));
  vector<Mint1> a1(size(a)), b1(size(b));
  vector<Mint2> a2(size(a)), b2(size(b));
  for(int i = 0; i < ssize(a); i++)
    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];
  for(int i = 0; i < ssize(b); i++)
    b0[i] = b[i], b1[i] = b[i], b2[i] = b[i];
  vector<Mint0> x = ntt0.conv(a0, b0);
  vector<Mint1> y = ntt1.conv(a1, b1);
  vector<Mint2> z = ntt2.conv(a2, b2);
  vll res(size(x));
  constexpr uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();
  static const Mint1 im0 = 1 / Mint1(mod0);
  static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;
  static const ll m0 = mod0, m0m1 = m0 * mod1;
  for(int i = 0; i < ssize(x); i++) {
    int y0 = x[i].get();
    int y1 = (im0 * (y[i] - y0)).get();
    int y2 = (im0m1 * (z[i] - y0) - im1 * y1).get();
    res[i] = y0 + m0 * y1 + m0m1 * y2;
  }

  return res;
}

vll convolution_self_ll(vll a) {
  assert(2 * ssize(a) - 1 <= (1 << 23));
  using Mint0 = MontgomeryModInt<998244353>;
  using Mint1 = MontgomeryModInt<469762049>;
  using Mint2 = MontgomeryModInt<167772161>;
  NTT<23, 119, 3, Mint0> ntt0;
  NTT<26, 7, 3, Mint1> ntt1;
  NTT<25, 5, 3, Mint2> ntt2;
  const int sz = bit_ceil((ull)(2 * ssize(a) - 1));
  vector<Mint0> a0(sz);
  vector<Mint1> a1(sz);
  vector<Mint2> a2(sz);
  for(int i = 0; i < ssize(a); i++)
    a0[i] = a[i], a1[i] = a[i], a2[i] = a[i];
  ntt0.ntt(a0, false);
  ntt1.ntt(a1, false);
  ntt2.ntt(a2, false);
  for(int i = 0; i < sz; i++)
    a0[i] *= a0[i], a1[i] *= a1[i], a2[i] *= a2[i];
  ntt0.ntt(a0, true);
  ntt1.ntt(a1, true);
  ntt2.ntt(a2, true);
  vll res(sz);
  constexpr uint32_t mod0 = ntt0.get_mod(), mod1 = ntt1.get_mod();
  static const Mint1 im0 = 1 / Mint1(mod0);
  static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;
  static const ll m0 = mod0, m0m1 = m0 * mod1;
  for(int i = 0; i < sz; i++) {
    int y0 = a0[i].get();
    int y1 = (im0 * (a1[i] - y0)).get();
    int y2 = (im0m1 * (a2[i] - y0) - im1 * y1).get();
    res[i] = y0 + m0 * y1 + m0m1 * y2;
  }

  return res;
}

