/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:19:14 by edegraev          #+#    #+#             */
/*   Updated: 2024/02/29 15:15:27 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# elif BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*ft_get_line(char *stash);
char	*ft_new_stash(char *stash);
char	*ft_read_to_stash(int fd, char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin(char *stash, char *buff);
char	*ft_strchr(char *s, int c);

#endif