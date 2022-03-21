//////////////////////////////////////////////////
//template name: sparseTable
//author: __Shioko(Misuki)
//last update: 2021/07/11

template<class T>
struct sparseTable{
  std::vector<std::vector<T> > table;
  int size = 0;

  void buildMin(std::vector<T> &base) {
    size = base.size();
    table.resize(__lg(size) + 1, std::vector<T>(size));
    
    table[0] = base;
    for(int i = 1; i < table.size(); i++) {
      for(int j = 0; j < size; j++) {
        if (j + (1 << (i - 1)) < size) {
          table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        } else {
          table[i][j] = table[i - 1][j];
        }
      }
    }
  } 

  void buildMax(std::vector<T> &base) {
    size = base.size();
    table.resize(__lg(size) + 1, std::vector<T>(size));
    
    table[0] = base;
    for(int i = 1; i < table.size(); i++) {
      for(int j = 0; j < size; j++) {
        if (j + (1 << (i - 1)) < size) {
          table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        } else {
          table[i][j] = table[i - 1][j];
        }
      }
    }
  } 

  //query range in [l, r)
  T queryMin(int l, int r) {
    int range = __lg(r - l);
    return min(table[range][l], table[range][r - (1 << range)]);
  }

  T queryMax(int l, int r) {
    int range = __lg(r - l);
    return max(table[range][l], table[range][r - (1 << range)]);
  }
};
//////////////////////////////////////////////////
