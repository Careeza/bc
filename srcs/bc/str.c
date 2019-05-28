/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:43:53 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/22 19:02:36 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_putchar(uint8_t c)
{
	write (1, &c, 1);
}

void	ft_putstr(uint8_t *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

bool	ft_strncmp(uint8_t *str, uint8_t *exp, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (true);
	while (i < len && str[i] && str[i] == exp[i])
		i++;
	return (str[i] == exp[i]);
}
