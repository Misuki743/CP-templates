#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../numtheory/factorize_sqrt.cpp"
#include "../factorize_pollard_rho.cpp"

void check(int64_t x) {
  vc<int64_t> pf;
  for(auto p : factor(x))
    pf.eb(p);
  ranges::sort(pf);
  vc<pair<int64_t, int64_t>> pf2;
  for(int i = 0, j = 0; i < ssize(pf); i = j) {
    while(j < ssize(pf) and pf[i] == pf[j]) j++;
    pf2.emplace_back(pf[i], j - i);
  }
  pf.resize(unique(pf.begin(), pf.end()) - pf.begin());
  vc<int64_t> divisor;
  auto dfs = [&](int i, int64_t prod, auto &self) -> void {
    if (i == ssize(pf)) {
      divisor.emplace_back(prod);
      return;
    }
    for(int j = 0; j <= pf2[i].second; j++) {
      if (j) prod *= pf2[i].first;
      self(i + 1, prod, self);
    }
  };
  dfs(0, 1, dfs);
  ranges::sort(divisor);
  
  assert(pf2 == prime_factorize_sqrt(x));
  assert(pf == prime_factor_sqrt(x));
  assert(divisor == divisor_sqrt(x));
}

void check_small() {
  for(int64_t x = 1; x < (1 << 10); x++)
    check(x);
}

void check_large() {
  mt19937_64 rng(clock);
  for(int64_t l = (1ll << 10); l < (1ll << 53); l <<= 1)
    for(int i = 0; i < 10; i++)
      check(rng() % l + l);
}

void a_plus_b() {
  int x, y; cin >> x >> y;
  cout << x + y << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  check_small();
  check_large();
  a_plus_b();

  return 0;
}
