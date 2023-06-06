//////////////////////////////////////////////////
//template name: FPS
//author: __Shioko(Misuki)
//last update: 2023/03/28
//include: mint with NTT-able MOD if using NTT(convolution/log/exp/pow),
//           or change NTT with high precision FFT
//verify: Library Checker - Inv of Formal Power Series
//        Library Checker - Exp of Formal Power Series
//        Library Checker - Log of Formal Power Series
//        Library Checker - Pow of Formal Power Series
//        Library Checker - Convolution
//
//some theorem about FPS:
//
//Lagrange inversion theorem: [x^n]G(x) = 1/n [x^{-1}] F(x)^{-1} for F(x) being the composition inversion of G(x)

bool init_NTT = false;

struct FPS : vector<mint> {

  using vector<mint>::vector;

  static const int K = 23, C = 119, R = 3;
  static mint w[K + 1], w_inv[K + 1];
  static bool init_NTT;

  void NTT(bool inverse) {
    if (!init_NTT) {
      w[K] = mint(R).POW(C);
      for(int i = K - 1; i >= 0; i--)
        w[i] = w[i + 1] * w[i + 1];
      for(int i = 0; i <= K; i++)
        w_inv[i] = 1 / w[i];

      init_NTT = true;
    }
    int n = this -> size();
    FPS tmp = *this;
    for(int i = 0; i < this -> size(); i++) {
      int idx = 0;
      int lgn = __lg(n);
      for(int j = lgn - 1; j >= 0; j--)
        idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);
      (*this)[idx] = tmp[i];
    }

    for(int l = 2; l <= n; l <<= 1) {
      mint w_l = (inverse ? w_inv[__lg(l)] : w[__lg(l)]);
      for(int i = 0; i < n; i += l) {
        mint w = 1;
        for(int j = 0; j < (l >> 1); j += 1) {
          mint t = (*this)[i + j + l / 2] * w;
          (*this)[i + j + l / 2] = (*this)[i + j] - t;
          (*this)[i + j] = (*this)[i + j] + t;
          w *= w_l;
        }
      }
    }

