template<int mxBit, bool duplicate = false>
struct binaryTrie {
  vector<array<int, 2>> nxt;
  vector<int> cnt;

  binaryTrie(int size = 0) : nxt(1, {-1, -1}), cnt(1) {
    nxt.reserve(size);
    cnt.reserve(size);
  }

  int count(ull x) {
    int v = 0;
    for(int bit = mxBit; bit >= 0; bit--) {
      ull to = x >> bit & 1;
      if (nxt[v][to] == -1) return 0;
      v = nxt[v][to];
    }
    return cnt[v];
  }

  void insert(ull x) {
    if constexpr (!duplicate) {
      if (count(x)) return;
    }
    int v = 0;
    cnt[0] += 1;
    for(int bit = mxBit; bit >= 0; bit--) {
      ull to = x >> bit & 1;
      if (nxt[v][to] == -1) {
        nxt[v][to] = ssize(nxt);
        nxt.push_back({-1, -1});
        cnt.emplace_back();
      }
      v = nxt[v][to], cnt[v] += 1;
    }
  }

  void erase(ull x) {
    if (!count(x)) return;
    int v = 0;
    cnt[0] -= 1;
    for(int bit = mxBit; bit >= 0; bit--)
      v = nxt[v][x >> bit & 1], cnt[v] -= 1;
  }

  ull queryMin(ull Xor = 0LL) {
    assert(cnt[0] > 0);
    ull res = 0;
    int v = 0;
    for(int bit = mxBit; bit >= 0; bit--) {
      ull to = Xor >> bit & 1;
      if (nxt[v][to] != -1 and cnt[nxt[v][to]] >= 1)
        v = nxt[v][to];
      else
        res |= 1LL << bit, v = nxt[v][to ^ 1];
    }
    return res;
  }
};
