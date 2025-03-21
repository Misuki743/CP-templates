using ldb = long double;
struct line {
  ldb m, b;
  ldb inter(line l) { return (b - l.b) / (l.m - m); }
};

vector<line> build_hull(vector<line> v) {
  {
    ranges::sort(v, {}, [](line &l) { return pair(-l.m, l.b); });
    vector<line> tmp;
    for(int i = 0, j = 0; i < ssize(v); i = j) {
      while(j < ssize(v) and v[i].m == v[j].m) j++;
      tmp.emplace_back(v[i]);
    }
    v.swap(tmp);
  }
  vector<line> h;
  for(auto l : v) {
    while(ssize(h) >= 2 and l.inter(end(h)[-2]) <= h.back().inter(end(h)[-2]))
      h.pop_back();
    h.emplace_back(l);
  }
  return h;
}

ldb query_hull(vector<line> &h, ldb x) {
  auto pred = [&](int i) { return h[i].inter(h[i + 1]) < x; };
  int i = *ranges::partition_point(views::iota(0, ssize(h) - 1), pred);
  return h[i].m * x + h[i].b;
}
