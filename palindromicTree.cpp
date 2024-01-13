/**
 * template name: palindromicTree
 * author: Misuki
 * last update: 2024/01/13
 * verify: yukicoder - No.2606 Mirror Relay
 */

template<unsigned sigma = 26, char base = 'a'>
struct palindromicTree {
  vector<int> len, link;
  vector<ll> freq;
  vector<array<int, sigma>> go;

  palindromicTree(string s) {
    array<int, sigma> unit;
    fill(unit.begin(), unit.end(), -1);
    len = link = {-1, 0}, go = {unit, unit}, freq = {0, 0};
    len.reserve(ssize(s) + 2);
    link.reserve(ssize(s) + 2);
    go.reserve(ssize(s) + 2);
    freq.reserve(ssize(s) + 2);

    int v = 0;
    for(int i = 0; i < ssize(s); i++) {
      while(len[v] == i or s[i - len[v] - 1] != s[i])
        v = link[v];
      if (go[v][s[i] - base] == -1) {
        go[v][s[i] - base] = ssize(len);
        len.emplace_back(len[v] + 2);
        freq.emplace_back();
        go.emplace_back(unit);
        int u = link[v];
        while(u != -1 and s[i - len[u] - 1] != s[i])
          u = link[u];
        link.emplace_back(u == -1 ? 1 : go[u][s[i] - base]);
      }
      v = go[v][s[i] - base];
      freq[v]++;
    }

    for(int i = ssize(len) - 1; i > 0; i--)
      freq[link[i]] += freq[i];
    freq[0] = freq[1] = 0;
  }
};
