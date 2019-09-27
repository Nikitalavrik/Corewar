.name		"Koala"
.comment	"So lazy that ........"


ld %33554431, r6
ld %4262155270, r9
ld %50858495, r11
ld %939655167, r4
ld %215, r8
ld %-1, r10
ld %-2, r12
ld %-3, r15
ld %4, r2
fork %:pakosti
start:
	live %-1
	sti r6, r3, r8
	sti r9, r10, r8
	sti r11, r12, r8
	sti r4, r15, r8
	live %-2
	add r8, r8, r8
	add r2, r10, r2
	live %-3
	live %-4
	zjmp %:goforward
	ld %0, r3
	zjmp %:start


pakosti:
	ld %-200, r8
	ld %0, r3
	live %-1
	zjmp %:start

goforward:
	live %-1
	fork %:start
