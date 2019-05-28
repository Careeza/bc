/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:22:43 by fbecerri          #+#    #+#             */
/*   Updated: 2019/05/23 14:28:54 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc.h"
#include "linenoise.h"
#include <string.h>

void	completion(const char *buf, linenoiseCompletions *lc)
{
	if (buf[0] == 'q')
		linenoiseAddCompletion(lc,"quit");
	if (buf[0] == 'c')
		linenoiseAddCompletion(lc,"clear");
}

char *hints(const char *buf, int *color, int *bold)
{
	if (!strcasecmp(buf,"q"))
	{
		*color = 35;
		*bold = 0;
		return ("uit");
	}
	if (!strcasecmp(buf,"c"))
	{
		*color = 35;
		*bold = 0;
		return ("lear");
	}
	return NULL;
}

t_inst		*create_inst(size_t capacity)
{
	t_inst	*inst;

	if (!(inst = malloc(sizeof(t_inst) + capacity * sizeof(uint8_t))))
		return (NULL);
	*inst = (t_inst){
		.capacity = capacity,
		.len = 0
	};
	ft_memset(inst->str, 0, capacity * sizeof(uint8_t));
	return (inst);
}

bool		add_a_char(t_inst **inst, uint8_t c)
{
	size_t	new_capacity;

	while ((*inst)->len >= (*inst)->capacity)
	{
		new_capacity = (*inst)->capacity * 2;
		if (!(*inst = realloc(*inst, sizeof(t_inst)
						+ new_capacity * sizeof(uint8_t))))
			return (false);
		ft_memset((*inst)->str + (*inst)->capacity, 0, (new_capacity / 2)
				* sizeof(uint8_t));
		(*inst)->capacity = new_capacity;
	}
	(*inst)->str[(*inst)->len] = c;
	(*inst)->len++;
	return (true);
}

int main(void)
{
	char *line;

	linenoiseSetCompletionCallback(completion);
	linenoiseSetHintsCallback(hints);
	linenoiseHistoryLoad("history.txt"); /* Load the history at startup */
	while ((line = linenoise("bc> ")) != NULL)
	{
		if (line[0] != '\0')
		{
			linenoiseHistoryAdd(line);
			linenoiseHistorySave("history.txt");
			parse((uint8_t *)line);
		}
		free(line);
	}
	return 0;
}

/*
int main(void)
{
	uint8_t		c;
	t_inst		*inst;
	bool		on_task;

	on_task = true;
	if (!(inst = create_inst(LEN_INST)))
		return (0);
	while (on_task)
	{
		c = getchar();
		if (c == 10)
		{
			on_task = parse(inst->str, inst->len);
			inst->len = 0;
			ft_memset(inst->str, 0, inst->capacity);
		}
		else
			if (c != ' ' && c != '\t' && c != '\n')
				add_a_char(&inst, c);
	}
	return (0);
}*/
