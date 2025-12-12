auto quotient_floor_enumerate(int64_t x) {
  using i64 = int64_t;
  vector<i64> v, s;
  v.reserve(2 * (sqrt(x) + 32));
  s.reserve(2 * (sqrt(x) + 32));
  for(i64 i = x; i; ) {
    v.emplace_back(x / i);
    s.emplace_back(x / v.back() + 1);
    i = x / (v.back() + 1);
  }
  s.emplace_back(1);

  struct Data { int64_t quotient, l, r; };
  vector<Data> res(size(v));
  for(int i = 0; i < ssize(v); i++)
    res[i] = Data{v[i], s[i + 1], s[i]};

  return res;
}

auto quotient_ceil_enumerate(int64_t x) {
  using i64 = int64_t;
  vector<i64> v, s;
  v.reserve(2 * (sqrt(x) + 32));
  s.reserve(2 * (sqrt(x) + 32));
  for(i64 i = 1; ;) {
    v.emplace_back((x + i - 1) / i);
    s.emplace_back((x + v.back() - 1) / v.back());
    if (v.back() == 1) break;
    i = (x + v.back() - 2) / (v.back() - 1);
  }
  s.emplace_back(x + 1);

  struct Data { int64_t quotient, l, r; };
  vector<Data> res(size(v));
  for(int i = 0; i < ssize(v); i++)
    res[i] = Data{v[i], s[i], s[i + 1]};

  return res;
}
