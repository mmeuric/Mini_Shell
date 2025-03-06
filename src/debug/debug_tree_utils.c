/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:05:08 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:05:10 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	debug_binary(t_ast_binary *head, FILE *f, int index)
{
	const char	*binaries[3] = {"&&", "||", "|"};

	fprintf(f, "	n%d[fontcolor=chocolate1 label=\"%s\"];\n",
		index,
		binaries[head->type]);
	fprintf(f, "	n%d -> n%d;\n", index, 2 * index + 1);
	fprintf(f, "	n%d -> n%d;\n", index, 2 * index + 2);
	debug_tree(head->left, f, 2 * index + 1);
	debug_tree(head->right, f, 2 * index + 2);
}

void	debug_redir(t_ast_redir *head, FILE *f, int index)
{
	const char	*redirs[4] = {">", ">>", "<", "<<"};

	fprintf(f, "	n%d[fontcolor=crimson label=\"%s ",
		index,
		redirs[head->direction - 3]);
	print_nosp_tok(f, head->file_tok);
	fprintf(f, "\"];\n");
	fprintf(f, "	n%d -> n%d;\n", index, 2 * index + 1);
	debug_tree(head->cmd, f, 2 * index + 1);
}

void	debug_exec(t_ast_exec *head, FILE *f, int index)
{
	t_token	*argv_tok;

	argv_tok = head->argv_tok;
	fprintf(f, "	n%d[label=\"", index);
	while (argv_tok)
	{
		print_nosp_tok(f, argv_tok);
		fprintf(f, " ");
		argv_tok = argv_tok->next;
	}
	fprintf(f, "\"];\n");
}

void	debug_subsh(t_ast_subsh *head, FILE *f, int index)
{
	fprintf(f, "	n%d[fontcolor=darkturquoise label=\"%s ",
		index,
		"(SUBSH)");
	fprintf(f, "\"];\n");
	fprintf(f, "	n%d -> n%d;\n", index, 2 * index + 1);
	debug_tree(head->cmd, f, 2 * index + 1);
}
