/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:53:48 by rbusseti          #+#    #+#             */
/*   Updated: 2014/12/09 14:06:41 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif_term(struct termios term)
{
    int		i;

	i = 0;
	if (term.c_iflag != 0 || term.c_oflag != 0 || term.c_cflag != 0 ||
		term.c_lflag != 0 || term.c_ispeed != 0 || term.c_ospeed != 0)
		return (1);
	while (i < 19)
	{
		if (term.c_cc[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

int			ft_restore_termcaps(void)
{
	static struct termios	term = {0};
	char					buffer[2048];

	if (ft_verif_term(term) == 0)
	{
		if ((tgetent(buffer, getenv("TERM"))) < 1)
			return (-1);
		tcgetattr(0, &term);
	}
	tputs(tgetstr("te", NULL), 1, ft_term_putchar);
	tputs(tgetstr("ve", NULL), 1, ft_term_putchar);
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	tcsetattr(0, TCSANOW, &term);
	return (0);
}

int			ft_init_termcaps(void)
{
    static struct termios	term = {0};
    char					buffer[2048];

	if (ft_verif_term(term) == 0)
	{
		if ((tgetent(buffer, getenv("TERM"))) < 1)
			return (-1);
		tcgetattr(0, &term);
	}
	tputs(tgetstr("ti", NULL), 1, ft_term_putchar);
	tputs(tgetstr("vi", NULL), 1, ft_term_putchar);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	return (0);
}
