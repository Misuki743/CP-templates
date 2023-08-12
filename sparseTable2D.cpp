/**
 * template name: sparseTable2D
 * author: Misuki
 * last update: 2023/06/21
 * verify: CF 1301-E
 */
template<class T>
struct sparseTable2D {
  vector<vector<vector<vector<T>>>> table;
  function<T(T, T)> comb;
  int size = 0;

  sparseTable2D(vector<sparseTable<T>> &base, function<T(T, T)> _comb) {
    comb = _comb;
    size = base.size();
    vector<vector<vector<T>>> tmp(size);
    for(int i = 0; i < size; i++)
      tmp[i] = base[i].table;
    table.resize(__lg(size) + 1, tmp);
    for(int i = 1; i < (int)table.size(); i++) {
      for(int j = 0; j < size; j++) {
        for(int k = 0; k < (int)table[i][j].size(); k++) {
          for(int l = 0; l < (int)table[i][j][k].size(); l++) {
            if (j + (1 << (i - 1)) < size)
              table[i][j][k][l] = comb(table[i - 1][j][k][l], table[i - 1][j + (1 << (i - 1))][k][l]);
            else
              table[i][j][k][l] = table[i - 1][j][k][l];
          }
        }
      }
    }
  }

  //query range in [r1, r2) x [c1, c2)
  T query(int r1, int c1, int r2, int c2) {
    int rRange = __lg(r2 - r1), cRange = __lg(c2 - c1);
    return comb(comb(table[rRange][r1][cRange][c1], table[rRange][r1][cRange][c2 - (1 << cRange)]),
                comb(table[rRange][r2 - (1 << rRange)][cRange][c1], table[rRange][r2 - (1 << rRange)][cRange][c2 - (1 << cRange)]));
  }
};
