/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:41:44 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/09 13:23:32 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFFER_SIZE 2

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *ft_strdup(const char *s);
char	*get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2, int n);
char    **ft_split(char const *s);
void    ft_putstr(char *str);
int check_nwln(char *str);
int  ft_strlen(const char *str);
#endif
