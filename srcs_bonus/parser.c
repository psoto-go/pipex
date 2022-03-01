/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/01 16:23:34 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	num_args(int argc, t_pipex *pipex)
{
	if (argc < 6)
		ft_error(1, pipex);
}

void	check_file(char **argv, t_pipex *p, int argc)
{
	p->fdstd[0] = open(argv[1], O_RDONLY);
	if (p->fdstd[0] < 0)
	{
		if (errno == 2)
			ft_error(2, p);
		else
			ft_error(3, p);
	}
	p->fdstd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (p->fdstd[1] < 0)
	{
		if (errno == 2)
			ft_error(2, p);
		else
			ft_error(3, p);
	}
}

void	check_file_here_doc(char **argv, t_pipex *p, int argc)
{
	p->fdstd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (p->fdstd[1] < 0)
	{
		if (errno == 2)
			ft_error(2, p);
		else
			ft_error(3, p);
	}
}

void	fill_stack(int argc, char **argv, t_pipex *p, int flag)
{
	int	i;

	if (flag == 0)
		i = 2;
	if (flag == 1)
		i = 3;
	while (i <= (argc - 2))
	{
		if (ft_isalpha(argv[i][0]) == 0)
			ft_error(5, p);
		check_only_command(argv[i], p);
		ft_lstadd_back(&p->list, new_nodo((void *)argv[i], sizeof(char *)));
		i++;
	}
}

void	parser(int argc, char **argv, t_pipex *pipex, char **envp)
{
	num_args(argc, pipex);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		check_file_here_doc(argv, pipex, argc);
		get_path(envp, pipex, argv);
		fill_stack(argc, argv, pipex, 1);
	}
	else
	{
		check_file(argv, pipex, argc);
		get_path(envp, pipex, argv);
		fill_stack(argc, argv, pipex, 0);
	}	
}
