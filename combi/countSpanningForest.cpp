//#include "modint/MontgomeryModInt.cpp"
//#include "linalg/matrixMint.cpp"

template<class Mint, bool directed = false>
Mint countSpanningForest(vector<tuple<int, int, Mint>> e, int n, vector<int> r = vector(1, 0)) {
  vector<int> id(n, 1);
  for(int x : r) id[x] = 0;
  id[0] -= 1;
  pSum(id);
  for(int x : r) id[x] = -1;

  matrix<Mint> M(n - ssize(r));
  for(auto [u, v, w] : e) {
    u = id[u], v = id[v];
    if (u != -1 and v != -1) {
      M[u][v] -= w;
      if constexpr (!directed) M[v][u] -= w;
    }
    if constexpr (!directed) if (u != -1) M[u][u] += w;
    if (v != -1) M[v][v] += w;
  }
  return M.det();
}
