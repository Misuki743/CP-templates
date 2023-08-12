/**
 * template name: sparseTable
 * author: Misuki
 * last update: 2023/06/21
 * verify: LibraryChecker - Static RMQ
 */

template<class T>
struct sparseTable{
  vector<vector<T> > table;
  function<T(T, T)> comb;
  int size = 0;

  sparseTable(vector<T> &base, function<T(T, T)> _comb) {
    comb = _comb;
    size = base.size();
    table.resize(__lg(size) + 1, std::vector<T>(size));
    
    table[0] = base;
    for(int i = 1; i < (int)table.size(); i++) {
      for(int j = 0; j < size; j++) {
        if (j + (1 << (i - 1)) < size)
          table[i][j] = comb(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        else
          table[i][j] = table[i - 1][j];
      }
    }
  }

  //query range in [l, r)
  T query(int l, int r) {
    int range = __lg(r - l);
    return comb(table[range][l], table[range][r - (1 << range)]);
  }
};
