/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:18:04 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:18:06 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GET_EXIT 0xdeadbeef

#include <hacks.h>

int	exit_status_trolling(unsigned int action)
{
	static int	exit_status;

	if (action != GET_EXIT)
		exit_status = action;
	return (exit_status);
}

void	set_exit_status(unsigned int exit_status)
{
	exit_status_trolling(exit_status);
}

int	get_exit_status(void)
{
	return (exit_status_trolling(GET_EXIT));
}

char	*make_dangling(unsigned long long dick_len)
{
	char			*dick;
	uint64_t		dick_idx;
	const uint64_t	dick_size = 2 + dick_len + 1;

	dick = ft_malloc(dick_size);
	dick[0] = '8';
	dick_idx = 1;
	while (dick_idx < dick_size - 2)
		dick[dick_idx++] = '=';
	dick[dick_idx++] = '>';
	dick[dick_idx] = '\0';
	return (dick);
}
