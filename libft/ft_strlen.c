/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:22 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/02/22 13:10:07 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
/*
int main()
{
    const char a[] = "Programs";
    printf("%zu",ft_strlen(a));
	printf("\n");
    printf("%lu",strlen(a));

    return 0;
}
*/
/*
1. Initialize len to 0.

2. Enter a loop that continues while the character pointed to by str is not null.

3. Increment len and str.

4. Return len.
*/