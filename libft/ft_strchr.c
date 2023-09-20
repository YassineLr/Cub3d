/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:22:11 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/20 05:57:08 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	// char	*str;
	// char	symbole;

	// str = (char *)s;
	// symbole = (char)c;
	// while (*str && !(*str == symbole))
	// 	str++;
	// if (*str == symbole)
	// 	return (str);
	// return (0);
	while (s && *s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (s && *s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
