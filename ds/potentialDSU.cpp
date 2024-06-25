template<class T>
struct DSU {
  vector<int> bos, sz;
  vector<T> _pot;
  int size;

  DSU(int _size) : bos(_size), sz(_size, 1), _pot(_size), size(_size) {
    iota(bos.begin(), bos.end(), 0);
  }

  int query(int v) {
    if (bos[v] == v) {
      return v;
    } else {
      int tmp = query(bos[v]);
      _pot[v] += _pot[bos[v]]; 
      return bos[v] = tmp;
    }
  }

  //v1 + d = v2
  bool merge(int v1, int v2, T d) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (sz[b1] > sz[b2]) {
      swap(b1, b2), swap(v1, v2);
      d *= -1;
    }
    bos[b1] = b2, sz[b2] += sz[b1], _pot[b1] = _pot[v2] - _pot[v1] - d;

    return true;
  }

  int pot(int v) {
    query(v);
    return _pot[v];
  }
};
