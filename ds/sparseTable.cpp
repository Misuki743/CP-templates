template<class T>
struct sparseTable{
  vector<vector<T> > table;
  function<T(const T&, const T&)> comb;
  int size = 0;

  sparseTable(vector<T> base, function<T(const T&, const T&)> _comb) {
    comb = _comb;
    size = base.size();
    table.resize(bit_width((unsigned)size), std::vector<T>(size));
    
    table[0] = base;
    for(int i = 1; i < ssize(table); i++) {
      for(int j = 0; j < size; j++) {
        if (j + (1 << (i - 1)) < size)
          table[i][j] = comb(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        else
          table[i][j] = table[i - 1][j];
      }
    }
  }

  T query(int l, int r) {
    int range = bit_width((unsigned)(r - l)) - 1;
    return comb(table[range][l], table[range][r - (1 << range)]);
  }
};
