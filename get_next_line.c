/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/08 18:40:42 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    static char buffer[BUFFER_SIZE];

    line = "";
    read(fd, buffer, BUFFER_SIZE);
    while (!check_nwln(buffer))
    {
        line = ft_strjoin(line, buffer);
        read(fd, buffer, BUFFER_SIZE);
    }
    line = ft_strjoin(line, buffer);
    return (buffer);
}

int main()
{
    int i;
    int j = 0;
    
    i = open("file.txt", O_RDONLY);
    while (j < 4)
    {
        ft_putstr(get_next_line(i));
        j++;
    }
}
