/**
 * template name: floorCeilSum
 * author: Misuki
 * last update: 2024/01/11
 * note: g = floor(x / val) is the greatest value s.t. floor(x / g) = val for floor sum, 
 *       g = ceil(x / val) is the least value s.t. ceil(x / g) = val for ceil sum. 
 * verify: brute forced x <= 1e4
 *         Library Checker - Enumerate Quotients
 */

template<class T>
vector<array<T, 3>> calc_floor(T x) {
  vector<T> v, rng;
  for(T i = x; i; ) {
    T val = x / i;
    v.emplace_back(val);
    rng.emplace_back(x / val);
    i = x / (val + 1);
  }
  rng.emplace_back(0);

  vector<array<T, 3>> res;
  for(int i = 0; i < ssize(v); i++)
    res.push_back({v[i], rng[i + 1] + 1, rng[i]}); //{q, [l, r]}

  return res;
}

template<class T>
vector<array<T, 3>> calc_ceil(T x) {
  vector<T> v, rng;
  for(T i = 1; ; ) {
    T val = (x + i - 1) / i;
    v.emplace_back(val);
    rng.emplace_back((x + val - 1) / val);
    if (val == 1)
      break;
    i = (x + val - 2) / (val - 1);
  }
  rng.emplace_back(x + 1);

  vector<array<T, 3>> res;
  for(int i = 0; i < ssize(v); i++)
    res.push_back({v[i], rng[i], rng[i + 1] - 1}); //{q, [l, r]}

  return res;
}
