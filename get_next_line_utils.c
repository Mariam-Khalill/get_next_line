/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markhali <markhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:43:29 by markhali          #+#    #+#             */
/*   Updated: 2025/07/01 16:39:11 by markhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endline(t_list *head)
{
	while (head)
	{
		if (head->content == '\n')
			return (1);
		head = head->next;
	}
	return (0);
}

void	init_list(t_list **head, char c)
{
	t_list	*node;
	t_list	*temp;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->content = c;
	node->next = NULL;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = (*head);
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;
}

char	*init_end(t_list **head)
{
	char	*end;
	t_list	*temp;
	int		i;

	if (!*head)
		return (NULL);
	end = malloc(get_size(*head) + 1);
	if (!end)
		return (free_list(head), NULL);
	i = 0;
	while (*head)
	{
		end[i++] = (*head)->content;
		temp = *head;
		*head = (*head)->next;
		free(temp);
		if (end[i - 1] == '\n')
			break ;
	}
	end[i] = '\0';
	return (end);
}

int	get_size(t_list *head)
{
	int	i;

	i = 0;
	while (head && head->content != '\n')
	{
		head = head->next;
		i++;
	}
	if (head && head->content == '\n')
		i++;
	return (i);
}

void	free_list(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
