/**
 * template name: DSU
 * author: Misuki
 * last update: 2024/01/01
 * verify: Library Checker - Unionfind
 */

struct DSU {
  vector<int> bos, sz;
  int size;

  DSU(int _size) : bos(_size), sz(_size, 1), size(_size) {
    iota(bos.begin(), bos.end(), 0);
  }

  int query(int v) {
    if (bos[v] == v)
      return v;
    else
      return bos[v] = query(bos[v]);
  }

  bool merge(int v1, int v2) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (sz[b1] > sz[b2])
      swap(b1, b2);
    bos[b1] = b2, sz[b2] += sz[b1];

    return true;
  }
};
