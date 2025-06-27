/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:53:57 by mugenan           #+#    #+#             */
/*   Updated: 2025/06/28 01:29:12 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	has_unclosed_quotes(const char *str)
{
	int	s_quote = 0;
	int	d_quote = 0;

	while (*str)
	{
		if (*str == '\'' && d_quote == 0)
			s_quote = !s_quote;
		else if (*str == '"' && s_quote == 0)
			d_quote = !d_quote;
		str++;
	}
	return (s_quote || d_quote);
}

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	(void)env;
	char *input;
	t_token *token_list;
	token_list = NULL;
	while (1)
	{
		input = readline("\001\033[1;36m\002minishell$ \001\033[0m\002");
		if (!input)
		{
			printf("exit\n"); 
			break;
		}
		if (*input)
			add_history(input);
		printf("input: %s\n", input);
		token_list = lexer(input);
		printf("token_list: %s \n", token_list->value);
		// command_table = parser(token_list);
		// executor(command_table);
		free(input);
	}
	return (0);
}

/*  Sources

	https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
	https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218
	https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html
	https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
	https://github.com/Swoorup/mysh
*/

/*
	Your shell must implement the following built-in commands:
		◦ echo with option -n
		◦ cd with only a relative or absolute path
		◦ pwd with no options
		◦ export with no options
		◦ unset with no options
		◦ env with no options or arguments
		◦ exit with no options
*/

/*
	• Handle ’ (single quote) which should prevent the shell from interpreting the meta-
	characters in the quoted sequence.
	
	• Handle " (double quote) which should prevent the shell from interpreting the meta-
	characters in the quoted sequence except for $ (dollar sign).
*/

/*
	Implement the following redirections:
	◦ < should redirect input.
	◦ > should redirect output.
	◦ << should be given a delimiter, then read the input until a line containing the
	delimiter is seen. However, it doesn’t have to update the history!
	◦ >> should redirect output in append mode.
*/

/*
	• Implement pipes (| character). The output of each command in the pipeline is
	connected to the input of the next command via a pipe.
	• Handle environment variables ($ followed by a sequence of characters) whijch
	should expand to their values.
	• Handle $? which should expand to the exit status of the most recently executed
	foreground pipeline.
*/

/*
	• Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
	• In interactive mode:
		◦ ctrl-C displays a new prompt on a new line.
		◦ ctrl-D exits the shell.
		◦ ctrl-\ does nothing.
*/