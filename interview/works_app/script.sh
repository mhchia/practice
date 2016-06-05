#!/bin/bash

for var in $(seq 1 1000)
do
    python gen_test.py | ./Main 2>&1 1>/dev/null
    if [ $? != 0 ]; then
        echo "$var : Failed"
    else
        echo "$var : OK"
    fi
    sleep 1
done
