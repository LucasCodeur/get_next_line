/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:46:36 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/18 15:13:21 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	fill_line(char *line, char *c_remaining, char *src, size_t *index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (c_remaining && c_remaining[i])
	{
		line[i] = c_remaining[i];
		i++;
	}
	while (src[j] && src[j] != '\n')
	{
		line[i + j] = src[j];
		src[j] = 0;
		j++;
	}
	if (src[j] == '\n')
		line[i + j] = '\n';
	*index = j;
}

char	*build_line(char *src, char *c_remaining, size_t *index)
{
	char	*line;
	size_t	size;
	size_t	is_jump;

	is_jump = ft_strchr(src);
	size = ft_strlen(src, '\n') + ft_strlen(c_remaining, '\0') + is_jump + 1;
	line = ft_calloc(size, sizeof(char));
	if (!line)
	{
		free(c_remaining);
		return (NULL);
	}
	if (!src)
		return (NULL);
	fill_line(line, c_remaining, src, index);
	if (c_remaining)
		free(c_remaining);
	return (line);
}

static void	read_file(int fd, char *buffer, ssize_t *nb_read)
{
	*nb_read = read(fd, buffer, BUFFER_SIZE);
	if (*nb_read < 0)
		return ;
	buffer[*nb_read] = '\0';
}

static char	*get_the_line(int fd, char *buffer)
{
	char	*line;
	size_t	i;
	ssize_t	nb_read;

	i = 0;
	nb_read = 0;
	line = NULL;
	if (buffer[0] != '\0')
	{
		line = build_line(buffer, NULL, &i);
		if (!line)
			return (NULL);
		ft_memcpy(buffer + i + 1, buffer, ft_strlen(buffer + i, '\0'));
	}
	while (ft_strchr(line) == 0)
	{
		read_file(fd, buffer, &nb_read);
		if (nb_read < 0)
			return (free(line), NULL);
		if (nb_read == 0)
			break ;
		line = build_line(buffer, line, &i);
		ft_memcpy(buffer + i + 1, buffer, ft_strlen(buffer + i, '\0'));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_the_line(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;
// 	char	*result;
//
// 	// fd = open("test.txt", O_RDONLY);
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		result = get_next_line(fd);
// 		printf("Final result :%s\n", result);
// 		free(result);
// 	}
// 	close(fd);
// 	return (0);
// }
