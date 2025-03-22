template<uint32_t m_max = 1>
pair<vector<string>, vector<int>> eliminate(vector<string> M) {
  if (m_max < size(M[0]))
    return eliminate<min(m_max << 1, 1u << 13)>(std::move(M));
  int n = ssize(M), m = ssize(M[0]);
  vector<bitset<m_max>> N;
  for(auto &s : M) {
    ranges::reverse(s);
    N.emplace_back(s);
  }
  vector<int> prs;
  for(int r = 0, c = 0; r < n and c < m; c++) {
    int pr = r;
    while(pr < n and !N[pr][c]) pr++;
    if (pr == n) continue;
    prs.emplace_back(r);
    if (r != pr) swap(N[r], N[pr]);
    for(int i = 0; i < n; i++)
      if (i != r and N[i][c])
        N[i] ^= N[r];
    r++;
  }
  for(int i = 0; i < n; i++) {
    string s = N[i].to_string().substr(m_max - m);
    ranges::reverse(s);
    M[i] = s;
  }
  return pair(M, prs);
}
