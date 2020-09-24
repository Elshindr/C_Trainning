/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:41:11 by njacquem          #+#    #+#             */
/*   Updated: 2019/04/09 15:43:23 by njacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		display_file(char *file_name)
{
	int		fd;
	char	buf[SIZE + 1];
	int		ret;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = read(fd, &buf, SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ft_putchar('\n');
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("File name missing\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	else
		display_file(argv[1]);
	return (0);
}
