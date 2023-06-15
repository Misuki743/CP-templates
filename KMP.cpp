/**
 * template name: KMP
 * author: Misuki
 * last update: 2022/02/04
 */

int fail[1000000];
void build(string &s) {
  fail[0] = -1;
  for(int i = 1; i < s.size(); i++) {
    int now = fail[i - 1];
    while(now != -1 and s[i] != s[now + 1])
      now = fail[now];
    fail[i] = now + ((s[now + 1] == s[i]) ? 1 : 0);
  }
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
