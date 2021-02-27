/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:45:32 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/27 13:40:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MANDATORY
# include "../get_next_line.h"
#elif BONUS
# include "../get_next_line_bonus.h"
#endif
#include <fcntl.h>
#include <stdio.h>

void	check_gnl_file(char *src)
{
	char	*line;
	int		fd;
	int		readvalue;

	readvalue = 1;
	line = NULL;
	printf("* * * * * * TEST |%s| * * * * *\n", src);
	fd = open(src, O_RDONLY);
	while (readvalue > 0)
	{
		readvalue = get_next_line(fd, &line);
		printf("[%d]: %s\n", readvalue, line);
		free(line);
		line = NULL;
	}
	printf("* * * * * * END * * * * *\n\n");
}

void	check_gnl_file_bonus(int count, char **src)
{
	char	*line;
	int		fd[count];
	int		readval[count];

	printf("* * * * * * TEST * * * * *\n");
	for (int i = 0; i < count - 1; i++)
		fd[i] = open(src[i + 1], O_RDONLY);
	while (readval[0] > 0 || readval[1] > 0 || readval[2] > 0)
	{
		for (int i = 0; i < count - 1; i++)
		{
			readval[i] = get_next_line(fd[i], &line);
			printf("[%d]: %s\n", readval[i], line);
		}
	}
	printf("* * * * * * END  * * * * *\n\n");
}

#ifdef MANDATORY
int		main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
		check_gnl_file(argv[i]);
	return (0);
}
#elif BONUS
int		main(int argc, char *argv[])
{
	check_gnl_file_bonus(argc, argv);
	return (0);
}
#endif
