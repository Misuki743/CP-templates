vector<int> Manacher(string &s) {
  vector<int> p(ssize(s));
  for(int i = 0, l = -1, r = -1; i < ssize(s); i++) {
    if (i <= r)
      p[i] = min(p[2 * l - i], r - i + 1);
    while(i + p[i] < ssize(s) and i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]])
      l = i, r = i + p[i], p[i] += 1;
  }

  return p;
}

vector<int> enumeratePalindrome(string &s) {
  string t = "#";
  for(char c : s)
    t += c, t += '#';
  vector<int> p = Manacher(t);
  for(int &x : p)
    x -= 1;
  return vector<int>(p.begin() + 1, p.end() - 1);
}
