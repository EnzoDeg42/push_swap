/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:30:14 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/22 09:24:21 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_whtspc(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

static int	nwords(char const *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != 0)
	{
		if (!is_whtspc(s[i]) && (is_whtspc(s[i + 1]) || s[i + 1] == 0))
			n++;
		i++;
	}
	return (n);
}

static int	split_words(char **str, char const *s, int word)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (s[end])
	{
		if (is_whtspc(s[end]) || s[end] == 0)
			start = end + 1;
		if (!is_whtspc(s[end]) && (is_whtspc(s[end + 1]) || s[end + 1] == 0))
		{
			str[word] = malloc(sizeof(char) * (end - start + 2));
			if (!str[word])
			{
				while (word++)
					free(str[word]);
				return (0);
			}
			ft_strlcpy(str[word], (s + start), end - start + 2);
			word++;
		}
		end++;
	}
	str[word] = 0;
	return (1);
}

char	**ft_split(char const *s)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (nwords(s) + 1));
	if (!str)
		return (NULL);
	if (split_words(str, s, 0) == 0)
		return (NULL);
	return (str);
}

// int	main(void)
// {
// 	char	*str = "--\t-Hev\tllo-W\nolr\rd-How--";
// 	char	**out;

// 	out = ft_split(str);
// 	int i = 0;
// 	while (out[i])
// 	{
// 		printf("%s\n", out[i]);
// 		i++;
// 	}	
// }
