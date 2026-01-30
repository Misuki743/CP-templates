struct DSU {
  vector<array<int, 4>> his;
  vector<int> bos, sz;
  int size;

  DSU(int _size) : bos(_size), sz(_size, 1), size(_size) {
    iota(bos.begin(), bos.end(), 0);
  }

  int query(int v) {
    if (bos[v] == v)
      return v;
    else
      return query(bos[v]);
  }

  bool merge(int v1, int v2) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (sz[b1] > sz[b2])
      swap(b1, b2);

    his.push_back({b1, bos[b1], b2, sz[b2]});
    bos[b1] = b2, sz[b2] += sz[b1];

    return true;
  }

  int time() { return ssize(his); }

  void rollback(int t) {
    while(ssize(his) > t) {
      auto arr = his.back(); his.pop_back();
      bos[arr[0]] = arr[1], sz[arr[2]] = arr[3];
    }
  }

  int cc() { return size - ssize(his); }
};
