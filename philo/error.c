/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:53:40 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/04 18:53:13 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_nrm(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	write(2, "Philo : Error : ", 17);
	write(2, str, count);
	write(2, "\n", 1);
	return ;
}
