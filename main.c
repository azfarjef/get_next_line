#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd, line_count;
	char *ret;

	line_count = 1;
	ret = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd)) != 0)
		{
			printf("Line #%d has been read  => %s\n", line_count, ret);
			line_count++;
		}
		printf("Line #%d has been read  => %s\n", line_count, ret);
		if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
		}
		close(fd);
	}
	if (ac == 1)
	{
		printf("Please enter your text to be read:\n");
		while ((ret = get_next_line(0)) != 0)
		{
			printf("Line #%d has been read  => %s\n", line_count, ret);
			line_count++;
		}
		printf("Line #%d has been read  => %s\n", line_count, ret);
		if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
		}
		close(fd);
	}
	return (0);
}