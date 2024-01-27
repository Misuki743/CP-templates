template<class T, bool duplicate = false>
struct compression {
  vector<int> ord;
  vector<T> val;

  compression(vector<T> &init) : val(init) { precompute(); }
  compression(int size = 0) { val.reserve(size); }

  void precompute() {
    vector<T> init = val;
    ord.resize(ssize(val));
    R::sort(val);
    if constexpr (duplicate) {
      vector<int> cnt(ssize(init));
      iota(cnt.begin(), cnt.end(), 0);
      for(int i = 0; i < ssize(ord); i++)
        ord[i] = cnt[lower_bound(init[i])]++;
    } else {
      val.resize(unique(val.begin(), val.end()) - val.begin());
      for(int i = 0; i < ssize(ord); i++)
        ord[i] = lower_bound(init[i]);
    }
  }

  int lower_bound(T x) { return R::lower_bound(val, x) - val.begin(); }
  int size() { return ssize(val); }
  template<R::range rng, class proj = identity>
  void mapping(rng &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }
  template<R::range rng, class proj = identity>
  void insert(rng &v, proj p = {}) { for(auto &x : v) val.emplace_back(p(x)); }
};
