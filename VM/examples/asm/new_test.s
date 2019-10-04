.name		"BisssgBob"
.comment	"chick chick"

roll:
sti r2, r3, r2
xor r2, r2, r3
live %-1

live %-2
add r2, r2, r3
live %-3
add r2, r2, r3
live %-4
xor r2, r2, r3
lldi 50, %10, r10
ld %0, r2
fork %:roll
zjmp %:roll
