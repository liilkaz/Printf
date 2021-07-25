#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi_invalid(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	if (str[i] == 43)
		i++;
	while (str[i] == 45)
		i++;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			res = res * 10 + str[i] - 48;
		else
			break ;
		i++;
	}
	return (res);
}

void	ft_putchar_s(char c, int *data)
{
	write(1, &c, 1);
	*data += 1;
}

void	ft_putstr_size(char *s, int *size)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (i < ft_strlen(s))
	{
		ft_putchar_s(s[i], size);
		i++;
	}
}
