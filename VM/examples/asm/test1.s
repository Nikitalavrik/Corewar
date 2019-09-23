.name		"BigBob"
.comment	"chick chick"

		ld   %0,r3
label:		zjmp %:avantdebut
			zjmp %0				

avantdebut:	zjmp %:code  # 		#7

code:	live %-1			# 5
		ld	%10, r2
		ld  %3, r4
		ld  %1, r5
		ld %15, r6
		and %10, r6, r7
		and r2, r6, r8
		and r4, r6, r9
		and 50, r6, r10
		or %10, r6, r7
		or r2, r6, r8
		or r4, r6, r9
		or 50, r6, r10
		xor %10, r6, r7
		xor r2, r6, r8
		xor r4, r6, r9
		xor 50, r6, r10
		live %-1

