#!/bin/bash
#written by obult

def="$2"
range="100"
if [ "$def" == "" ]
then
def="$range"
fi
for i in $(seq $1);
do
ARG="$(ruby -e "puts (1..$def).to_a.shuffle.join(' ')")"
./push_swap $ARG | ./checker_Mac $ARG && ./push_swap $ARG | wc -l
# ./push_swap $ARG | ./checker $ARG && ./push_swap $ARG | wc -l
#./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l
done
