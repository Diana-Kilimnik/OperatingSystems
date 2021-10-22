.PHONY: lib function

run_function: function
	@./function

function:
	@gcc -c main.c 
	@gcc -o function main.o -L./make_lib -lFunction -lm 
	@rm main.o