//#include "graph/tree.cpp"

auto tree_diameter(vc<pii> e) {
  auto d0 = tree(e).dep;
  int u = max_element(d0.begin(), d0.end()) - d0.begin();
  tree t(e, u);
  int v = max_element(t.dep.begin(), t.dep.end()) - t.dep.begin();
  vi path = {v};
  for(int i = t.dep[v]; i > 0; i--)
    path.emplace_back(t.p[path.back()]);
  return pair((int)(ssize(path) - 1), path);
}
