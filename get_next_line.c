/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/09 11:27:29 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    char **sp;
    int i;
    int j;
    static char buffer[BUFFER_SIZE + 1];

    line = "";
    if (buffer[0] != 0)
        line = ft_strjoin(line , buffer, BUFFER_SIZE);
    i = read(fd, buffer, BUFFER_SIZE);
    if (i == 0)
        return ("");
    while (!check_nwln(buffer) && i != -1 && i != 0)
    {
        line = ft_strjoin(line , buffer, BUFFER_SIZE);
        i = read(fd, buffer, BUFFER_SIZE);
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

int main()
{
    int i;
    int j = 0;
    
    i = open("file.txt", O_RDONLY);
    while (j < 10)
    {
        ft_putstr(get_next_line(i));
        j++;
    }
}
