/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:14:48 by njacquem          #+#    #+#             */
/*   Updated: 2019/04/04 12:35:33 by njacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int res;

	if (nb > 0 && nb <= 12)
	{
		res = ft_recursive_factorial(nb - 1) * nb;
		return (res);
	}
	else if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else
		return (0);
}
