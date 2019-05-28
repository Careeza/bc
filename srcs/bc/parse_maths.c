/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:55:48 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/23 13:29:51 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc.h"

t_num	*parse_factor(uint8_t *str, size_t *i)
{
	t_num *fac1;

	fac1 = create_num(LEN_NBR);
	if (str[*i] >= '0' && str[*i] <= '9')
		big_num_atoi((const char *)(str + *i), &fac1);
	else if (str[*i] == '(')
	{
		++(*i);
		fac1 = parse_sum(str, i);
		++(*i);
	}
	(*i) += fac1->len;
	return (fac1);
}

t_num	*parse_pow(uint8_t *str, size_t *i)
{
	t_num	*pow1;
	t_num	*pow2;

	pow1 = parse_factor(str, i);
	while (str[*i] == '^')
	{
		++(*i);
		pow2 = parse_factor(str, i);
		big_num_pow(pow1, pow2, &pow1);
	}
	return (pow1);
}

t_num	*parse_product(uint8_t *str, size_t *i)
{
	t_num	*pro1;
	t_num	*pro2;
	bool	operand;


	pro1 = parse_pow(str, i);
	while (str[*i] == '*' || str[*i] == '/')
	{
		operand = str[*i] == '*';
		++(*i);
		pro2 = parse_pow(str, i);
		operand ? big_num_mult(pro1, pro2, &pro1)
			: big_num_div(pro1, pro2, &pro1);
	}
	return (pro1);
}

t_num	*parse_sum(uint8_t *str, size_t *i)
{
	t_num	*sum1;
	t_num	*sum2;
	bool	operand;


	sum1 = parse_product(str, i);
	while (str[*i] == '+' || str[*i] == '-')
	{
		operand = str[*i] == '+';
		++(*i);
		sum2 = parse_product(str, i);
		operand ? big_num_add(sum1, sum2, &sum1)
			: big_num_sub(sum1, sum2, &sum1);
	}
	return (sum1);
}
