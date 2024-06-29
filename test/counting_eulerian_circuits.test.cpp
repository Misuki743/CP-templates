#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"
#include "../combi/countSpanningForest.cpp"
#include "../combi/countEulerianCircuit.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e) cin >> u >> v;

  cout << countEulerianCircuit<mint>(e, n) << '\n';

  return 0;
}
