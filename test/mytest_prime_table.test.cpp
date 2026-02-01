#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../numtheory/prime_table.cpp"

void a_plus_b() {
  int a, b; cin >> a >> b;
  cout << a + b << '\n';
}

template<int32_t N = 150>
void check_small() {
  if (N == 0) return;
  {
    prime_table<N> pt;

    auto is_prime = [&](int x) {
      if (x == 0 or x == 1) return false;
      for(int i = 2; i < x; i++)
        if (x % i == 0)
          return false;
      return true;
    };

    vi primes;
    for(int i = 0; i < N; i++) {
      assert(pt.is_prime(i) == is_prime(i));
      if (pt.is_prime(i))
        primes.emplace_back(i);
    }
    assert(pt.prime_array() == primes);
  }
  check_small<max(N - 1, 0)>();
}

bitset<(1 << 28)> is_prime = {};
template<int32_t N = (1 << 28)>
void check_power() {
  if (N == 1) return;
  {
    prime_table<N> pt;

    vi primes;
    for(int i = 0; i < N; i++) {
      assert(pt.is_prime(i) == is_prime[i]);
      if (pt.is_prime(i))
        primes.emplace_back(i);
    }
    assert(pt.prime_array() == primes);
  }
  check_power<max(N >> 1, 1)>();
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  check_small();

  is_prime.set();
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i < (1 << 28); i++)
    if (is_prime[i])
      for(int j = 2 * i; j < (1 << 28); j += i)
        is_prime[j] = false;
  check_power();

  a_plus_b();

  return 0;
}
