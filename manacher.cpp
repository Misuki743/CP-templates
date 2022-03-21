//////////////////////////////////////////////////
//template name: manacher
//author: __Shioko(Misuki)
//last update: 2022/02/04

int p[2000001];
void build(string &s) {
  for(int i = 0, l = -1, r = -1; i < s.size(); i++) {
    if (i <= r)
      p[i] = min(p[2 * l - i], r - i + 1);
    while(i + p[i] < s.size() and i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]])
      l = i, r = i + p[i], p[i] += 1;
  }
}
//////////////////////////////////////////////////
