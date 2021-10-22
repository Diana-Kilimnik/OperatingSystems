.PHONY: lib struct

run_struct: struct
	@./struct

struct:
	@gcc -c main.c 
	@gcc -o struct main.o -L./make_lib -lStruct -Wl,-rpath,./make_lib/
	@rm main.o
