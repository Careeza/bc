/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:31:41 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/22 18:16:38 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_H

# define NUM_H
# define LEN_NBR 1
# include "common.h"

typedef struct	s_num
{
	size_t	capacity;
	bool	sign;
	bool	zero;
	size_t	len;
	uint8_t	num[];
}				t_num;

t_num	*create_num(size_t capacity);
t_num	*create_num_with_1_at_end(size_t len);

bool	add_a_nbr(t_num **num, uint8_t c);

t_num	*copy_num(t_num *num);
t_num	*copy_reverse_num(t_num *num);

void	big_num_atoi(const char *str, t_num **num);

ssize_t	conv_in_int(t_num *op);

void	aff_param(t_num *op, char *name);
void	aff_big_num(t_num *res, const char *str);

bool	big_num_add(t_num *op1, t_num *op2, t_num **res);
bool	bin_add(t_num *a, t_num *b, t_num **res, size_t len);

bool	big_num_sub(t_num *op1, t_num *op2, t_num **res);
bool	bin_sub(t_num *a, t_num *b, t_num **res, size_t len);

bool	big_num_mult(t_num *op1, t_num *op2, t_num **res);

bool	big_num_div(t_num *op1, t_num *op2, t_num **res);

bool	big_num_mod(t_num *op1, t_num *op2, t_num **res);

bool	big_num_pow(t_num *op1, t_num *op2, t_num **res);

bool	shift_to_right(t_num **num, ssize_t shift);
bool	shift_to_left(t_num **num, ssize_t shift);

#endif
