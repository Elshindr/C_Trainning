/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:42:57 by njacquem          #+#    #+#             */
/*   Updated: 2019/04/04 12:16:55 by njacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int fac;

	if (nb >= 0 && nb <= 12)
	{
		i = 1;
		fac = 1;
		while (i <= nb)
		{
			fac = i * fac;
			i++;
		}
	}
	else
		fac = 0;
	return (fac);
}
