#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd1, fd2, fd3;

	fd1 = open("files/bonus_test01_with_lines", O_RDONLY);
	fd2 = open("files/bonus_test02_with_lines", O_RDONLY);
	fd3 = open("files/bonus_test03_with_lines", O_RDONLY);

	//FD 01
	printf("FD01 | First Line | FD return %s\n", get_next_line(fd1));

	//FD02
	printf("FD02 | First Line | FD return %s\n", get_next_line(fd2));

	//FD03
	printf("FD03 | First Line | FD return %s\n", get_next_line(fd3));

	//FD01 Seconda Line
	printf("FD01 | Second Line | FD return %s\n", get_next_line(fd1));

	//FD03 Second Line
	printf("FD03 | Second Line | FD return %s\n", get_next_line(fd3));

	//FD03 Third Line
	printf("FD03 | Third Line | FD return %s\n", get_next_line(fd3));
}