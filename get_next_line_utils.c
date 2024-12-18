/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:46:47 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/18 10:46:49 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

void	ft_memcpy(char *src, char *dest, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (!src)
		return ;
	while (n > 0)
	{
		*p_dest++ = *p_src++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory_block;
	size_t			i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	memory_block = malloc(nmemb * size);
	if (!memory_block)
		return (NULL);
	while (i < nmemb * size)
	{
		memory_block[i] = 0;
		i++;
	}
	return ((void *)memory_block);
}

size_t	ft_strchr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
