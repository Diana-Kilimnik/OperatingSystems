.PHONY: lib ArrayList

run_array_list: ArrayList
	@./ArrayList

ArrayList:
	@gcc -c main.c
	@gcc -o ArrayList main.o -L./make_lib -lArrayList
	@rm main.o
