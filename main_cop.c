#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd, ret, line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("[ Return: %d ] | Line #%d has been read  => %s\n", ret, line_count, line);
			line_count++;
			free(line);
		}
		printf("[ Return: %d ] | Line #%d has been read  => %s\n", ret, line_count, line);
		if (ret == -1)
			printf("-----------\n An error happened\n");
		else if (ret == 0)
		{
			printf("-----------\n EOF has been reached\n");
			free(line);
		}
		close(fd);
	}
	if (ac == 1)
	{
		printf("Please enter your text to be read:\n");
		while ((ret = get_next_line(0, &line)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
			line_count++;
		}
		if (ret == -1)
			printf("\n An error happened\n");
		else if (ret == 0)
			printf("\n EOF has been reached\n");
		close(fd);
	}
	return (0);
}