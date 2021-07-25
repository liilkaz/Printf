#include "ft_printf.h"

int	ft_type_int(int d, t_struct *all)
{
	char	*s;
	char	*s_neg;

	s = ft_itoa(d);
	s_neg = ft_itoa_neg(d);
	if (d < 0)
		ft_negative_int(s, s_neg, all);
	else
		ft_positive_int(d, s, all);
	free(s);
	free(s_neg);
	return (0);
}

int	ft_type_unsigned_int(int u, t_struct *all)
{
	char	*s_un;

	s_un = ft_unitoa(u);
	ft_positive_int(u, s_un, all);
	free(s_un);
	return (0);
}

int	ft_type_hex_int(const char *mod, int *i, unsigned int x, t_struct *all)
{
	char	*s_hex;

	if (mod[*i] == 'x')
		s_hex = ft_itoa_hex(x, 32, 0);
	else
		s_hex = ft_itoa_hex(x, 0, 0);
	ft_positive_int(x, s_hex, all);
	free(s_hex);
	return (0);
}

int	ft_type_pointer(long p, t_struct *all)
{
	char	*s_point;

	s_point = ft_itoa_hex(p, 32, 0);
	ft_pointer(p, s_point, all);
	free(s_point);
	return (0);
}
