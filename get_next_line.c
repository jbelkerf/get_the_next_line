/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/10 16:04:12 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 2

void    arr_free(char **arr)
{
    int i;
    
    i = 0;
    while (i < 2)
    {
        free(arr[0]);
        i++;
    }
    free(arr);
}

void    empty_buf(char *buf, int size)
{
    int i;
    
    i = 0;
    while (i < size && buf[i])
    {
        buf[i] = 0;
        i++;
    }
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    char *buf;
    int i;
    int size = BUFFER_SIZE;

    if (fd < 0)
        return (NULL);
    i = 0;
    line = NULL;
    buf = check(buffer, &line, size);
    if (buf != 0)
    {
        while (buf[i])
        {
            buffer[i] = buf[i];
            i++;
        }
        buffer[i] = 0;
        return (line);
    }
    while (!buf)
    {
        i = 0;
        line = ft_strjoin(line , buffer, BUFFER_SIZE);
        empty_buf(buffer, size);
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == 0 || i == -1)
        {
            empty_buf(buffer, size);
            return (line);
        }
        buf = check(buffer, &line, size);
        if (buf != 0)
        {
            while (buf[i])
            {
               buffer[i] = buf[i];
               i++;
            }
            buffer[i] = 0;
            return (line);
        }
    }
    return (NULL);
}


