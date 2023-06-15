/**
 * template name: fastZetaTransform
 * author: Misuki
 * last update: 2023/03/26
 * note: to change to poset, flip the condition inside if statement. 
 * four possible usage:
 * fastZetaTransform on subset (SOS)
 * fastZetaTransform on poset
 * fastMobiusTransform on subset
 * fastMobiusTransform on poset (IEP)
 */

template<class T>
void fastZetaTransform(vector<T> &vec, bool inverse = false) {
  for(int i = 0; (1 << i) < (int)vec.size(); i++)
    for(int j = 0; j < (int)vec.size(); j++)
      if (j >> i & 1)
        vec[j] += (inverse ? -vec[j ^ (1 << i)] : vec[j ^ (1 << i)]);
}
