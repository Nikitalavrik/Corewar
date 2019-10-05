#!/bin/bash

rm test_original test_toto differ
read from
read to

for  i in $(seq $from $to)
do
	./corewar examples/toto.cor -d $i > test_toto
	../../resources/corewar examples/toto.cor -d $i > test_original
	echo $i >> differ
	diff test_toto test_original >> differ
done