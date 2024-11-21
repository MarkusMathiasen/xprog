g++ -O2 main.cpp -o main
for (( i=1; i<=$1; ++i )) do
  for (( j=1; j<=100; ++j )) do
    echo $j | python gen.py > test.txt
    python cheat.py < test.txt > cheat.txt
    python test.py < test.txt > main.txt
    if [[ $(diff cheat.txt main.txt) ]]
    then
      echo "$(diff -Z cheat.txt main.txt)" > diff.txt
      printf "WA on test $i cycle length $j\nTESTS FAILED!\n"
      exit 0
    else echo "AC on test $i cycle length $j"
fi done done
echo "TESTS PASSED!"