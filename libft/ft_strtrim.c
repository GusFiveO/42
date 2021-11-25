/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:40:27 by alorain           #+#    #+#             */
/*   Updated: 2021/11/24 15:36:20 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	compt;
	size_t	i;
	size_t	offset;

	compt = 0;
	offset = 0;
	i = 0;
	while (ft_isin(set, s1[i]) && s1[i])
	{
		i++;
		offset++;
	}
	i = ft_strlen(s1) - 1;
	while (ft_isin(set, s1[i]) && i != 0)
	{
		i--;
		compt++;
	}
	trim = malloc(sizeof(trim) * (ft_strlen(s1) - offset + compt) + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[offset], ft_strlen(s1) - (offset + compt) + 1);
	return (trim);
}
