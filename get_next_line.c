/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/08 17:04:55 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    t_list  *l;

    read(fd, buffer, BUFFER_SIZE);
    
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
