/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/13 17:04:14 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

void	*free_p(char **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
	return (NULL);
}

int	check(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*do_the_job(char **left, char **line, int separator, int f)
{
	char	*tmp;

	if (f == 1)
	{
		tmp = *left;
		*line = ft_substr(*left, 0, separator);
		*left = ft_substr(*left, separator, BUFFER_SIZE);
		free(tmp);
		tmp = NULL;
		return (*line);
	}
	else
	{
		tmp = *line;
		*line = ft_substr(tmp, 0, separator);
		*left = ft_substr(tmp, separator, BUFFER_SIZE);
		free(tmp);
		tmp = NULL;
		return (*line);
	}
}

int	check_left(char **left, char **line)
{
	int	i;

	i = -1;
	if (*left != NULL)
	{
		if (**left != 0)
		{
			i = check(*left);
		}
	}
	if (i > 0)
	{
		*line = do_the_job(left, line, i, 1);
		if (**left == 0)
			free_p(left);
		return (1);
	}
	else if (i == 0)
	{
		*line = ft_strjoin(*line, *left);
		free_p(left);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_left(&left, &line))
		return (line);
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_p(&line));
		if (read_bytes == 0)
		{
			if (left != NULL)
			{
				line = ft_strjoin(line, left);
				free_p(&left);
			}
			if (line == NULL || *line == 0)
				return (NULL);
			return (line);
		}
		buffer[read_bytes] = 0;
		line = ft_strjoin(line, buffer);
		read_bytes = check(line);
		if (read_bytes)
		{
			line = do_the_job(&left, &line, read_bytes, 2);
			if (line == NULL || *line == 0)
				return (NULL);
			if (*left == 0)
				free_p(&left);
			return (line);
		}
	}
	return (NULL);
}
