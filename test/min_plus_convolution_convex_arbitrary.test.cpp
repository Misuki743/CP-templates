#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include "../default/t.cpp"
#include "../poly/min_plus_convolution.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for(int &x : a) cin >> x;
  for(int &x : b) cin >> x;

  cout << min_plus_convolution(a, b) << '\n';

  return 0;
}

