#!/bin/bash

rm test_original test_toto differ test_diff

read from
read to

for  i in $(seq $from $to)
do
	../corewar ../champs/championships/2014/gudepard/Kappa.cor ../champs/championships/2014/srabah-m/littlepuppy.cor ../champs/championships/2014/fcorre/ultimate-surrender.cor ../champs/examples/zork.cor -dump $i > test_toto
	/Users/nlavrine/Documents/resources/corewar  ../champs/championships/2014/gudepard/Kappa.cor ../champs/championships/2014/srabah-m/littlepuppy.cor ../champs/championships/2014/fcorre/ultimate-surrender.cor ../champs/examples/zork.cor -d $i > test_original
	# ../corewar ../champs/championships/2014/clafleur/big_feet.cor ../champs/bot_kompot.cor ../champs/examples/bigzork.cor ../champs/championships/2014/clafleur/big_feet.cor -dump $i > test_toto
	# /Users/nlavrine/Documents/resources/corewar ../champs/championships/2014/clafleur/big_feet.cor ../champs/bot_kompot.cor ../champs/examples/bigzork.cor ../champs/championships/2014/clafleur/big_feet.cor -d $i > test_original
	dif=$(diff test_toto test_original)
	echo $i >> test_diff
	diff test_toto test_original >> test_diff
done

