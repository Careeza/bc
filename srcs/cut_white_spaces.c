/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_white_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:19:37 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/23 14:23:19 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc.h"

char	*cut_white_spaces(char *str)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*copy;

	len = strlen(str);
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			copy[j] = str[i];
			j++;
		}
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
