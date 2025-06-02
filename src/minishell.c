/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugenan <mugenan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:53:57 by mugenan           #+#    #+#             */
/*   Updated: 2025/06/02 22:12:45 by mugenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char *argv[], char *env[])
{
    
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