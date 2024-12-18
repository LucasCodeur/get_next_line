/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:46:55 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/18 10:49:14 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_strcpy(char *src, char *dest);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strchr(char *str);
size_t	ft_strlen(char *str, char c);
char	*build_line(char *src, char *c_remaining, size_t *index);
void	ft_memcpy(char *src, char *dest, size_t n);
char	*get_next_line(int fd);

#endif
