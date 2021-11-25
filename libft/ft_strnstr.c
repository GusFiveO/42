/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:27:17 by alorain           #+#    #+#             */
/*   Updated: 2021/11/25 17:27:26 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char	*s;
	char	*t;
	size_t	i;
	size_t	j;

	i = 0;
	s = (char *)str;
	t = (char *)to_find;
	if (!ft_strlen(t))
		return (s);
	if (n == 0)
		return (NULL);
	while (i < (n - 1) && s[i])
	{
		j = 0;
		while (s[i + j] == t[j] && (i + j) < (n - 1))
			j++;
		if (j == ft_strlen(t))
			return (&s[i]);
		i++;
	}
	return (NULL);
}
