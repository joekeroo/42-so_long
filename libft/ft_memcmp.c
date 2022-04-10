/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:16:39 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 23:18:46 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned long	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	if (str1 == str2 || n == 0)
		return (0);
	i = 0;
	cs1 = (unsigned char *)str1;
	cs2 = (unsigned char *)str2;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
