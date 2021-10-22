.PHONY: lib

lib: 
	@gcc -c -FPIC struct.c
	@gcc -shared -o libStruct.so *.o
	@rm *.o