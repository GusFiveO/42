/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:46:10 by alorain           #+#    #+#             */
/*   Updated: 2021/11/25 17:32:40 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nblen(int n)
{
	size_t	len;
	long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	i;
	char	*str;

	nb = n;
	if (n == 0)
		return ("0");
	str = malloc(sizeof(char) * nblen(n) + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{	
		str[0] = '-';
		nb *= -1;
	}
	i = nblen(n) - 1;
	while (nb >= 10)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	str[i] = nb % 10 + '0';
	str[nblen(n)] = '\0';
	return (str);
}

#include <stdio.h>

int main()
{
	printf("%s", ft_itoa(0));

}