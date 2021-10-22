.PHONY: lib arrCalc

run_arrCalc: arrCalc
	@./arrCalc

arrCalc:
	@gcc -c main.c 
	@gcc -o arrCalc main.o -L./make_lib -lArrCalculations -lm 
	@rm main.o