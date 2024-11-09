/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/09 17:37:32 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 2
static char buffer[BUFFER_SIZE + 1];

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

char *get_next_line(int fd)
{
    char *line;
    char **sp;
    char *buf;
    int i;
    int j;

    i = 0;
    if (fd < 0)
    return (NULL);
    line = NULL;
    buf = check(buffer, &line);
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
    if (fd < 2)
        return (NULL);
    line = NULL;
    while (!check_nwln(buffer))
    {
        i = 0;
        line = ft_strjoin(line , buffer, BUFFER_SIZE);
        while (i <= BUFFER_SIZE)
        {
            buffer[i] = 0;
            i++;
        }
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == 0 || i == -1)
        {
            i = 0;
            while (i <= BUFFER_SIZE)
            {
                buffer[i] = 0;
                i++;
            }
            return (line);
        }
    }
    if (i == 0)
        return (line);
    if (i == -1)
        return (line);
    sp = ft_split(buffer);
    line = ft_strjoin(line, sp[0], ft_strlen(sp[0]));
    j = 0;
    
    while (j < BUFFER_SIZE && sp[1][j])
    {
        buffer[j] = sp[1][j];
        j++;
    }
    buffer[j] = 0;
    if (i == 0 || i == -1)
        buffer[0] = 0;
    return (line);
}


