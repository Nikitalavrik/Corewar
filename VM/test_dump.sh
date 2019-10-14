#!/bin/bash

rm test_original test_toto differ test_diff
read from
read to

for  i in $(seq $from $to)
do
	./corewar examples/asm/test.cor -d $i > test_toto
	../../resources/corewar examples/asm/test.cor -d $i > test_original
	dif=$(diff test_toto test_original)
	echo $i >> test_diff
	diff test_toto test_original >> test_diff
	# if [ $dif ]
	# then
	# 	echo $i >> differ
	# 	echo $dif >> differ
	# fi
done