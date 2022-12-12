.DEFAULT_GOAL := run

run :
	cc main.c tree.c
	./a.out
	rm a.out

build :
	cc main.c tree.c
