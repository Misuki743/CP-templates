#define PROBLEM "https://yukicoder.me/problems/no/1344"

#include "../default/t.cpp"
#include "../graph/shortest_path/Floyd_Warshall.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<tuple<int, int, ll>> e(m);
  for(auto &[u, v, w] : e) {
    cin >> u >> v >> w;
    u--, v--;
  }

  for(auto vec : Floyd_Warshall<true>(n, e)) {
    ll sum = 0;
    for(ll x : vec)
      if (x != LLONG_MAX)
        sum += x;
    cout << sum << '\n';
  }

  return 0;
}
