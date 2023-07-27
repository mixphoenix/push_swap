/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:11:39 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/27 21:19:04 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

int	ft_putnbr(int nb)
{
	int				c;
	unsigned int	nbr;

	c = 0;
	nbr = nb;
	if (nb < 0)
	{
		nbr = nb * -1;
		ft_putchar('-');
		c++;
	}
	if (nbr > 9)
	{
		c += ft_putnbr(nbr / 10);
	}
	c += ft_putchar((nbr % 10) + '0');
	return (c);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int		c;

	c = 0;
	if (nb >= 10)
	{
		c += ft_putunbr(nb / 10);
		c += ft_putunbr(nb % 10);
	}
	else if (nb <= 9)
		c += ft_putchar(nb + '0');
	return (c);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*r;

	i = 0;
	r = (unsigned char *)b;
	while (i < len)
	{
		r[i] = (unsigned char)c;
		i++;
	}
	b = r;
	return (b);
}
