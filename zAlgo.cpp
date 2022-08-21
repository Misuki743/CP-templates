//////////////////////////////////////////////////
//template name: zAlgo
//author: __Shioko(Misuki)
//last update: 2022/02/04

int z[2000000];
void build(string &s) {
  fill(z, z + s.size(), 0);
  z[0] = s.size();
  for(int i = 1, l = 0, r = -1; i < s.size(); i++) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < s.size() and s[i + z[i]] == s[z[i]])
      l = i, r = i + z[i], z[i] += 1;
  }
}
//////////////////////////////////////////////////
