/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:10:58 by jhii              #+#    #+#             */
/*   Updated: 2022/04/05 11:02:59 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	check_filename(char *filename, char	*needle)
{
	int	i;
	int	j;
	int	res;

	j = 0;
	res = 1;
	i = ft_strlen(filename) - 4;
	if (i < 0 || ft_strlen(filename) < 5)
		res = -1;
	while (filename[i])
	{
		if (filename[i++] != needle[j++])
			res = -1;
	}
	if (res < 0)
		ft_printf("Error: Invalid File Extension.\n");
	return (res);
}

static	int	check_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_printf("Error: File Not Readable.\n");
		return (-1);
	}
	close(fd);
	return (1);
}

int	check_file_error(char *filename)
{
	if (check_filename(filename, ".ber") < 0)
		return (-1);
	if (check_file(filename) < 0)
		return (-1);
	return (1);
}
