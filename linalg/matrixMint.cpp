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
      for(int k = 0; k < m(); k++)
        for(int j = 0; j < b.m(); j++)
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

  tuple<matrix, vector<int>, int> eliminate() {
    int sgn = 1;
    matrix M = *this;
    vector<int> pivot_row;
    for(int row = 0, col = 0; row < n() and col < m(); col++) {
      int p_row = -1;
      for(int i = row; i < n() and p_row == -1; i++)
        if (M[i][col] != 0) 
          p_row = i;
      if (p_row == -1) continue;
      pivot_row.emplace_back(row);
      if (row != p_row) {
        for(int j = col; j < m(); j++)
          swap(M[row][j], M[p_row][j]);
        sgn *= -1;
      }
      for(int i = 0; i < n(); i++) {
        if (i == row or M[i][col] == 0) continue;
        Mint s = M[i][col] / M[row][col];
        for(int j = col; j < m(); j++)
          M[i][j] -= M[row][j] * s;
      }
      row++;
    }
    return {M, pivot_row, sgn};
  }

  Mint det() {
    assert(n() == m());
    auto [M, pr, sgn] = eliminate();
    if (ssize(pr) != n()) {
      return Mint(0);
    } else {
      Mint d = sgn;
      for(int i = 0; i < n(); i++)
        d *= M[i][i];
      return d;
    }
  }

  int rank() {
    return get<1>(eliminate()).size();
  }

  pair<bool, matrix> inv() {
    assert(n() == m());
    matrix M(n(), 2 * n());
    for(int i = 0; i < n(); i++) {
      for(int j = 0; j < n(); j++)
        M[i][j] = (*this)[i][j];
      M[i][n() + i] = 1;
    }
    matrix tmp = get<0>(M.eliminate());
    matrix MI(n(), n());
    for(int i = 0; i < n(); i++) {
      if (tmp[i][i] == 0) return {false, matrix(0, 0)};
      Mint r = tmp[i][i].inverse();
      for(int j = 0; j < n(); j++)
        MI[i][j] = tmp[i][j + n()] * r;
    }
    return {true, MI};
  }

  pair<vector<Mint>, matrix> solve_linear(vector<Mint> b) {
    assert(n() == ssize(b));

    matrix M(n(), m() + 1);
    for(int i = 0; i < n(); i++) {
      for(int j = 0; j < m(); j++)
        M[i][j] = (*this)[i][j];
      M[i][m()] = b[i];
    }

    auto [N, pr, _] = M.eliminate();
    vector<Mint> x(m());
    vector<int> where(m(), -1), inv_where(m(), -1);
    for(int row : pr) {
      int col = 0;
      while(N[row][col] == 0) col++;
      if (col < m())
        where[col] = row, inv_where[row] = col;
    }

    for(int i = 0; i < m(); i++)
      if (where[i] != -1)
        x[i] = N[where[i]][m()] / N[where[i]][i];

    for(int i = 0; i < n(); i++) {
      Mint s = -N[i][m()];
      for(int j = 0; j < m(); j++)
        s += x[j] * N[i][j];
      if (s != Mint(0))
        return {vector<Mint>(), matrix(0)};
    }

    matrix basis(m() - ssize(pr), m());
    for(int col = 0, last_row = 0, k = 0; col < m(); col++) {
      if (where[col] != -1) {
        last_row = where[col];
      } else {
        basis[k][col] = 1;
        for(int i = 0; i <= last_row; i++)
          basis[k][inv_where[i]] = -N[i][col] / N[i][inv_where[i]];
        k++;
      }
    }

    return {x, basis};
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
