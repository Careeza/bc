/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:37:09 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/23 14:25:29 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc.h"

bool	parse_expression(uint8_t *exp)
{
	t_num	*num;
	size_t	i;
	char	*str;

	i = 0;
	str = cut_white_spaces((char *)exp);
	num = parse_sum((uint8_t *)str, &i);
	aff_big_num(num, "\n");
	return (true);
}

bool	parse_instruction(uint8_t *exp)
{
	if (strcmp("quit", (const char*)exp) == 0)
		exit(0);
	else if (strcmp("clear", (const char*)exp) == 0)
		system("clear");
	else
	{
		printf("\"%s\"", exp);
		printf(" Unknow instruction\n");
	}
	return (true);
}

bool	parse(uint8_t *inst)
{
	if (inst[0] >= '0' && inst[0] <= '9')
		parse_expression(inst);
	else
		return (parse_instruction(inst));
	return (true);
}
