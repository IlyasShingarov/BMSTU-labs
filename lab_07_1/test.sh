#!/bin/bash

POS_TEST_COUNT=11
NEG_TEST_COUNT=9

echo
echo "Positive tests:"
for ((i=1; i<=$POS_TEST_COUNT; i++))
do
    rm -rf ./func_tests/share/fout.txt
    bash ./func_tests/share/pos_0${i}_args.txt
    ERROR_CODE=$?
    if cmp -s ./func_tests/share/pos_0${i}_out.txt ./func_tests/share/fout.txt && [ $? -eq 0 ]
        then echo "TEST_0${i}: PASS"
    else 
        echo "TEST_0${i}: FAIL"
        #diff ./func_tests/share/pos_0${i}_out.txt ./func_tests/share/fout.txt
        cat ./func_tests/share/pos_0${i}_out.txt
        echo
        cat ./func_tests/share/fout.txt
        echo "Код ошибки: $ERROR_CODE"
    fi
done
read -p "Press enter to continue"

echo
echo
echo "Negative tests:"
for ((i=1; i<=$NEG_TEST_COUNT; i++))
do
    rm -rf ./func_tests/share/fout.txt
    bash ./func_tests/share/neg_0${i}_args.txt
    ERROR_CODE=$?
    if cmp -s ./func_tests/share/neg_0${i}_out.txt ./func_tests/share/fout.txt || [ $ERROR_CODE -ne 0 ]
        then echo "TEST_0${i}: PASS"
    else 
        echo "TEST_0${i}: FAIL"
        echo "Код ошибки: $ERROR_CODE"
    fi
done
read -p "Press enter to continue"

echo
echo
echo "Code coverage"
for file in `find ./out/ -type f -name "*.o"`
do
    gcov -n $file
done