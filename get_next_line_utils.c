/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:48:42 by mfedorys          #+#    #+#             */
/*   Updated: 2024/11/09 15:06:19 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	str_cp(char *src, char *dst, int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	check_if_contains_nl (char *str)
{
	while(str != NULL && *str!='\0')
	{
		if(*str == '\n')
			return 1;
		++str;
	}
	return 0;
}

int	find_nl(char *str)
{
	int	i;
	i = 0;
	while(str[i]!='\n')
	{
		i++;
	}
	return i;
}

int	lenght_of_str(char* str)
{
	int	i;
	i = 0;
	while(str[i]!='\0')
	{
		i++;
	}
	return i;
}

char *join(char **str1, char **str2)
{
	int	len1;
	int	len2;
	char *buf_for_joined_str;

	len1 = lenght_of_str(*str1);
	len2 = lenght_of_str(*str2);
	buf_for_joined_str = malloc(len1 + len2 + 1);
	str_cp(*str1, buf_for_joined_str, len1);
	str_cp(*str2, buf_for_joined_str + len1, len2);
	free(*str1);
	free(*str2);
	return (buf_for_joined_str);
}