//////////////////////////////////////////////////
//template name: disjointSet
//author: __Shioko(Misuki)
//last update: 2022/01/13

struct disjointSet{
  vector<int> bos;
  vector<int> dep;
  int size;

  disjointSet(int _size) {
    size = _size;
    bos.resize(size, 0);
    dep.resize(size, 0);
    for(int i = 0; i < size; i++) {
      bos[i] = i;
    }
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
