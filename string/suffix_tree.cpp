//#include "string/suffixArray.cpp"

//0 is root, substring presented by v is
//s[suf_id[v] + dep[p[v]], suf_id[v] + dep[v])
auto suffix_tree(vi SA, vi LCP) {
  const int n = ssize(SA);

  LCP.eb(0);

  vi st = {0}, suf_id = {0}, dep = {0}, freq = {0};
  vi lcp_st = {-1};
  vvi g(1);
  int nxt = 1;
  for(int i = 0; i < n; i++) {
    g.eb();
    st.eb(nxt++);
    suf_id.eb(SA[i]);
    dep.eb(n - SA[i]);
    freq.eb(-i);

    int last_pop = -1;
    while(dep[st.back()] > LCP[i]) {
      int j = st.back(); st.pop_back();
      freq[j] += i + 1;
      if (last_pop != -1)
        g[j].eb(last_pop);
      last_pop = j;
    }
    while(lcp_st.back() != -1 and LCP[lcp_st.back()] >= LCP[i])
      lcp_st.pop_back();
    if (dep[st.back()] != LCP[i]) {
      g.eb();
      st.eb(nxt++);
      suf_id.eb(SA[i]);
      dep.eb(LCP[i]);
      freq.eb(-(lcp_st.back() + 1));
    }
    lcp_st.eb(i);
    if (last_pop != -1)
      g[st.back()].eb(last_pop);
  }

  return tuple(g, suf_id, dep, freq);
}
