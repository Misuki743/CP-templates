//#include<string/suffixArray.cpp>

array<int, 4> longestCommonSubstring(string s, string t) {
  t = s + '#' + t;
  auto sa = suffix_array(t);
  auto lcp = lcp_array(t, sa);
  array<int, 4> res = {};
  for(int i = 0; i < ssize(lcp); i++) {
    if (lcp[i] <= res[1] - res[0]) continue;
    if (sa[i] < ssize(s) and sa[i + 1] > ssize(s))
      res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s) + 1), sa[i + 1] - (int)(ssize(s) + 1) + lcp[i]};
    else if (sa[i] > ssize(s) and sa[i + 1] < ssize(s))
      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i] - (int)(ssize(s) + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};
  }
  return res;
}
