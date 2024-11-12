/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/12 18:26:13 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif
int check(char *buf)
{
        int i;

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

char *do_the_job(char **left, char **line, int separator, int f)
{
    char *tmp;

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


char *get_next_line(int fd)
{
    static char *left;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    char *tmp;
    int i;
    int read_bytes;

    line = NULL;
    i = -1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
        if (left != NULL)
        {
            if (*left != 0)
            {
                i = check(left);
            }
        }
    if (i > 0)
    {
        tmp = left;
        line = do_the_job(&left, &line,i, 1);
        if (*left == 0)
        {
            free(left);
            left = NULL;
        }
        return(line);
    }
    else if (i == 0)
    {
        line = ft_strjoin(line, left);
        free(left);
        left = NULL;
    }
    while (1)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
            return (NULL);
        if (read_bytes == 0)
        {
            if (left != NULL)
                if (left != 0)
                {
                    line = ft_strjoin(line, left);
                    free(left);
                    left = NULL;
                }
                if (line == NULL || *line == 0)
                    return (NULL);
            return (line);
        }
        buffer[read_bytes] = 0;
        line = ft_strjoin(line, buffer);
        i = check(line);
        if (i)
        {
            line = do_the_job(&left, &line, i, 2);
            if (line == NULL || *line == 0)
                    return (NULL);
            if (*left == 0)
            {
                free(left);
                left = NULL;
            }
            return (line);
        }
    }
    return (NULL);
}


