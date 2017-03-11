/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:55:00 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/01 18:34:01 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return lenth of number without sign!!!
*/

int	ft_numlen(int in)
{
	int i;
	int	n;

	i = 0;
	n = M(in);
	if (n / 10 == 0)
		return (i + 1);
	else
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
		return (i);
	}
}
