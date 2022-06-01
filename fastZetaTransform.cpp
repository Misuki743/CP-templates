//////////////////////////////////////////////////
//template name: fastZetaTransform
//author: __Shioko(Misuki)
//last update: 2022/05/29
//note: to change to poset, flip the condition inside if statement. 
//      to change to fast mobius transform, use minus instead of plus.
//four possible usage:
//fastZetaTransform on subset (SOS)
//fastZetaTransform on poset
//fastMobiusTransform on subset
//fastMobiusTransform on poset (IEP)

void fastZetaTransform(vector<int> &vec) {
  for(int i = 0; (1 << i) < vec.size(); i++)
    for(int j = 0; j < vec.size(); j++)
      if (j >> i & 1)
        vec[j] += vec[j ^ (1 << i)];
}
//////////////////////////////////////////////////
