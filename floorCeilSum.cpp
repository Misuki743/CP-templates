//////////////////////////////////////////////////
//template name: floorCeilSum
//author: __Shioko(Misuki)
//last update: 2023/06/06
//note: g = floor(x / val) is the greatest value s.t. floor(x / g) = val for floor sum, 
//      g = ceil(x / val) is the least value s.t. ceil(x / g) = val for ceil sum. 
//verify: brute force x <= 1e4

vector<array<int, 3>> calc_floor(int x) {
  vector<int> v, rng;
  for(int i = x; i; ) {
    int val = x / i;
    v.emplace_back(val);
    rng.emplace_back(x / val);
    i = x / (val + 1);
  }
  rng.emplace_back(0);

  vector<array<int, 3>> res;
  for(int i = 0; i < v.size(); i++)
    res.push_back({v[i], rng[i + 1] + 1, rng[i]});

  return res;
}

vector<array<int, 3>> calc_ceil(int x) {
  vector<int> v, rng;
  for(int i = 1; ; ) {
    int val = (x + i - 1) / i;
    v.emplace_back(val);
    rng.emplace_back((x + val - 1) / val);
    if (val == 1)
      break;
    i = (x + val - 2) / (val - 1);
  }
  rng.emplace_back(x + 1);

  vector<array<int, 3>> res;
  for(int i = 0; i < v.size(); i++)
    res.push_back({v[i], rng[i], rng[i + 1] - 1});

  return res;
}
//////////////////////////////////////////////////
