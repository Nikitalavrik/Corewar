.name		"Koala"
.comment	"So lazy that ........"

ld %218099713, r2
ld %4294967294, r3
ld %190054918, r4
ld %168514563, r5
ld %101124948, r12
ld %67504139,  r13
ld %200, r6
ld %-1, r7
ld %-2, r8
ld %-3, r9
ld %-4, r14
ld %-5, r15
ld %128, r11
ld %4, r16
fork %:wow
start:
	live %-1
	sti r2, r6, r10
	sti r3, r6, r7
	sti r4, r6, r8
	sti r5, r6, r9
	sti r12, r6, r14
	sti r13, r6, r15

toto:
	add r6, r11, r6
	add r16, r7, r16
	zjmp %:zmp
	ld %0, r10
	zjmp %:start

wow:
	ld %224, r6
	ld %1409615369, r2
	ld %190057478,  r3
	ld %235623437, 	r4
	ld %101646992, 	r5
	ld %0, 			r12
	ld %167722240, r13
	ld %0, r10
	zjmp %:start

zmp: live %10

