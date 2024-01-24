struct DSU {
  vector<int> dep;
  vector<int> bos;
  vector<int> d;
  int size;

  DSU(int _size) : size(_size), dep(_size, 0), bos(_size), d(_size) {
    iota(bos.begin(), bos.end(), 0);
  }

  array<int, 2> query(int V) {
    if (bos[V] == V) {
      return {d[V], V};
    } else {
      auto res = query(bos[V]);
      d[V] ^= res[0];
      bos[V] = res[1];
      return {d[V], bos[V]};
    }
  }

  bool merge(int V1, int V2, bool eq) {
    int del = (eq ? 0 : 1);
    int B1 = query(V1)[1];
    int B2 = query(V2)[1];

    if (B1 == B2)
      return (d[V1] ^ d[V2]) == del;

    if (dep[B1] < dep[B2]) {
      bos[B1] = B2, d[B1] = d[V1] ^ d[V2] ^ del;
    } else if (dep[B1] > dep[B2]) {
      bos[B2] = B1, d[B2] = d[V1] ^ d[V2] ^ del;
    } else {
      bos[B1] = B2, d[B1] = d[V1] ^ d[V2] ^ del;
      dep[B2] += 1;
    }

    return true;
  }
};
