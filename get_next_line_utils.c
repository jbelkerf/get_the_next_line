/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:58:48 by jbelkerf          #+#    #+#             */
/*   Updated: 2024/11/08 17:04:35 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void    ft_putstr(char *str)
{
    int i;

    if (str = NULL)
        ft_pustr("{null}");
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *last;

        if (!new || !lst)
                return ;
        if (!*lst)
                *lst = new;
        else
        {
                last = ft_lstlast(*lst);
                last->next = new;
        }
}

t_list  *ft_lstnew(char *content)
{
        t_list  *new;

        new = (t_list *)malloc(1 * sizeof(t_list));
        if (new == 0)
                return (0);
        new->content = content;
        new->next = NULL;
        return (new);
}