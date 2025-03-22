//rank: size(prs), det: full_rank ? sgn : 0
//inv(LI): L == identity ? R : -1
//Ax=b(Ab): b is pivot col ? -1 : x[c] = M[prs[i]].back
//where c is pivot column of row prs[i]

const int mod = 998244353;
auto eliminate(vector<vector<int>> M) {
  int n = ssize(M), m = M.empty() ? 0 : ssize(M[0]), sgn = 1;
  vector<int> prs;
  for(int r = 0, c = 0; r < n and c < m; c++) {
    int pr = r;
    while(pr < n and M[pr][c] == 0) pr++;
    if (pr == n) continue;
    prs.emplace_back(r);
    if (r != pr)
      M[r].swap(M[pr]), sgn = (mod - sgn) % mod;
    ll inv = 1, b = M[r][c];
    sgn = (ll)sgn * b % mod;
    for(int i = 0; i < 30; i++, b = b * b % mod)
      if ((mod - 2) >> i & 1)
        inv = inv * b % mod;
    for(int i = 0; i < m; i++)
      M[r][i] = M[r][i] * inv % mod;
    for(int i = 0; i < n; i++) {
      if (i == r or M[i][c] == 0) continue;
      ll x = M[i][c];
      for(int j = c; j < m; j++)
        M[i][j] = (M[i][j] + mod - M[r][j] * x % mod) % mod;
    }
    r++;
  }
  return tuple(M, prs, sgn);
}
