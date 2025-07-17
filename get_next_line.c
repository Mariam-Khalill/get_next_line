/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markhali <markhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:35:20 by markhali          #+#    #+#             */
/*   Updated: 2025/07/01 16:58:57 by markhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	*head;
	int				i;
	int				r;

	while (!endline(head))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free_list(&head), NULL);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
		{
			free(buffer);
			if (!head)
				return (NULL);
			return (init_end(&head));
		}
		buffer[r] = '\0';
		i = -1;
		while (++i < r)
			init_list(&head, buffer[i]);
		free(buffer);
	}
	return (init_end(&head));
}
