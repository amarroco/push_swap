/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroco <amarroco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:47 by amarroco          #+#    #+#             */
/*   Updated: 2024/02/13 16:22:55 by amarroco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;
	char	*tmp;

	if (size > 0 && nmemb > 2147483647 / size)
		return (NULL);
	if (nmemb < 1 || size < 1)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	tmp = (char *)ptr;
	while (size--)
		*(tmp++) = 0;
	return (ptr);
}

static char	*ft_substr(char const *s, int start, int len)
{
	char	*d;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	d = (char *)ft_calloc(len + 1, sizeof(char));
	if (!d)
		return (NULL);
	while (i < len && start < ft_strlen(s) + 1)
		d[i++] = s[start++];
	return (d);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_free(char **d, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		free(d[i++]);
	free(d);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	int		i;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	i = 1;
	start = 0;
	d = (char **)ft_calloc(ft_count(s, c) + 2, sizeof(char *));
	if (!d)
		return (NULL);
	while (i - 1 < ft_count(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		d[i] = ft_substr(s, start, end - start);
		if (!d[i++])
			return (ft_free(d, ft_count(s, c)));
		start = end;
	}
	return (d);
}
