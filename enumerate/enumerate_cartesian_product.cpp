//enumerate product of [0, rs_i)
template<typename F>
requires invocable<F, vector<int>>
void enumerate_cartesian_product(vector<int> rs, F f) {
  vector<int> a(size(rs));
  auto dfs = [&](int i, auto &self) -> void {
    if (i == ssize(rs)) {
      f(a);
    } else {
      for(int j = 0; j < rs[i]; j++) {
        a[i] = j;
        self(i + 1, self);
      }
    }
  };
  dfs(0, dfs);
}
