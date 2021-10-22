.PHONY: lib

lib: 
	@gcc -c -FPIC matrix.c
	@gcc -shared -o libMatrix.so *.o
	@rm *.o