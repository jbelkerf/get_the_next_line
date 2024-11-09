/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/09 17:09:55 by jbelkerf         ###   ########.fr       */
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

char    *ft_strjoin(char  *s1, char  *s2, int n)
{
        char    *re;
        int     i;

        i = 0;
        if (s1 == NULL)
                s1 = "";
        re = (char *)malloc((ft_strlen(s1) + n + 1) * sizeof(char));
        if (re == NULL)
                return (NULL);
        while (s1[i])
        {
                re[i] = s1[i];
                i++;
        }
        while (i < ft_strlen(s1) + n && s2[i - ft_strlen(s1)])
        {
                re[i] = s2[i - ft_strlen(s1)];
                i++;
        }
        re[i] = 0;
        if (*s1 != '\0')
                free(s1);
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
        re[0] = malloc((i + 2) * sizeof(char));
        re[1] = malloc((j + 1) * sizeof(char));
        while (k <= i)
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

char *check(char *buf, char **line)
{
        int     i;
        char    **re;

        i = 0;
        while (buf[i])
        {
                if (buf[i] == '\n')
                    break;
                i++;
        }
        if (buf[i] == '\n')
        {
            re = ft_split(buf);
            *line = ft_strjoin(*line, re[0], ft_strlen(re[0]));
            i = 0;
            while (re[i])
            {
                buf[i] = re[1][i];
                i++;
            }
            buf[i] = 0;
            return (buf);
        }
        return (0);
}