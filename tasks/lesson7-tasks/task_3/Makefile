.PHONY:all

all: compile run

compile: main.c 
	@gcc main.c -lpthread -o ./main.out

run: main.out
	@./main.out