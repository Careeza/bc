/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:14:38 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/23 14:08:11 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H

# define COMMON_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct		s_entry
{
	char		*key;
	uint64_t	hash;
	uint64_t	offset;
	bool		resolve;
}					t_entry;

typedef struct		s_hashtable
{
	size_t		size;
	t_entry		bucket[];
}					t_hashtable;

void	*ft_memset(void *s, uint8_t c, size_t n);
bool	ft_strncmp(uint8_t *str, uint8_t *exp, size_t len);
void	ft_putstr(uint8_t *str, size_t len);
void	ft_putchar(uint8_t c);

#endif
