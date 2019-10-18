#!/bin/bash

rm test_original test_toto differ test_diff

read from
read to

for  i in $(seq $from $to)
do
	../corewar ../examples/sam_2.0.cor ../examples/loose.cor -dump $i > test_toto
	/Users/nlavrine/Documents/resources/corewar ../examples/sam_2.0.cor ../examples/loose.cor -d $i > test_original
	dif=$(diff test_toto test_original)
	echo $i >> test_diff
	diff test_toto test_original >> test_diff
	# if [ $dif ]
	# then
	# 	echo $i >> differ
	# 	echo $dif >> differ
	# fi
done

