/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:29:54 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:29:56 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	debug_ast(t_ast_cmd *head, char *cmd);
void	debug_tree(t_ast_cmd *head, FILE *f, int index);

/* Utils */
void	debug_binary(t_ast_binary *head, FILE *f, int index);
void	debug_redir(t_ast_redir *head, FILE *f, int index);
void	debug_exec(t_ast_exec *head, FILE *f, int index);
void	debug_subsh(t_ast_subsh *head, FILE *f, int index);
