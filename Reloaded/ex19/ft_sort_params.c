/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:43:37 by njacquem          #+#    #+#             */
/*   Updated: 2019/04/05 13:00:35 by njacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_arg_swap(char **arg1, char **arg2)
{
	char	*c;

	c = *arg1;
	*arg1 = *arg2;
	*arg2 = c;
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i != argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) <= 0)
			i++;
		else
		{
			ft_arg_swap(argv + i, argv + i + 1);
			i = 1;
		}
	}
	i = 1;
	while (i != argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
