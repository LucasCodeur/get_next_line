#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

// DEBUG Have to withdraw
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 164
#endif

int		ft_strrchr(char *s, int c);
int		ft_strchr(char *s, int c);
char    *ft_strjoin(char *buffer, char *result, char c);
size_t  ft_strlen(char *str, char c);
void    *ft_calloc(size_t nmemb, size_t size);
char    *get_next_line(int fd);

#endif
