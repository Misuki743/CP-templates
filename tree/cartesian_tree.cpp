template<class T>
vi cartesian_tree(vc<T> a) {
  vi p(size(a)), s;
  for(int i = 0; i < ssize(a); i++) {
    int last_pop = -1;
    while(!s.empty() and a[s.back()] > a[i]) {
      int j = s.back(); s.pop_back();
      if (last_pop != -1)
        p[last_pop] = j;
      last_pop = j;
    }
    if (last_pop != -1)
      p[last_pop] = i;
    s.emplace_back(i);
  }

  p[s[0]] = s[0];
  for(int i = 1; i < ssize(s); i++)
    p[s[i]] = s[i - 1];

  return p;
}
