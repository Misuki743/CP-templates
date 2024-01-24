vector<int> zFunc(string &s) {
  vector<int> z(ssize(s));
  z[0] = ssize(s);
  for(int i = 1, l = 0, r = -1; i < ssize(s); i++) {
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < ssize(s) and s[i + z[i]] == s[z[i]])
      l = i, r = i + z[i], z[i] += 1;
  }
  return z;
}
