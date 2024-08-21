SRC = bsq.c find_solution.c functions.c get_chars.c print_solution.c read_map.c verify_map.c

all:
	cc -Wall -Wextra -Werror $(SRC) -o bsq
	
clean:
	rm -f *.o

fclean: clean
	rm -f bsq
	
re: fclean all
