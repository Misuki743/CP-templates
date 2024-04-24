read sol1 sol2 gen
for i in {0..99}; do
  echo testcase $i
  ./$gen > input
  ./$sol1 < input > output1
  ./$sol2 < input > output2
  if !(diff output1 output2 > log)
  then
    echo input:
    cat input
    echo output1:
    cat output1
    echo output2:
    cat output2
    break
  fi
done
