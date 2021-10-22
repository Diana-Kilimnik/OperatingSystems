.PHONY: lib matrix

run_matrix: matrix
	@./matrix

matrix:
	@gcc -c main.c 
	@gcc -o matrix main.o -L./make_lib -lMatrix -Wl,-rpath,./make_lib/ -lm
	@rm main.o