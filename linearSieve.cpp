/**
 * template name: linearSieve
 * author: Misuki
 * last update: 2022/12/13
 */

const int C = 1000001;
vector<int> prime;
int mpf[C];
void sieve() {
  for(int i = 1; i < C; i++)
    mpf[i] = i;
  for(int i = 2; i < C; i++) {
    if (mpf[i] == i)
      prime.emplace_back(i);
    for(int P : prime) {
      if (P > mpf[i] or i * P >= C)
        break;
      mpf[i * P] = P;
    }
  }
}

vector<pii> factorize(int val) {
  vector<pii> res;
  while(val > 1) {
    int p = mpf[val];
    res.emplace_back(p, 0);
    while(val % p == 0)
      res.back().second += 1, val /= p;
  }
  return res;
}

vector<int> factors(int val) {
  vector<int> res(1, 1);
  for(auto [p, idx] : factorize(val)) {
    vector<int> tmp;
    for(int i = 0, base = 1; i <= idx; i++, base *= p)
      for(int X : res)
        tmp.emplace_back(X * base);
    res.swap(tmp);
  }
  return res;
}
