/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:41:49 by lkoc              #+#    #+#             */
/*   Updated: 2024/06/03 16:27:43 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	*ft_free(char **str, int size)
{
	while (0 < size)
	{
		free(*str);
		size--;
	}
	free(*str);
	return (NULL);
}

static int	count_words(const char *str, char c)
{
	static int	pos = 0;
	int			count;
	int			trigger;

	count = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
		{
			trigger = 0;
			pos++;
		}
		str++;
	}
	return (count);
}

static char	*word_copy(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_initiate_vars(size_t *i, int *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = -1;
}

char	**ft_split(char *s, char c)
{
	int		j;
	int		index;
	char	**word;
	size_t	i;

	ft_initiate_vars(&i, &j, &index);
	word = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!word)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			word[j] = word_copy(s, index, i);
			if (word[j] == NULL)
				return (ft_free(word, j));
			index = -1;
			j++;
		}
		i++;
	}
	word[j] = 0;
	return (word);
}
