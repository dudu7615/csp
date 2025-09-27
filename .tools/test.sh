#!/bin/bash

for file in $(find . -name "in*" | sort); do
    echo "========= Testing $file ========="
    cat $file > in
    ./main~
    echo -e "\n\n"
    rm in
done

