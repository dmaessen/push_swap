/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:43:50 by dmaessen          #+#    #+#             */
/*   Updated: 2022/10/19 11:50:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	int	c;
// 	c = ' ';
// 	printf("%d", ft_isalnum(c));
// }