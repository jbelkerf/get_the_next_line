/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/12 18:50:01 by jbelkerf         ###   ########.fr       */
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

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*re;
	int		i;
	int		j;

	j = 0;
	i = 0;
        if (s1 == NULL)
                s1 = ft_strdup("");
	re = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (re == NULL)
		return (NULL);
	while (s1[i])
	{
		re[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		re[j] = s2[i];
		i++;
		j++;
	}
	re[j] = 0;
        free(s1);
        s1 = NULL;
        return (re);
}
