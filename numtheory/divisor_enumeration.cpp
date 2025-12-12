template<int32_t C>
struct divisor_enumeration {
  using i32 = int32_t;
  array<i32, C + 1> s = {};
  vector<i32> d;
  divisor_enumeration() {
    for(int i = 1; i < C; i++)
      for(int j = i; j < C; j += i)
        s[j]++;
    for(int i = 1; i <= C; i++)
      s[i] += s[i - 1];
    d.resize(s[C]);
    for(int i = C - 1; i >= 1; i--)
      for(int j = i; j < C; j += i)
        d[--s[j]] = i;
  }
  vector<int> divisor(int x) {
    return vector<int>(d.begin() + s[x], d.begin() + s[x + 1]);
  }
};
