for((i=1;;++i)); do
  echo $i
  ./gen $i > int
  diff <(./solution < int) <(./stupid < int) || break
done

#here gen.cpp has the test case generator code,  then soltuion.cpp has the code that we need to test, and stupid has the correct brute force solution 
#it will run while the solution is correct. when it found a case which is wrong, that will be there is int file.