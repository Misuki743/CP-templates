//////////////////////////////////////////////////
//template name: FFT
//author: __Shioko(Misuki)
//last update: 2022/04/06

const double PI = acos(-1);
vector<complex<double> > FFT(vector<complex<double> > a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }

  vector<complex<double> > a_odd(n / 2), a_even(n / 2);
  for(int i = 0; i < n; i += 2)
    a_even[i / 2] = a[i];
  for(int i = 0; i < n; i += 2)
    a_odd[i / 2] = a[i + 1];
  a_even = FFT(a_even);
  a_odd = FFT(a_odd);

  const complex<double> w_n = exp(complex<double>(0, 2 * PI) / (double)n);
  complex<double> w_k = 1;
  for(int i = 0; i < n / 2; i++, w_k = w_k * w_n)
    a[i] = a_even[i] + a_odd[i] * w_k;
  for(int i = n / 2; i < n; i++, w_k = w_k * w_n)
    a[i] = a_even[i - n / 2] + w_k * a_odd[i - n / 2];

  return a;
}

vector<complex<double> > IFFT(vector<complex<double> > a) {
  int n = a.size();
  if (n == 1) {
    return a;
  }

  const complex<double> w_n = exp(complex<double>(0, -2 * PI) / (double)n);
  vector<complex<double> > a_odd(n / 2), a_even(n / 2);
  for(int i = 0; i < n; i += 2)
    a_even[i / 2] = a[i];
  for(int i = 0; i < n; i += 2)
    a_odd[i / 2] = a[i + 1];
  a_even = IFFT(a_even);
  a_odd = IFFT(a_odd);
  complex<double> w_k = 1;
  for(int i = 0; i < n / 2; i++, w_k = w_k * w_n)
    a[i] = a_even[i] + a_odd[i] * w_k;
  for(int i = n / 2; i < n; i++, w_k = w_k * w_n)
    a[i] = a_even[i - n / 2] + w_k * a_odd[i - n / 2];
  
  return a;
}

vector<complex<double> > convolution(vector<complex<double> > a, vector<complex<double> > b) {
  for(int i = 0; i < a.size(); i++)
    a[i] *= b[i];
  return a;
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

  vector<complex<double> > cp = FFT(c), dp = FFT(d);
  cp = convolution(cp, dp);
  cp = IFFT(cp);

  for(int i = 0; i < cp.size(); i++)
    cp[i] /= n;

  vector<int> res(n, 0);
  for(int i = 0; i < n; i++)
    res[i] = cp[i].real() + 0.5;

  return res;
}
//////////////////////////////////////////////////
