#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"

#include "../default/t.cpp"
#include "../linalg/xorBasis.cpp"

template<int size = 1>
void solve(int n, int m) {
  if (size < m) {
    solve<min(2 * size, 1 << 24)>(n, m);
    return;
  }
  xorBasis<size> b;
  while(n--) {
    string s; cin >> s;
    b.insert(bitset<size>(s), 0);
  }
  int rank = 0;
  for(int i = 0; i < size; i++)
    rank += b.basis[i] != nullptr;
  cout << rank << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  solve(n, m);

  return 0;
}
