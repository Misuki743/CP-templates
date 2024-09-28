template<class T>
vector<T> min_plus_convolution(vector<T> convex, vector<T> b) {
  vector<T> c(ssize(convex) + ssize(b) - 1, numeric_limits<T>::max());
  auto dc = [&](int l, int r, int ql, int qr, auto &&self) -> void {
    int mid = (l + r) / 2;
    int best = -1;
    for(int j = max(ql, mid - (int)size(convex) + 1); j <= min(qr, mid); j++)
      if (chmin(c[mid], convex[mid - j] + b[j]))
        best = j;
    if (l + 1 != r) {
      self(l, mid, ql, best, self);
      self(mid, r, best, qr, self);
    }
  };
  dc(0, ssize(c), 0, ssize(b) - 1, dc);
  return c;
}
