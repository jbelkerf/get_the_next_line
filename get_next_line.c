/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/08 20:33:40 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    char **sp;
    int i;
    static char buffer[BUFFER_SIZE];

    line = "";
    if (buffer[0] != 0)
    {
        line = ft_strjoin(line , buffer);
    }
    i = read(fd, buffer, BUFFER_SIZE);
    if (i == 0)
        return ("");
    while (!check_nwln(buffer) && i != -1 && i != 0)
    {
        line = ft_strjoin(line, buffer);
        i = read(fd, buffer, BUFFER_SIZE);
    }
    if (i == 0)
        return (line);
    if (i == -1)
    {
        return (line);
    }
    sp = ft_split(buffer);
    line = ft_strjoin(line, sp[0]);
    i = 0;
    while (i < BUFFER_SIZE && sp[i])
    {
        buffer[i] = sp[1][i];
        i++;
    }
    return (line);
}

int main()
{
    int i;
    int j = 0;
    
    i = open("file.txt", O_RDONLY);
    while (j < 6)
    {
        ft_putstr(get_next_line(i));
        write(1, "\n", 1);
        j++;
    }
}
