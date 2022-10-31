/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:32:42 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/10/31 12:50:44 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] <= 32 || str[i] == 43)
    i++;
    if (str[i] == 45)
    {
        neg *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
    {
        nb *= 10;
        nb += str[i] - 48;
        i++;
    }
    return (nb * neg);
}
