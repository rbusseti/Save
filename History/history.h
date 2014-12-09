/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 13:56:03 by rbusseti          #+#    #+#             */
/*   Updated: 2014/12/09 14:01:39 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H

# define HISTORY_H

# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>

# define UP 4283163
# define DOWN 4348699
# define ESC 27
# define SPACE 32
# define DEL 2117294875
# define RET 10
# define BACKSP 127
# define KEY *(unsigned int *)(buffer)

int		ft_init_termcaps(void);
int		ft_restore_termcaps(void);

#endif
