/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/08 19:36:56 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i])
        {
                i++;
        }
        return (i);
}
size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
        size_t  i;

        if (size == 0)
                return (ft_strlen(src));
        i = 0;
        while (i < size - 1 && src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = 0;
        return (ft_strlen(src));
}
size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
        size_t  i;
        size_t  j;

        if (size == 0)
                return (ft_strlen(src));
        i = ft_strlen(dst);
        j = 0;
        if (ft_strlen(dst) >= size)
                return (size + ft_strlen(src));
        if (size != 0)
        {
                while (i < size - 1 && src[j])
                {
                        dst[i] = src[j];
                        i++;
                        j++;
                }
                dst[i] = 0;
        }
        return (i - j + ft_strlen(src));
}
char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *re;

        if (s1 == NULL || s2 == NULL)
                return (NULL);
        re = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
        if (re == NULL)
                return (NULL);
        ft_strlcpy(re, s1, ft_strlen(s1) + 1);
        ft_strlcat(re, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
        return (re);
}

int check_nwln(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == '\n')
            return (i + 1);
        i++;
    }
    return (0);
}

void    ft_putstr(char *str)
{
    int i;

    if (str == NULL)
        ft_putstr("{null}");
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
 


char    **ft_split(char const *s)
{
        char    **re;
        int i;
        int j;
        int k;

        k = 0;
        i = 0;
        j = 0;
        if (s == NULL)
                return (NULL);
        while (s[i] && s[i] != '\n')
            i++;
        while (s[i + j + 1])
            j++;
        re = malloc(2 * sizeof(char *));
        re[0] = malloc((i + 1) * sizeof(char));
        re[1] = malloc((j + 1) * sizeof(char));
        while (k < i)
        {
            re[0][k] = s[k];
            k++;
        }
        re[0][k] = 0;
        k = 0;
        while(k < j)
        {
            re[1][k] = s[k + i + 1];
            k++;
        }
        re[1][k] = 0;
        return (re);
}
