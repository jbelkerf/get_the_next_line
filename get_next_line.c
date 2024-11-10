/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:40:04 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/10 23:02:11 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 2

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

char *do_the_job(char **buffer, char **line, char *tmp, int separator)
{
    *line = ft_substr(*buffer, 0, separator);
    *buffer = ft_substr(*buffer, separator, BUFFER_SIZE);
    //free(tmp);
    tmp = *buffer;
    return (*line);
}
char *do_the_job2(char **buffer, char **line, int separator)
{
    char *tmp;
    
    tmp = *line;
    *line = ft_substr(tmp, 0, separator);
    *buffer = ft_substr(tmp, separator, BUFFER_SIZE);
    tmp = *buffer;
    //free(tmp);
    return (*line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *tmp;
    char *line;
    int i;
    int read_bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    tmp = buffer;
    i = check(buffer);
    if (i)
        return(do_the_job(&buffer, &line, tmp, i));
    else
        line = buffer;
    while (1)
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (buffer == NULL)
            return (NULL);
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[read_bytes] = 0;
        if (read_bytes == -1)
            return (NULL);
        if (read_bytes == 0)
        {
            //free(buffer);
                return (line);
        }
        line = ft_strjoin(line, buffer);
        i = check(line);
        if (i)
        {
            line = do_the_job2(&buffer, &line, i);
            return (line);
        }
    }
    return (NULL);
}


