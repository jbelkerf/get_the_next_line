/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:41:44 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/10 15:07:03 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void    arr_free(char **arr);
char    *ft_strdup(const char *s);
char	*get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2, int n);
char    **ft_split(char const *s, int size);
int check_nwln(char *str);
int  ft_strlen(const char *str);
char *check(char *buf, char **line, int size);
#endif
