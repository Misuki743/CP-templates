#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../default/t.cpp"
#include "../graph/misc/2sat.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(0);

  string p, cnf; cin >> p >> cnf;
  int n, m; cin >> n >> m;

  TwoSat ts(n);
  while(m--) {
    int a, b, c; cin >> a >> b >> c;
    a = (a > 0 ? a - 1 : ~(-(a + 1)));
    b = (b > 0 ? b - 1 : ~(-(b + 1)));
    ts.either(a, b);
  }

  if (ts.solve()) {
    cout << "s SATISFIABLE\n";
    cout << "v ";
    for(int i = 0; i < n; i++)
      cout << (ts.values[i] ? i + 1 : -(i + 1)) << ' ';
    cout << 0 << '\n';
  } else {
    cout << "s UNSATISFIABLE\n";
  }

  return 0;
}
