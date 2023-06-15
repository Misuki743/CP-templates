/**
 * template name: matrix
 * author: Misuki
 * last update: 2022/08/21
 * include: mint
 */

using matrix = vector<vector<mint>>;

matrix mul(matrix a, matrix b) {
  int n = a.size(), m = b[0].size();
  matrix res(n, vector<mint>(m));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      for(int k = 0; k < b.size(); k++)
        res[i][j] += a[i][k] * b[k][j];
  return res;
}

matrix pow(matrix a, int index) {
  matrix res(a.size(), vector<mint>(a.size()));
  for(int i = 0; i < a.size(); i++)
    res[i][i] = 1;
  while(index) {
    if (index & 1)
      res = mul(res, a);
    a = mul(a, a), index >>= 1;
  }
  return res;
}
