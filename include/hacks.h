/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hacks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:30:51 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:30:53 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HACKS_H
# define HACKS_H
# include <libft.h>

enum
{
	ATTR_SET,
	ATTR_GET,
	ATTR_CHG
};

void	set_exit_status(unsigned int exit_status);
int		get_exit_status(void);
char	*make_dangling(unsigned long long dick_len);
#endif
