/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/10 22:30:38 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int  ft_strlen(const char *str)
{
        int  i;

        i = 0;
        while (str[i])
        {
                i++;
        }
        return (i);
}
char    *ft_strdup(const char *s)
{
        char    *re;

        re = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
        if (re == NULL)
                return (NULL);
        ft_strlcpy(re, s, ft_strlen(s) + 1);
        return (re);
}

int  ft_strlcpy(char *dest, const char *src, int size)
{
        int  i;

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
int  ft_strlcat(char *dst, const char *src, int size)
{
        int i;
        int j;

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
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        unsigned int    len_s;
        char                    *sub;

        if (s == NULL)
                return (NULL);
        len_s = ft_strlen(s);
        if (len_s < start)
                return (ft_strdup(""));
        if (len_s - start < len)
                len = len_s - start;
        sub = (char *)malloc((len + 1) * sizeof(char));
        if (sub == NULL)
                return (NULL);
        ft_strlcpy(sub, s + start, len + 1);
        return (sub);
}
char    *ft_strjoin(char *s1, char *s2)
{
        char    *re;

        if (s1 == NULL)
                s1 = "";
        re = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
        if (re == NULL)
                return (NULL);
        ft_strlcpy(re, s1, ft_strlen(s1) + 1);
        ft_strlcat(re, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
        if (*s1 != 0)
                free(s1);
        if (*s2)
                free(s2);
        return (re);
}
