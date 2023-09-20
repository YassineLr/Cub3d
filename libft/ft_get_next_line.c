/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:44:56 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/20 04:07:40 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static char	*ft_get_our_line(char *read_4m_left)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!read_4m_left[i])
		return (NULL);
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	new_str = malloc((i + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	if (read_4m_left[i] == '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_new_str(char *read_4m_left)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	if (!read_4m_left[i])
	{
		free(read_4m_left);
		return (NULL);
	}
	new_line = malloc((ft_strlen(read_4m_left) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (read_4m_left[i])
		new_line[j++] = read_4m_left[i++];
	new_line[j] = '\0';
	free(read_4m_left);
	return (new_line);
}

static char	*ft_read_str(int fd, char *read_4m_left)
{
	char	*new_str;
	int		bytes_read;

	new_str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(read_4m_left, '\n') && bytes_read)
	{
		bytes_read = read(fd, new_str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_str);
			free(read_4m_left);
			new_str = NULL;
			read_4m_left = NULL;
			return (NULL);
		}
		new_str[bytes_read] = '\0';
		read_4m_left = ft_strjoin(read_4m_left, new_str);
	}
	free(new_str);
	return (read_4m_left);
}

char	*get_next_line(int fd)
{
	static char	*read_4m_left[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_4m_left[fd] = ft_read_str(fd, read_4m_left[fd]);
	if (!read_4m_left[fd])
		return (NULL);
	line = ft_get_our_line(read_4m_left[fd]);
	read_4m_left[fd] = ft_new_str(read_4m_left[fd]);
	return (line);
}