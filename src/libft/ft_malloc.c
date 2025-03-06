/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:34:09 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:34:11 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "shell69: MALLOC FAILED BRO !\n", 29);
		exit(69);
	}
	return (ptr);
}
