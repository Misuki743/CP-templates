const double PI = acos(-1);
vector<complex<double> > w(2, 1), w_inv(2, 1);

void FFT(vector<complex<double> > &a, bool inverse) {
  int n = a.size();

  if (w.size() < n) {
    int lgSz = __lg((int)w.size());
    int lgN = __lg(n);
    w.resize(n);
    w_inv.resize(n);
    for(int i = lgSz; i < lgN; i++) {
      complex<double> w_k = exp(complex<double>(0, PI / (double)(1 << i)));
      complex<double> w_k_inv = exp(complex<double>(0, -PI / (double)(1 << i)));
      for(int j = 1 << i; j < (1 << (i + 1)); j++) {
        w[j] = (j & 1) ? w[j >> 1] * w_k : w[j >> 1]; 
        w_inv[j] = (j & 1) ? w_inv[j >> 1] * w_k_inv : w_inv[j >> 1];
      }
    }
  }

  vector<complex<double> > tmp = a;
  for(int i = 0; i < a.size(); i++) {
    int idx = 0;
    int lgn = __lg(n);
    for(int j = lgn - 1; j >= 0; j--) {
      idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);
    }
    a[idx] = tmp[i];
  }

  for(int l = 2; l <= n; l <<= 1) {
    for(int i = 0; i < n; i += l) {
      for(int j = 0; j < (l >> 1); j += 1) {
        complex<double> w_j = (inverse ? w_inv[(l >> 1) + j] : w[(l >> 1) + j]);
        complex<double> t = a[i + j + l / 2] * w_j;
        a[i + j + l / 2] = a[i + j] - t;
        a[i + j] = a[i + j] + t;
      }
    } 
  } 

  if (inverse) {
    for(int i = 0; i < n; i++)
      a[i] = a[i] / (double)n;
  }
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int mxSz = (int)a.size() + (int)b.size() - 1;
  int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));

  vector<complex<double> > c(n), d(n);
  for(int i = 0; i < n; i++)
    c[i] = d[i] = 0;
  for(int i = 0; i < a.size(); i++)
    c[i] = a[i];
  for(int i = 0; i < b.size(); i++)
    d[i] = b[i];

  FFT(c, false);
  FFT(d, false);

  for(int i = 0; i < n; i++)
    c[i] = c[i] * d[i];

  FFT(c, true);

  vector<int> res(mxSz);
  for(int i = 0; i < mxSz; i++)
    res[i] = round(c[i].real());

  return res;
}
