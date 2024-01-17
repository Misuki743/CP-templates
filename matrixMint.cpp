/**
 * template name: matrixMint
 * author: Misuki
 * include: mint
 * reference: kactl (for det() and inv())
 * last update: 2024/01/17
 * verify: Library Checker - Matrix Product
 * verify: Library Checker - Determinant of Matrix
 * verify: Library Checker - Inverse Matrix
 * verify: Library Checker - Pow of Matrix
 */

template<class Mint>
struct matrix : vector<vector<Mint>> {
  matrix(int n, int m) : vector<vector<Mint>>(n, vector<Mint>(m, 0)) {}
  matrix(int n) : vector<vector<Mint>>(n, vector<Mint>(n, 0)) {}

  int n() const { return ssize(*this); }
  int m() const { return ssize((*this)[0]); }

  static matrix I(int n) {
    auto res = matrix(n, n);
    for(int i = 0; i < n; i++)
      res[i][i] = 1;
    return res;
  }

  matrix& operator+=(const matrix &b) {
    assert(n() == b.n());
    assert(m() == b.m());
    for(int i = 0; i < n(); i++)
      for(int j = 0; j < m(); j++)
        (*this)[i][j] += b[i][j];
    return *this;
  }

  matrix& operator-=(const matrix &b) {
    assert(n() == b.n());
    assert(m() == b.m());
    for(int i = 0; i < n(); i++)
      for(int j = 0; j < m(); j++)
        (*this)[i][j] -= b[i][j];
    return *this;
  }

  matrix& operator*=(const matrix &b) {
    assert(m() == b.n());
    auto res = matrix(n(), b.m());
    for(int i = 0; i < n(); i++)
      for(int j = 0; j < b.m(); j++)
        for(int k = 0; k < m(); k++)
          res[i][j] += (*this)[i][k] * b[k][j];
    this -> swap(res);
    return *this;
  }

  matrix pow(ll k) const {
    assert(n() == m());
    auto res = I(n()), base = *this;
    while(k) {
      if (k & 1) res *= base;
      base *= base, k >>= 1;
    }
    return res;
  }

  Mint det() const {
    Mint res = 1;
    auto a = *this;
    for(int i = 0; i < n(); i++) {
      for(int j = i + 1; j < m(); j++) {
        while(a[j][i] != 0) {
          Mint t = a[i][i] / a[j][i];
          if (t != 0)
            for(int k = i; k < n(); k++)
              a[i][k] -= a[j][k] * t;
          swap(a[i], a[j]);
          res = -res;
        }
      }
      res *= a[i][i];
      if (res == 0) return 0;
    }
    return res;
  }

  matrix inv() const {
    assert(n() == m());
    matrix a = *this, tmp = I(n());
    vector<int> col(n());
    for(int i = 0; i < n(); i++) col[i] = i;

    for(int i = 0; i < n(); i++) {
      int r = i, c = i;
      for(int j = i; j < n(); j++) {
        for(int k = i; k < n(); k++) {
          if (a[j][k] != 0) {
            r = j, c = k;
            goto found;
          }
        }
      }
      return matrix(0);
      found:
      a[i].swap(a[r]), tmp[i].swap(tmp[r]);
      for(int j = 0; j < n(); j++)
        swap(a[j][i], a[j][c]), swap(tmp[j][i], tmp[j][c]);
      swap(col[i], col[c]);
      Mint v = 1 / a[i][i];
      for(int j = i + 1; j < n(); j++) {
        Mint f = a[j][i] * v;
        a[j][i] = 0;
        for(int k = i + 1; k < n(); k++)
          a[j][k] -= f * a[i][k];
        for(int k = 0; k < n(); k++)
          tmp[j][k] -= f * tmp[i][k];
      }
      for(int j = i + 1; j < n(); j++) 
        a[i][j] *= v;
      for(int j = 0; j < n(); j++) 
        tmp[i][j] *= v;
      a[i][i] = 1;
    }

    for(int i = n() - 1; i > 0; i--) {
      for(int j = 0; j < i; j++) {
        Mint v = a[j][i];
        for(int k = 0; k < n(); k++)
          tmp[j][k] -= v * tmp[i][k];
      }
    }

    for(int i = 0; i < n(); i++)
      for(int j = 0; j < n(); j++)
        a[col[i]][col[j]] = tmp[i][j];
    return a;
  }

  matrix operator-() { return matrix(n(), m()) - (*this); }
  
  friend matrix operator+(matrix a, matrix b) { return a += b; }
  friend matrix operator-(matrix a, matrix b) { return a -= b; }
  friend matrix operator*(matrix a, matrix b) { return a *= b; }
  
  friend ostream& operator<<(ostream& os, const matrix& b) {
    for(int i = 0; i < b.n(); i++) {
      os << '\n';
      for(int j = 0; j < b.m(); j++)
        os << b[i][j] << ' ';
    }
    return os;
  }
  friend istream& operator>>(istream& is, matrix& b) {
    for(int i = 0; i < b.n(); i++)
      for(int j = 0; j < b.m(); j++)
        is >> b[i][j];
    return is;
  }
};
