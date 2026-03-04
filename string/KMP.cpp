template<class T>
vi prefix_function(T &s) {
  vi pi(size(s));
  pi[0] = -1;
  for(int i = 1; i < ssize(s); i++) {
    int now = pi[i - 1];
    while(now != -1 and s[i] != s[now + 1])
      now = pi[now];
    pi[i] = now + (s[now + 1] == s[i]);
  }
  return pi;
}

int match(string &a, string &b) {
  build(b);
  int res = 0;
  int now = -1;
  for(char X : a) {
    while(now != -1 and X != b[now + 1])
      now = fail[now];
    if (X == b[now + 1])
      now++;
    if (now + 1 == b.size())
      res++, now = fail[now];
  }

  return res;
}
