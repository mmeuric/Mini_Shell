/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:05:18 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:05:20 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	print_escape(FILE *f, char *str)
{
	while (*str)
	{
		if (*str == '\'')
			fprintf(f, "%s", "\\\'");
		else if (*str == '\"')
			fprintf(f, "%s", "\\\"");
		else
			fprintf(f, "%c", *str);
		str++;
	}
}

void	print_nosp_tok(FILE *f, t_token *tok)
{
	while (tok)
	{
		print_escape(f, tok->value);
		tok = tok->nospace_next;
	}
}

void	debug_tree(t_ast_cmd *head, FILE *f, int index)
{
	if (!head)
		fprintf(f, "	n%d[fontcolor=blue label=\"NULL\"];\n", index);
	else if (head->type == P_AND || head->type == P_OR || head->type == P_PIPE)
		debug_binary((t_ast_binary *)head, f, index);
	else if (head->type == P_REDIR)
		debug_redir((t_ast_redir *)head, f, index);
	else if (head->type == P_EXEC)
		debug_exec((t_ast_exec *)head, f, index);
	else if (head->type == P_SUBSH)
		debug_subsh((t_ast_subsh *)head, f, index);
}

#ifdef DEBUG

void	debug_ast(t_ast_cmd *head, char *cmd)
{
	FILE	*f;

	f = fopen("tree.dot", "w");
	if (!f)
		return ((void)printf("Couldn't open file !"));
	fprintf(f, "digraph yep {\n");
	fprintf(f, "	label=\"");
	print_escape(f, cmd);
	fprintf(f, "\"\n");
	debug_tree(head, f, 0);
	fprintf(f, "}\n");
	fclose(f);
}

#else

void	debug_ast(t_ast_cmd *head, char *cmd)
{
	(void)head;
	(void)cmd;
}

#endif
