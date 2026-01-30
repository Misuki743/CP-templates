vi recover(vi &pre, int t) {
  if (pre[t] == -1) return {};
  vi path = {t};
  while(pre[path.back()] != path.back())
    path.emplace_back(pre[path.back()]);
  ranges::reverse(path);
  return path;
}
