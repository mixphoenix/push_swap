#include <unistd.h>
#include "../push_swap.h"

int	ft_hex(unsigned int n, char x)
{
	char	*hex;
	int		c;

	c = 0;
	hex = 0;
	if (x == 'X')
		hex = "0123456789ABCDEF";
	else if (x == 'x')
	hex = "0123456789abcdef";
	if (n >= 16)
		c += ft_hex((n / 16), x);
	c += ft_putchar(hex[(n % 16)]);
	return (c);
}

int	ft_hex_p(unsigned long long n)
{
	char	*hex;
	int		c;

	c = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		c += ft_hex_p((n / 16));
	c += ft_putchar(hex[(n % 16)]);
	return (c);
}

int	ft_pointer(unsigned long long p)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	c += ft_hex_p(p);
	return (c);
}

long int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] <= 32 && str[i])
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		if ((((res - 1) > INT_MAX) && s == -1) \
			|| ((res > INT_MAX) && s == 1))
			ft_error();
		i++;
	}
	return (res * s);
}
