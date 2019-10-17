.name		"Koala"
.comment	"So lazy that ........"


ld %190055943, r6
ld %134960137, r9
ld %168299348, r11
ld %185337856, r4
ld %215, r8
ld %-1, r10
ld %-2, r12
ld %-3, r15
ld %5, r2
fork %:pakosti
start:
	live %-1
<<<<<<< HEAD
	sti r6, r7
	sti r9, r10
	sti r11, r12
	sti r4, r15
	sti r6, r7
	sti r9, r10
	sti r11, r12
	sti r4, r15
	sti r6, r7
	live %-2
	sti r9, r10, r8
	sti r11, r12, r8
	sti r4, r15, r8
	sti r6, r7, r8
	sti r9, r10, r8
	sti r11, r12, r8
	live %-3
	sti r4, r15, r8
	sti r6, r7, r8
	sti r9, r10, r8
	sti r11, r12, r8
	sti r4, r15, r8
=======
	st r6, r7
	st r9, r10
	st r11, r12
	st r4, r15
	st r6, r7
	st r9, r10
	st r11, r12
	st r4, r15
	st r6, r7
	live %-2
	st r9, r10, r8
	st r11, r12, r8
	st r4, r15, r8
	st r6, r7, r8
	st r9, r10, r8
	st r11, r12, r8
	live %-3
	st r4, r15, r8
	st r6, r7, r8
	st r9, r10, r8
	st r11, r12, r8
	st r4, r15, r8
>>>>>>> master
	add r8, r8, r8
	add r2, r10, r2
	zjmp %:goforward
	ld %0, r3
	live %-4
	zjmp %:start 

pakosti:
	ld %-200, r8
	ld %0, r3
	zjmp %:start

goforward:
	live %1
	sti r6, r7, r8
	sti r9, r10, r8
	sti r11, r12, r8
	sti r4, r15, r8
