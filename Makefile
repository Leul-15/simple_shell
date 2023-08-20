FLAGS = -ggdb -Wall -pedantic -Werror -Wextra -std=gnu89

make:
	gcc $(FLAGS) *.c -o hsh
