//////////////////////////////////////////////////
//template name: DSU
//author: __Shioko(Misuki)
//last update: 2023/01/07
//verify: Library Checker - Unionfind

struct DSU {
  vector<int> dep;
  vector<int> bos;
  int size;

  DSU(int _size) : size(_size), dep(_size, 0), bos(_size) {
    iota(bos.begin(), bos.end(), 0);
  }

  int query(int V) {
    if (bos[V] == V) {
      return V;
    } else {
      bos[V] = query(bos[V]);
      return bos[V];
    }
  }

  bool merge(int V1, int V2) {
    int B1 = query(V1);
    int B2 = query(V2);

    if (B1 == B2) {
      return false;
    }

    if (dep[B1] < dep[B2]) {
      bos[B1] = B2;
    } else if (dep[B1] > dep[B2]) {
      bos[B2] = B1;
    } else {
      bos[B1] = B2;
      dep[B2] += 1;
    }

    return true;
  }
};
////////////////////////////////////////////////// 
