/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabada-r <mabada-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:13:22 by mabada-r          #+#    #+#             */
/*   Updated: 2025/11/23 18:03:17 by mabada-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(&stash[i + 1]);
	free(stash);
	return (new_stash);
}

static char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		br;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	br = 1;
	while (br > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br < 0)
			return (free(buf), free(stash), NULL);
		buf[br] = '\0';
		if (br == 0)
			break ;
		stash = ft_strjoin_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	if (br == 0 && (!stash || !*stash))
		return (free(stash), NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
