#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../numtheory/linear_sieve.cpp"

vc<pii> prime_factorize(int x) {
  vc<pii> v;
  int x0 = x;
  for(int d = 2; d <= x0; d++) {
    if (x % d == 0) {
      int f = 0;
      while(x % d == 0)
        x /= d, f++;
      v.emplace_back(d, f);
    }
  }
  return v;
}

vi prime_factor(int x) {
  vi v;
  int x0 = x;
  for(int d = 2; d <= x0; d++) {
    if (x % d == 0) {
      while(x % d == 0)
        x /= d;
      v.eb(d);
    }
  }
  return v;
}

vi divisor(int x) {
  vi v;
  for(int d = 1; d <= x; d++)
    if (x % d == 0)
      v.eb(d);
  return v;
}

int mpf[1 << 10];

template<int32_t sz = 64>
void check_small() {
  if (sz == 0) return;
  check_small<max(sz - 1, 0)>();
  auto ls = linear_sieve<sz>();
  for(int i = 0; i < sz; i++)
    assert(mpf[i] == ls.mpf[i]);
  for(int i = 1; i < sz; i++) {
    assert(ls.prime_factorize(i) == prime_factorize(i));
    assert(ls.prime_factor(i) == prime_factor(i));
    assert(ls.divisor(i) == divisor(i));
  }
}

template<int32_t sz = (1 << 10)>
void check_power() {
  if (sz == 0) return;
  check_power<max(sz >> 1, 0)>();
  auto ls = linear_sieve<sz>();
  for(int i = 0; i < sz; i++)
    assert(mpf[i] == ls.mpf[i]);
  for(int i = 1; i < sz; i++) {
    assert(ls.prime_factorize(i) == prime_factorize(i));
    assert(ls.prime_factor(i) == prime_factor(i));
    assert(ls.divisor(i) == divisor(i));
  }
}

void a_plus_b() {
  int x, y; cin >> x >> y;
  cout << x + y << '\n';
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  for(int x = 2; x < (1 << 10); x++)
    mpf[x] = prime_factor(x)[0];

  check_small();
  check_power();
  a_plus_b();

  return 0;
}
