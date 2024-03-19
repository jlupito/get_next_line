/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:13:04 by jarthaud          #+#    #+#             */
/*   Updated: 2022/12/02 10:38:51 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
		dst[i++] = s1[i];
	j = 0;
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free(s1);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ((char)c))
			return ((char *)s + i);
		i++;
	}
	if ((char)s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
