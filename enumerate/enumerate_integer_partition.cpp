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
