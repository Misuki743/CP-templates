template<class T>
struct fenwickTree {
  const int size;
  vector<T> data;

  fenwickTree(int _size) : size(_size + 1), data(_size + 1) {}
  fenwickTree(vector<T> &init) : size(ssize(init) + 1), data(ssize(init) + 1) {
    partial_sum(init.begin(), init.end(), data.begin() + 1);
    for(int i = size - 1; i > 0; i--)
      data[i] -= data[i - (i & (-i))];
  }

  void add(int i, T d) {
    for(i += 1; i < size; i += i & (-i))
      data[i] += d;
  }

  T query(int i) {
    T res = T(0);
    for(i += 1; i > 0; i -= i & (-i))
      res += data[i];
    return res;
  }

  T query(int l, int r) {
    return query(r - 1) - query(l - 1);
  }
};
