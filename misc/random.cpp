namespace RNG {
  mt19937_64 rng(clock);

  //empty vector would be assumed to be n = 2
  vector<pii> prufer_recover(vector<int> prufer_code) {
    const int n = ssize(prufer_code) + 2;
    assert(prufer_code.empty() or (ranges::min(prufer_code) >= 0 and ranges::max(prufer_code) < n));
    vector<int> d(n, 1);
    for(int x : prufer_code) d[x]++;
    min_heap<int> leaf;
    for(int v = 0; v < n; v++)
      if (d[v] == 1)
        leaf.emplace(v);
    vector<pii> edges;
    for(int x : prufer_code) {
      int v = leaf.top(); leaf.pop();
      edges.emplace_back(v, x);
      if (--d[x] == 1)
        leaf.emplace(x);
    }
    int v = leaf.top(); leaf.pop();
    edges.emplace_back(v, leaf.top());
    return edges;
  }

  int rand_int(int l, int r) { return uniform_int_distribution(l, r - 1)(rng); }
  vi rand_seq(int n, int l, int r) {
    assert(n >= 0);
    vi v(n);
    for(int &x : v) x = rand_int(l, r);
    return v;
  }
  vvi rand_label_tree(int n) {
    assert(n >= 0);
    if (n <= 1) return vvi(n);
    else return adjacency_list<false>(n, prufer_recover(rand_seq(n - 2, 0, n)), 0);
  }
  vi rand_perm(int n) {
    assert(n >= 0);
    vi p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), rng);
    return p;
  }
  vi rand_comb(int n, int k) {
    assert(0 <= k and k <= n);
    vi p = rand_perm(n);
    p.resize(k);
    ranges::sort(p);
    return p;
  }
};

using namespace RNG;
