/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:30:31 by alorain           #+#    #+#             */
/*   Updated: 2021/11/25 11:58:14 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = 0;
	j = 0;
	str = malloc(sizeof(str) * len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[j + i] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
