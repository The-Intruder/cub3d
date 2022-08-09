/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_tl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:22:37 by mnaimi            #+#    #+#             */
/*   Updated: 2021/07/07 14:39:30 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* -------------------------------------------------------------------------- */

char	*ft_strstr_tl(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (NULL);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == ft_tolower(needle[j]) || needle[j] == '\0')
			if (needle[j++] == '\0')
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */