.name		"Boss"
.comment	"chick chick"

ld %1, r2
ld %100728832, r3

ld	%-448, r4
ld	%16, r5

wow:
fork %:rebase

pakosti_up:
	sti r2, r4, %0
	sti r1, r4, %-2
	live %10
	add r4, r5, r4
	zjmp %-200
	ld %0, r6
	zjmp %:pakosti_up


rebase:
	live %10
	ld %448, r4
	ld %16, r5

pakosti_down:
	sti r2, r4, %0
	sti r1, r4, %-2
	live %10
	sub r4, r5, r4
	zjmp %:wow
	ld %0, r6
	zjmp %:pakosti_down


