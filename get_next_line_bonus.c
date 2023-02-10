/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:09:55 by jarthaud          #+#    #+#             */
/*   Updated: 2023/01/06 17:40:51 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_new_start(char *stash, int read_nb)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(stash);
	j = 0;
	while (stash[j] != '\n' && stash[j])
		j++;
	j++;
	if (read_nb == 0)
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (i - j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[j])
		str[i++] = stash[j++];
	str[i] = '\0';
	free(stash);
	return (str);
}

char	*get_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;
	int			read_nb;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_nb = 1;
	while (!(ft_strchr(stash[fd], '\n')) && read_nb != 0)
	{
		read_nb = read(fd, buffer, BUFFER_SIZE);
		if (read_nb <= 0 && !stash[fd])
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_nb] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	free(buffer);
	buffer = get_line(stash[fd]);
	stash[fd] = get_new_start(stash[fd], read_nb);
	return (buffer);
}

int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		i;
	char	*res;

	fd = open("fichiertest.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	fd1 = open("fichiertest1.txt", O_RDONLY);
	if (fd1 < 0)
		return (-1);
	fd2 = open("fichiertest2.txt", O_RDONLY);
	if (fd2 < 0)
		return (-1);
	i = 1;
	while (i < 200000)
	{
		res = get_next_line(fd);
		printf("text0:%s", res);
		free(res);
		res = get_next_line(fd1);
		printf("text1:%s", res);
		free(res);
		res = get_next_line(fd2);
		printf("text2:%s", res);
		free(res);
		i++;
	}
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}
