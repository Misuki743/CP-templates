template<class T> 
struct segmentTree2D {
  static const int MAXR = 2000;
  static const int MAXC = 2000;
  function<T(const T&, const T&)> combine;
  T UNIT;
  T arr[2 * MAXR][2 * MAXC];
  int szR, szC;

  segmentTree2D(int _szR, int _szC, T _UNIT, function<T(const T&, const T&)> _combine) {
    szR = _szR, szC = _szC;
    UNIT = _UNIT;
    combine = _combine;
    for(int i = 0; i < 2 * szR; i++)
      fill(arr[i], arr[i] + 2 * szC, UNIT);
  }

  void set(int x, int y, T val) {
    x += szR;
    set2(x, y, val);
    x >>= 1;
    while(x) {
      set2(x, y, val);
      x >>= 1;
    }
  }

  void set2(int x, int y, T val) {
    y += szC;
    arr[x][y] = combine(arr[x][y], val);
    y >>= 1;
    while(y) {
      arr[x][y] = combine(arr[x][y<<1], arr[x][y<<1|1]);
      y >>= 1;
    }
  }

  T query(int x1, int x2, int y1, int y2) {
    T L = UNIT, R = UNIT;
    for(x1 += szR, x2 += szR; x1 < x2; x1 >>= 1, x2 >>= 1) {
      if (x1 & 1) L = combine(L, query2(x1++, y1, y2));
      if (x2 & 1) R = combine(query2(--x2, y1, y2), R);
    }
    return combine(L, R);
  }
  
  T query2(int x, int y1, int y2) {
    T L = UNIT, R = UNIT;
    for(y1 += szC, y2 += szC; y1 < y2; y1 >>= 1, y2 >>= 1) {
      if (y1 & 1) L = combine(L, arr[x][y1++]);
      if (y2 & 1) R = combine(arr[x][--y2], R);
    }
    return combine(L, R);
  }
};
