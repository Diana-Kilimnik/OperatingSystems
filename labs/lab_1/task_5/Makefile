.PHONY: lib LinkedList

run_linked_list: LinkedList
	@./LinkedList

LinkedList:
	@gcc -c main.c
	@gcc -o LinkedList main.o -L./make_lib -lLinkedList
	@rm main.o
