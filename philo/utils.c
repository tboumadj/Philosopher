/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:32:42 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/11/02 15:41:22 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long get_time(void)
{
    struct timeval tv;
    unsigned long long ms;

    gettimeofday(&tv, NULL);
    ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (ms);
}

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
