/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:49:05 by mfedorys          #+#    #+#             */
/*   Updated: 2024/11/09 15:06:18 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 25
#endif   // BUFFER_SIZE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
void	str_cp(char *src, char *dst, int n);
int	check_if_contains_nl(char *str);
int	find_nl(char * str);
int	lenght_of_str(char* str);
char *join(char **str1, char **str2);

#endif   // GET_NEXT_LINE
