Make:
	gcc ls.c -o ls
	gcc rm.c -o rm
	gcc mkdir.c -o mkdir
	gcc date.c -o date
	gcc cat.c -o cat
	gcc Main.c -o Main -lreadline
	./Main

Clean:
	rm ls
	rm mkdir
	rm date
	rm cat
	rm rm
