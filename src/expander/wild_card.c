/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_card.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:17:47 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:17:50 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	wild_match(char *str, char *expr)
{
	while (*str && *expr)
	{
		if (*expr == '*' && expr[1] == '\0')
			return (true);
		if (*expr == '*')
		{
			while (expr[1] == '*')
				expr++;
			if (wild_match(str, expr + 1))
				return (true);
			str++;
		}
		else
		{
			if (*str != *expr)
				return (false);
			str++;
			expr++;
		}
	}
	return (*str == '\0' && *expr == '\0');
}

void	wild_card(t_str **lst, t_str *expr)
{
	DIR				*dir;
	struct dirent	*file_entry;
	bool			is_hidden;
	bool			matched;

	is_hidden = expr->str[0] == '.';
	dir = opendir(".");
	matched = false;
	if (!dir)
		return ((void)closedir(dir));
	file_entry = readdir(dir);
	while (file_entry)
	{
		if ((is_hidden || file_entry->d_name[0] != '.')
			&& wild_match(file_entry->d_name, expr->str))
		{
			ft_stradd_back(lst, new_str(file_entry->d_name, false));
			matched = true;
		}
		file_entry = readdir(dir);
	}
	if (!matched)
		ft_stradd_back(lst, new_str(expr->str, false));
	closedir(dir);
}

t_str	*expand_wild_cards(t_str *argv_lst)
{
	t_str	*new_argv;
	t_str	*tmp;

	new_argv = NULL;
	while (argv_lst)
	{
		if (argv_lst->wild_card)
			wild_card(&new_argv, argv_lst);
		else
			ft_stradd_back(&new_argv, new_str(argv_lst->str, false));
		tmp = argv_lst;
		argv_lst = argv_lst->next;
		free_strnode(tmp);
	}
	return (new_argv);
}
