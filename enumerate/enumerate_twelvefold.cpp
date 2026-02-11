//#include "enumerate/bit.cpp"

//n^k
template<typename F>
requires invocable<F, vector<int>>
void enumerate_cartesian_power(int n, int k, F f) {
  assert(min(n, k) >= 0);
  vector<int> p(k);
  auto dfs = [&](int i, auto &self) -> void {
    if (i == k) {
      f(p);
    } else {
      for(int x = 0; x < n; x++) {
        p[i] = x;
        self(i + 1, self);
      }
    }
  };
  dfs(0, dfs);
}

//factorial:
//[1, 2, 6, 24, 120,
// 720, 5040, 40320, 362880, 3628800,
// 39916800, 479001600, 6227020800, 87178291200, 1307674368000]
template<typename F>
requires invocable<F, vector<int>>
void enumerate_permutation(int n, F f) {
  assert(n >= 0);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  do { f(p); } while(next_permutation(p.begin(), p.end()));
}

//binom(n, k)
template<typename F>
requires invocable<F, vector<int>>
void enumerate_combination(int n, int k, F f) {
  assert(min(n, k) >= 0);
  vector<int> p;
  auto dfs = [&](auto &self) -> void {
    if (ssize(p) == k) {
      f(p);
    } else {
      for(int x = (p.empty() ? 0 : p.back() + 1); x + k - ssize(p) <= n; x++) {
        p.emplace_back(x);
        self(self);
        p.pop_back();
      }
    }
  };
  dfs(dfs);
}

//Bell's number:
//[1, 2, 5, 15, 52,
// 203, 877, 4140, 21147, 115975,
// 678570, 4213597, 27644437, 190899322, 1382958545]
template<typename F>
requires invocable<F, vector<int>>
void enumerate_set_partition(int n, F f) {
  assert(n >= 0);
  vector<int> p;
  int msk = (1 << n) - 1;
  auto dfs = [&](auto &self) -> void {
    if (msk == 0) {
      f(p);
    } else {
      int x = msk & (-msk);
      msk ^= x;
      enumerate_subset(msk, [&](int sub) {
        p.emplace_back(sub | x);
        msk ^= sub;
        self(self);
        msk ^= sub;
        p.pop_back();
      });
      msk ^= x;
    }
  };
  dfs(dfs);
}

//f[0] + f[1] + ... + f[n - 1] = sum, f[i] >= 0
//binom(sum + (n - 1), sum)
template<typename F>
requires invocable<F, vector<int>>
void enumerate_multisubset(int n, int sum, F f) {
  assert(min(n, sum) >= 0);
  vector<int> p(n);
  auto dfs = [&](int i, auto &self) -> void {
    if (i == n) {
      if (sum == 0) f(p);
    } else {
      for(int x = sum; x >= 0; x--) {
        p[i] = x, sum -= x;
        self(i + 1, self);
        sum += x;
      }
    }
  };
  dfs(0, dfs);
}

//partition number:
//n = 10: 42
//n = 20: 627
//n = 30: 5604
//n = 40: 37338
//n = 50: 204226
//n = 60: 966467
//n = 70: 4087968
//n = 80: 15796476
//n = 90: 56634173
//n = 100: 190569292
template<typename F>
requires invocable<F, vector<int>>
void enumerate_integer_partition(int n, F f) {
  assert(n >= 0);
  vector<int> p;
  auto dfs = [&](int s, auto &self) -> void {
    if (s == 0) {
      f(p);
    } else {
      for(int x = (p.empty() ? s : min(p.back(), s)); x > 0; x--) {
        p.emplace_back(x);
        self(s - x, self);
        p.pop_back();
      }
    }
  };
  dfs(n, dfs);
}
