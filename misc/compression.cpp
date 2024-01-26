template<class T, bool duplicate = false>
struct compression {
  vector<int> ord;
  vector<T> val;
  compression(vector<T> &init) : ord(ssize(init)), val(init) {
    R::sort(val);
    if constexpr (duplicate) {
      vector<int> cnt(ssize(init));
      iota(cnt.begin(), cnt.end(), 0);
      for(int i = 0; i < ssize(init); i++)
        ord[i] = cnt[lb(init[i])]++;
    } else {
      val.resize(unique(val.begin(), val.end()) - val.begin());
      for(int i = 0; i < ssize(init); i++)
        ord[i] = lb(init[i]);
    }
  }
  int lb(T x) { return R::lower_bound(val, x) - val.begin(); }
};
