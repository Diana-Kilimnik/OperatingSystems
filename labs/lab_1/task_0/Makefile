.PHONY:all

all: compile run

compile: main.c 
	@gcc main.c findPoint.c -lm -o ./main.out

run: main.out
	@./main.out