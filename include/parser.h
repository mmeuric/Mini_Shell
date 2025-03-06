/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:31:28 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:31:29 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ast.h"
# include "debug.h"
# include "lexer.h"
# include "error.h"
# include "heredoc.h"

bool	parser(t_token *tokens, char *cmd, t_ast_cmd **tree);

#endif // PARSER_H
