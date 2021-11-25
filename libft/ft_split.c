/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:39:01 by alorain           #+#    #+#             */
/*   Updated: 2021/11/25 11:56:36 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	comptword(const char *s1, char c)
{
	size_t	i;
	size_t	compt;

	i = 0;
	compt = 0;
	while(s1[i])
	{
		while (s1[i] == c && s1[i])
			i++;
		if (s1[i] != '\0')
		{
			compt++;
			while (s1[i] != c && s1[i])
				i++;
		}
	}
	return (compt);
}

static char	*cpyword(const char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*str;
	
	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++; 
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free(char **tab, char *str, size_t	size)
{
	size_t	i;

	i = 0;
	free(str);
	while (i < size)
	{
		free(tab[i]);
		i++;
	}

}

char	**ft_split(const char *s1, char c)
{
	size_t	i;
	size_t	word;
	char	**tab;

	i = 0;
	word = 0;	
	tab = malloc(sizeof(tab) * comptword(s1, c) + 1);
	if (!tab)
		return (NULL);
	while(s1[i])
	{
		if (s1[i] != c)
		{
			if(!(tab[word] = cpyword(s1 + i, c)))
			{
				ft_free(tab, tab[word], word);
				return (NULL);
			}
			word++;
			while (s1[i] != c && s1[i])
				i++;
			i--;
		}		
		i++;
	}
	tab[word] = NULL;
	return (tab);
}


/* #include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void    ft_print_result(char const *s)
{
        int             len;

        len = 0;
        while (s[len])
                len++;
        write(1, s, len);
}

int             main(int argc, const char *argv[])
{
        char    **tabstr;
        int             i;
        int             arg;

        alarm(5);
        if (argc == 1)
                return (0);
        i = 0;
        if ((arg = atoi(argv[1])) == 1)
        {
                if (!(tabstr = ft_split("          ", ' ')))
                        ft_print_result("NULL");
                else
                {
                        while (tabstr[i] != NULL)
                        {
                                ft_print_result(tabstr[i]);
                                write(1, "\n", 1);
                                i++;
                        }
                }
        }
        else if (arg == 2)
        {
                if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
                        ft_print_result("NULL");
                else
                {
                        while (tabstr[i] != NULL)
                        {
                                ft_print_result(tabstr[i]);
                                write(1, "\n", 1);
                                i++;
                        }
                }
        }
        else if (arg == 3)
        {
                if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
                        ft_print_result("NULL");
                else
                {
                        while (tabstr[i] != NULL)
                        {
                                ft_print_result(tabstr[i]);
                                write(1, "\n", 1);
                                i++;
                        }
                }
        }
        else if (arg == 4)
        {
                if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
                        ft_print_result("NULL");
                else
                {
                        while (tabstr[i] != NULL)
                        {
                                ft_print_result(tabstr[i]);
                                write(1, "\n", 1);
                                i++;
                        }
                }
        }
        else if (arg == 5)
        {
                if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
                        ft_print_result("NULL");
                else
                {
                        while (tabstr[i] != NULL)
                        {
                                ft_print_result(tabstr[i]);
                                write(1, "\n", 1);
                                i++;
                        }
                }
        }
        else if (arg == 6)
        {
                if (!(tabstr = ft_split("", 'z')))
                        ft_print_result("NULL");
                else
                        if (!tabstr[0])
                                ft_print_result("ok\n");
        }
        return (0);
} */