    if (inverse) {
      mint INV = mint(1) / n;
      for(int i = 0; i < n; i++)
        (*this)[i] *= INV;
    }
  }
  FPS& operator+=(FPS b) {
    if (this -> size() < b.size()) this -> resize(b.size(), 0);
    for(int i = 0; i < b.size(); i++)
      (*this)[i] += b[i];
    return *this;
  }
  FPS& operator-=(FPS b) {
    if (this -> size() < b.size()) this -> resize(b.size(), 0);
    for(int i = 0; i < b.size(); i++)
      (*this)[i] -= b[i];
    return *this;
  }
  FPS& operator*=(FPS b) {
    int mxSz = (int)this -> size() + (int)b.size() - 1;
    int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));

    this -> resize(n, 0);
    b.resize(n, 0);

    this -> NTT(false);
    b.NTT(false);
    for(int i = 0; i < n; i++)
      (*this)[i] *= b[i];
    this -> NTT(true);
    this -> resize(mxSz);
    return *this;
  }
  //use this if the problem author just hate 998244353
  /*
  FPS& operator*=(FPS b) {
    const long long SQRT = sqrt(mint::MOD);
    auto sqrtDivide = [&](FPS &a, FPS &b) {
      FPS tmp = a;
      a.clear();
      b.clear();
      a.resize(tmp.size());
      b.resize(tmp.size());
      for(int i = 0; i < tmp.size(); i++)
        a[i] = tmp[i]._val % SQRT, b[i] = tmp[i]._val / SQRT;
    };

    int mxSz = (int)this -> size() + (int)b.size() - 1;
    int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));

    FPS a2, b2;
    sqrtDivide((*this), a2);
    sqrtDivide(b, b2);

    vector<complex<double>> c1(n), c2(n), d1(n), d2(n);
    for(int i = 0; i < n; i++)
      c1[i] = c2[i] = d1[i] = d2[i] = 0;
    for(int i = 0; i < this -> size(); i++)
      c1[i] = (*this)[i]._val, c2[i] = a2[i]._val;
    for(int i = 0; i < b.size(); i++)
      d1[i] = b[i]._val, d2[i] = b2[i]._val;

    auto FFT = [&](vector<complex<double>> &a, bool inverse) -> void {
      const double PI = acos(-1);
      vector<complex<double> > w(2, 1), w_inv(2, 1);
      int n = a.size();

      if (w.size() < n) {
        int lgSz = __lg(w.size()), lgN = __lg(n);
        w.resize(n);
        w_inv.resize(n);
        for(int i = lgSz; i < lgN; i++) {
          complex<double> w_k = std::exp(complex<double>(0, PI / (double)(1 << i)));
          complex<double> w_k_inv = std::exp(complex<double>(0, -PI / (double)(1 << i)));
          for(int j = 1 << i; j < (1 << (i + 1)); j++) {
            w[j] = (j & 1) ? w[j >> 1] * w_k : w[j >> 1];
            w_inv[j] = (j & 1) ? w_inv[j >> 1] * w_k_inv : w_inv[j >> 1];
          }
        }
      }

      vector<complex<double>> tmp = a;
      for(int i = 0; i < a.size(); i++) {
        int idx = 0, lgn = __lg(n);
        for(int j = lgn - 1; j >= 0; j--)
          idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);
        a[idx] = tmp[i];
      }

      for(int l = 2; l <= n; l <<= 1) {
        for(int i = 0; i < n; i += l) {
          for(int j = 0; j < (l >> 1); j++) {
            complex<double> w_j = (inverse ? w_inv[(l >> 1) + j] : w[(l >> 1) + j]);
            complex<double> t = a[i + j + l / 2] * w_j;
            a[i + j + l / 2] = a[i + j] - t;
            a[i + j] = a[i + j] + t;
          }
        }
      }

      if (inverse)
        for(int i = 0; i < n; i++)
          a[i] = a[i] / (double)n;
    };

    FFT(c1, false);
    FFT(c2, false);
    FFT(d1, false);
    FFT(d2, false);

    vector<complex<double>> c1d1(n), c1d2(n), c2d1(n), c2d2(n);
    for(int i = 0; i < n; i++) {
      c1d1[i] = c1[i] * d1[i];
      c1d2[i] = c1[i] * d2[i];
      c2d1[i] = c2[i] * d1[i];
      c2d2[i] = c2[i] * d2[i];
    }

    FFT(c1d1, true);
    FFT(c1d2, true);
    FFT(c2d1, true);
    FFT(c2d2, true);
  
    this -> resize(mxSz);
    for(int i = 0; i < mxSz; i++) {
      mint c1d1v = (long long)round(c1d1[i].real());
      mint c1d2v = (long long)round(c1d2[i].real());
      mint c2d1v = (long long)round(c2d1[i].real());
      mint c2d2v = (long long)round(c2d2[i].real());
      (*this)[i] = (c2d2v * SQRT + c1d2v + c2d1v) * SQRT + c1d1v;
    }

    return (*this);
  }
  */
  FPS& operator*=(mint b) {
    for(int i = 0; i < this -> size(); i++)
      (*this)[i] *= b;
    return (*this);
  }

  FPS& operator/=(mint b) {
    b = mint(1) / b;
    for(int i = 0; i < this -> size(); i++)
      (*this)[i] *= b;
    return (*this);
  }

  FPS integral() {
    vector<mint> Inv(this -> size() + 1);
    Inv[1] = 1;
    for(int i = 2; i < Inv.size(); i++)
      Inv[i] = (mint::MOD - mint::MOD / i) * Inv[mint::MOD % i];
    FPS Q(this -> size() + 1, 0);
    for(int i = 0; i < this -> size(); i++)
      Q[i + 1] = (*this)[i] * Inv[i + 1];
    
    return Q;
  }

  FPS derivative() {
    assert(!this -> empty());

    FPS Q((int)(this -> size()) - 1);
    for(int i = 1; i < this -> size(); i++)
      Q[i - 1] = (*this)[i] * i;

    return Q;
  }

  mint eval(mint x) {
    mint base = 1, res = 0;
    for(int i = 0; i < this -> size(); i++, base *= x)
      res += (*this)[i] * base;
    return res;
  }

  FPS inv(int k) { // 1 / FPS (mod x^k)
    assert(!this -> empty() and (*this)[0] != 0);

    FPS Q(1, 1 / (*this)[0]);
    for(int i = 1; (1 << (i - 1)) < k; i++) {
      FPS P = (*this);
      P.resize(1 << i, 0);
      Q = Q * (FPS(1, 2) - P * Q);
      Q.resize(1 << i, 0);
    }
    Q.resize(k);

    return Q;
  }

  FPS log(int k) {
    assert(!this -> empty() and (*this)[0] == 1);

    FPS Q = *this;
    Q = (Q.derivative() * Q.inv(k));
    Q.resize(k - 1);
    return Q.integral();
  }

  FPS exp(int k) {
    assert(!this -> empty() and (*this)[0] == 0);

    FPS Q(1, 1);
    for(int i = 1; (1 << (i - 1)) < k; i++) {
      FPS P = (*this);
      P.resize(1 << i, 0);
      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));
      Q.resize(1 << i, 0);
    }
    Q.resize(k);

    return Q;
  }

  FPS pow(long long idx, int k) {
    if (idx == 0) {
      FPS res(k, 0);
      res[0] = 1;
      return res;
    }
    for(int i = 0; i < this -> size() and i * idx < k; i++) {
      if ((*this)[i] != 0) {
        mint Inv = 1 / (*this)[i];
        FPS Q((int)this -> size() - i);
        for(int j = i; j < this -> size(); j++)
          Q[j - i] = (*this)[j] * Inv;
        Q = (Q.log(k) * idx).exp(k);
        FPS Q2(k, 0);
        mint Pow = (*this)[i].POW(idx);
        for(int j = 0; j + i * idx < k; j++)
          Q2[j + i * idx] = Q[j] * Pow;
        return Q2;
      }
    } 
    return FPS(k, 0);
  }

  friend FPS operator+(FPS a, FPS b) { return a += b; }
  friend FPS operator-(FPS a, FPS b) { return a -= b; }
  friend FPS operator*(FPS a, FPS b) { return a *= b; }
  friend FPS operator*(FPS a, mint b) { return a *= b; }
  friend FPS operator/(FPS a, mint b) { return a /= b; }
};

bool FPS::init_NTT = false;
mint FPS::w[K + 1];
mint FPS::w_inv[K + 1];
//////////////////////////////////////////////////
