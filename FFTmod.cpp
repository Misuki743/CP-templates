//////////////////////////////////////////////////
//template name: FFTmod
//author: __Shioko(Misuki)
//last update: 2022/04/07
//include template: FFT

const long long MOD = 1e9 + 7;
const long long SQRT = sqrt(MOD);
void sqrtDivide(vector<long long> &a, vector<long long> &b) {
  vector<long long> tmp = a;
  a.clear();
  b.clear();
  a.resize(tmp.size());
  b.resize(tmp.size());
  for(int i = 0; i < tmp.size(); i++) {
    a[i] = tmp[i] % SQRT;
    b[i] = tmp[i] / SQRT;
  }
}

vector<long long> multiplyMOD(vector<long long> a1, vector<long long> b1) {
  int mxSz = (int)a1.size() + (int)b1.size() - 1;
  int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));

  vector<long long> a2, b2;
  sqrtDivide(a1, a2);
  sqrtDivide(b1, b2);

  vector<complex<double> > c1(n), c2(n), d1(n), d2(n);
  for(int i = 0; i < n; i++)
    c1[i] = c2[i] = d1[i] = d2[i] = 0;
  for(int i = 0; i < a1.size(); i++)
    c1[i] = a1[i], c2[i] = a2[i];
  for(int i = 0; i < b1.size(); i++)
    d1[i] = b1[i], d2[i] = b2[i];

  FFT(c1, false);
  FFT(c2, false);
  FFT(d1, false);
  FFT(d2, false);

  vector<complex<double> > c1d1(n), c1d2(n), c2d1(n), c2d2(n);
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

  vector<long long> res(mxSz);
  for(int i = 0; i < mxSz; i++) {
    long long c1d1Val = (long long)(c1d1[i].real() + 0.5);
    long long c1d2Val = (long long)(c1d2[i].real() + 0.5);
    long long c2d1Val = (long long)(c2d1[i].real() + 0.5);
    long long c2d2Val = (long long)(c2d2[i].real() + 0.5);
    c1d1Val %= MOD;
    c1d2Val %= MOD;
    c2d1Val %= MOD;
    c2d2Val %= MOD;

    res[i] = ((((((c2d2Val * SQRT) % MOD) + (c1d2Val + c2d1Val)) * SQRT) % MOD) + c1d1Val) % MOD;
  }

  return res;
}
//////////////////////////////////////////////////
