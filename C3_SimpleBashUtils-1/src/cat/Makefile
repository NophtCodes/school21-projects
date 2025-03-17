SHELL := /bin/bash
FLAG = -Wall -Wextra -Werror
FILE = file1.txt
CHECK = 2>&1 valgrind --tool=memcheck --leak-check=yes

all: s21_cat tests
s21_cat: clean
	gcc $(FLAG) s21.cat.c -o s21_cat
	
tests: 
	-diff <(./s21_cat $(FILE)) <(cat$(FILE))
	-diff <(./s21_cat -e $(FILE)) <(cat -e $(FILE))
	-diff 