vector<pair<int64_t, int64_t>> prime_factorize_sqrt(int64_t x) {
  using i64 = int64_t;
  vector<pair<i64, i64>> res;
  for(i64 d = 2; d * d <= x; d++) {
    if (x % d != 0) continue;
    res.emplace_back(d, 0ll);
    while(x % d == 0)
      x /= d, res.back().second++;
  }
  if (x != 1) res.emplace_back(x, 1);
  return res;
}

vector<int64_t> prime_factor_enumerate_sqrt(int64_t x) {
  using i64 = int64_t;
  vector<i64> res;
  for(i64 d = 2; d * d <= x; d++) {
    if (x % d != 0) continue;
    res.emplace_back(d);
    while(x % d == 0)
      x /= d;
  }
  if (x != 1) res.emplace_back(x);
  return res;
}

vector<int64_t> divisor_enumerate_sqrt(int64_t x, bool sorted = true) {
  using i64 = int64_t;
  vector<i64> divisor = {1};
  for(auto [p, f] : prime_factorize_sqrt(x)) {
    vector<i64> nxt;
    nxt.reserve(ssize(divisor) * (f + 1));
    uint64_t q = 1;
    for(int i = 0; i <= f; i++, q *= p)
      for(i64 d : divisor)
        nxt.emplace_back(d * q);
    divisor.swap(nxt);
  }
  if (sorted)
    ranges::sort(divisor);
  return divisor;
}
