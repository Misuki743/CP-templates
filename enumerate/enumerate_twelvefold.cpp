//#include "enumerate/bit.cpp"

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

template<typename F>
requires invocable<F, vector<int>>
void enumerate_permutation(int n, F f) {
  assert(n >= 0);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  do { f(p); } while(next_permutation(p.begin(), p.end()));
}

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
