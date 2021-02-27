#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#include <stdio.h>
int	main()
{
	int	fd;
	int	ret;
	char	*line;

	fd = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			free(line);
			break ;
		}
		printf("[%d]: %s\n", ret, line);
		free(line);
	}
	close(fd);
	free(line);
	return (0);
}
