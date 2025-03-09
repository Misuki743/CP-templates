//#include<modint/MontgomeryModInt.cpp>
//#include<linalg/matrixMint.cpp>

template<class Mint>
pair<vector<Mint>, vector<vector<Mint>>> solve_linear(matrix<Mint> A, vector<Mint> b) {
  const int n = A.n(), m = A.m();
  assert(n == ssize(b));

  {
    matrix<Mint> tmp(n, m + 1);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        tmp[i][j] = A[i][j];
      tmp[i][m] = b[i];
    }
    A.swap(tmp);
  }

  vector<int> where(m, -1), inv_where(n, -1);
  for(int row = 0, col = 0; row < n and col < m; col++) {
    int p_row = -1;
    for(int i = row; i < n and p_row == -1; i++)
      if (A[i][col] != 0) 
        p_row = i;
    if (p_row == -1) continue;
    where[col] = row, inv_where[row] = col;
    for(int j = col; j <= m; j++)
      swap(A[row][j], A[p_row][j]);
    Mint r = 1 / Mint(A[row][col]);
    for(int j = col; j <= m; j++)
      A[row][j] *= r;
    for(int i = 0; i < n; i++) {
      if (i == row or A[i][col] == 0) continue;
      Mint s = A[i][col];
      for(int j = col; j <= m; j++)
        A[i][j] -= A[row][j] * s;
    }
    row++;
  }

  vector<Mint> ans(m);
  for(int i = 0; i < m; i++)
    if (where[i] != -1)
      ans[i] = A[where[i]][m];

  for(int i = 0; i < n; i++) {
    Mint s = -A[i][m];
    for(int j = 0; j < m; j++)
      s += ans[j] * A[i][j];
    if (s != 0)
      return {};
  }

  vector<vector<Mint>> basis;
  for(int col = 0, last_row = 0; col < m; col++) {
    if (where[col] != -1) {
      last_row = where[col];
    } else {
      basis.emplace_back(m);
      basis.back()[col] = 1;
      for(int i = 0; i <= last_row; i++)
        basis.back()[inv_where[i]] = -A[i][col];
    }
  }

  return make_pair(ans, basis);
}
