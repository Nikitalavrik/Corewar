.name		"Celebration Funebre v0.99pl42"
.comment	"Jour J"

		ld   %0,r3
label:		zjmp %:avantdebut
		zjmp %0				# pour eviter ecrasement
						# de l'instruction suivante

avantdebut:	zjmp %:code  # 		#7

code:	live %42			# 5
		ld	%10, r2
		st  r2, r7			# 6
		ld	%19, r5
		add r2, r7, r3
		sub r3, r5, r4
		
		and %8, r2, r12
		and r2, %8, r11
		and %8, %10, r10 
		and r5, r2, r9
		and 0, r5, r16
		and 0, 0, r8
		and %10, 511, r8



