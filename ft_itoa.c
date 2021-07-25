#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char			*s;
	int				i;
	unsigned int	n2;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n = -n;
	n2 = n;
	while (n)
	{
		n = n / 10;
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	return (s);
}

static char	*ft_itoa_neg_part2(int j, int i, unsigned int n2)
{
	char	*s;

	s = malloc(sizeof(char) * (i + 1 + j));
	if (s == NULL)
		return (NULL);
	s[i + j] = '\0';
	while (--i >= 0)
	{
		s[i + j] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	if (j)
		s[i + j] = '-';
	return (s);
}

char	*ft_itoa_neg(int n)
{
	int				i;
	unsigned int	n2;
	int				j;

	j = 0;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = -n;
		j++;
	}
	n2 = n;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (ft_itoa_neg_part2(j, i, n2));
}

char	*ft_unitoa(unsigned int n)
{
	int				i;
	char			*s;
	unsigned int	n2;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	n2 = n;
	while (n)
	{
		n = n / 10;
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	return (s);
}

char	*ft_itoa_hex(long n, int big, int i)
{
	long	n2;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	n2 = n;
	while (n)
	{
		n = n / 16;
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	while (--i >= 0)
	{
		if (n2 % 16 > 9)
			s[i] = n2 % 16 - 10 + 65 + big;
		else
			s[i] = n2 % 16 + '0';
		n2 /= 16;
	}
	return (s);
}
