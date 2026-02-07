template<int32_t C>
struct linear_sieve {
  array<int, C> mpf = {};
  vi prime;
  linear_sieve() {
    if (C > 2)
      iota(mpf.begin() + 2, mpf.end(), 2);
    for(int i = 2; i < C; i++) {
      if (mpf[i] == i)
        prime.emplace_back(i);
      for(int64_t p : prime) {
        if (p > mpf[i] or p * i >= C)
          break;
        mpf[p * i] = p;
      }
    }
  }

  vc<pii> prime_factorize(int x) {
    vc<pii> r;
    while(mpf[x]) {
      r.emplace_back(mpf[x], 0);
      while(x % r.back().first == 0)
        x /= r.back().first, r.back().second++;
    }
    return r;
  }

  vi prime_factor(int x) {
    vi r;
    while(mpf[x]) {
      r.emplace_back(mpf[x]);
      while(x % r.back() == 0)
        x /= r.back();
    }
    return r;
  }

  vi divisor(int x, bool sorted = true) {
    vi divisor = {1};
    for(auto [p, f] : prime_factorize(x)) {
      vi nxt;
      nxt.reserve(ssize(divisor) * (f + 1));
      for(int64_t i = 0, q = 1; i <= f; i++, q *= p)
        for(int d : divisor)
          nxt.emplace_back(d * q);
      divisor.swap(nxt);
    }
    if (sorted)
      ranges::sort(divisor);
    return divisor;
  }
};
