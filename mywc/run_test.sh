#!/bin/bash

norm() { tr -s ' \t' ' ' | sed 's/^ //'; }

fail=0

for file in ./test/*;
do
	wc_output=$(wc $file | norm)
	mywc_output=$(./mywc $file | norm)
	
	if [[ "$wc_output" != "$mywc_output" ]]; then
		fail=1
		printf "\nFail: $wc_output\n"
		printf "\033[0;31mFail: $mywc_output\033[0m\n"
	else
		printf "\n\033[0;32mSuccess: $file\n\033[0m"
	fi
done

exit $fail
