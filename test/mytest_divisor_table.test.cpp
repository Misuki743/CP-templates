#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../numtheory/divisor_table.cpp"

template<int32_t sz = 128>
void test_small() {
  if (sz == 0) return;
  test_small<max(sz - 1, 0)>();

  divisor_table<sz> dt;
  for(int x = 1; x < sz; x++) {
    vi divisor;
    for(int d = 1; d <= x; d++)
      if (x % d == 0)
        divisor.emplace_back(d);
    assert(divisor == dt.divisor(x));
  }
}

template<int32_t sz = (1 << 12)>
void test_power() {
  if (sz == 0) return;
  test_power<max(sz >> 1, 0)>();

  divisor_table<sz> dt;
  for(int x = 1; x < sz; x++) {
    vi divisor;
    for(int d = 1; d <= x; d++)
      if (x % d == 0)
        divisor.emplace_back(d);
    assert(divisor == dt.divisor(x));
  }
}

void a_plus_b() {
  int x, y; cin >> x >> y;
  cout << x + y << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  test_small();
  test_power();
  a_plus_b();

  return 0;
}
