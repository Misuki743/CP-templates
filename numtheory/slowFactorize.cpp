vector<pll> slowFactorize(ll val) {
  vector<pll> res;
  for(ll d = 2; d * d <= val; d++) {
    if (val % d != 0) continue;
    res.emplace_back(d, 0);
    while(val % d == 0) {
      val /= d;
      res.back().second++;
    }
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

vector<ll> factors(vector<pll> pf) {
  vector<ll> res(1, 1);
  for(auto [p, idx] : pf) {
    vector<ll> tmp;
    ull base = 1;
    for(int i = 0; i <= idx; i++, base *= p)
      for(ll X : res)
        tmp.emplace_back(X * base);
    res.swap(tmp);
  }
  return res;
}
