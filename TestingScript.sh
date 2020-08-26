for((i = 1; i <= 200 ; ++i)); do
        echo $i
        ./gen $i > in
        ./c < in > out1
        ./brute < in > out2
        diff -w out1 out2 || break
#       diff -w <(./a < int) <(./brute < int) || break
done
