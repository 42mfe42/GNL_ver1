/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:48:56 by mfedorys          #+#    #+#             */
/*   Updated: 2024/11/09 15:06:13 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *split_on_nl(char **iuf, int flag_if_nl_present)
{
	char	*huf;
	char	*buf;
	int	nl_index;
	int	iuf_len;

	if(!flag_if_nl_present)										//znaczy, ze jest koniec?
	{
		huf = *iuf;												//nie mam mallocka na huf
		*iuf = NULL;
		return (huf);
	} 
	else
	{
		nl_index = find_nl(*iuf);
		iuf_len = lenght_of_str(*iuf);
		buf = malloc(nl_index + 2);          
		huf = malloc(iuf_len - nl_index);    
		str_cp(*iuf, buf, nl_index + 1);
		str_cp(*iuf + nl_index + 1, huf, iuf_len - nl_index - 1);
		free(*iuf);											//skoro czyszcze iuf, to nie mam mallocka zeby go zaraz uzyc?
		*iuf = huf;
		return (buf);
	}
}

int	read_until_nl(int fd, char **iuf)
{
	char	*buf;
	int	flag_if_nl_present;
	int	flag_if_eof;
	int	how_many_read;

	flag_if_nl_present = check_if_contains_nl(*iuf);
	flag_if_eof = 0;
	while (!flag_if_nl_present && !flag_if_eof) //rob to dopoki trafisz na nowa linie lub koniec pliku
	{
		buf = malloc (BUFFER_SIZE + 1);
		how_many_read = read (fd, buf, BUFFER_SIZE);
		if (how_many_read < 0)
		{
			free(buf);
			if (iuf != NULL && *iuf != NULL)
				free(*iuf);
			return (-1);
		}
		buf[how_many_read] = '\0';
		flag_if_nl_present = check_if_contains_nl(buf);
		flag_if_eof = how_many_read < BUFFER_SIZE;
		*iuf = join(iuf, &buf);
	}
	return (flag_if_nl_present);
}

char	*get_next_line(int fd)
{
	static char	*iuf = NULL;
	int	flag_if_nl_present;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (iuf == NULL)
	{
		iuf = malloc(1);
		if(iuf == NULL)
			return (NULL);
		iuf[0] = '\0';
	}
	flag_if_nl_present = read_until_nl(fd, &iuf);
	if (flag_if_nl_present < 0)
	{
		iuf = NULL;
		return (NULL);
	}
	return(split_on_nl(&iuf, flag_if_nl_present));
}
