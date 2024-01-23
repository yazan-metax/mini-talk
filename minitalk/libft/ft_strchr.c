/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:56:18 by yazan             #+#    #+#             */
/*   Updated: 2023/01/06 20:24:59 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}
/* int main(void)
{
	char str[100]="hey you";
	printf("here we are:%s\n",ft_strchr(str, 'y'));
	return(0);
} */