/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/08 15:10:49 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
 #include <fcntl.h>


char	*get_next_line(int fd)
{
    static char BUFFER[BUFFER_SIZE];
    read(fd, BUFFER, BUFFER_SIZE);
    return (BUFFER);
}
int main()
{
    int i;
    
    i = open("file.txt", O_RDONLY);
    write(1, get_next_line(i), 2);
}
