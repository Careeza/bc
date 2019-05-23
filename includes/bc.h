/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:14:00 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/23 14:23:03 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BC_H

# define BC_H

# define LEN_INST 16
# include "common.h"
# include "num.h"

typedef struct	s_inst
{
	size_t		capacity;
	size_t		len;
	uint8_t		str[];
}				t_inst;

char	*cut_white_spaces(char *str);
t_num	*parse_pow(uint8_t *exp, size_t *i);
t_num	*parse_sum(uint8_t *exp, size_t *i);
t_num	*parse_product(uint8_t *exp, size_t *i);
bool	parse(uint8_t *inst);

#endif
