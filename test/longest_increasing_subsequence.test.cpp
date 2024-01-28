#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../default/t.cpp"
#include "../misc/LIS.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;

  auto lis = LIS<int, INT_MAX>(a);
  cout << ssize(lis) << '\n';
  cout << lis << '\n';

  return 0;
}
