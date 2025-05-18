/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:33:42 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/23 11:44:24 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

/* the maximum number of file descriptor in 
 * unix like systems(for normal users). */
# define MAX_SUPPORTED_FD 1024

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/* get_next_line_utils prototype */
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/* get_next_line prototype */
char	*get_next_line(int fd);

#endif
