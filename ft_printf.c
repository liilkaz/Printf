#include "ft_printf.h"

static void	specification(t_struct *all)
{
	all->hyphen = 0;
	all->width = 0;
	all->precision = -1;
	all->zero = 0;
	all->point = 0;
}

static int	ft_type(const char *mod, va_list ap, int *i, t_struct *all)
{
	if (mod[*i] == 'c')
		ft_type_char(va_arg(ap, int), all);
	if (mod[*i] == 'd' || mod[*i] == 'i')
		ft_type_int(va_arg(ap, int), all);
	else if (mod[*i] == 'u')
		ft_type_unsigned_int(va_arg(ap, unsigned int), all);
	else if (mod[*i] == 's')
		ft_type_string(va_arg(ap, char *), all, -1);
	else if (mod[*i] == 'p')
		ft_type_pointer(va_arg(ap, long), all);
	else if (mod[*i] == 'x' || mod[*i] == 'X')
		ft_type_hex_int(mod, i, va_arg(ap, long), all);
	else if (mod[*i] == '%')
		ft_type_char('%', all);
	(*i)++;
	return (0);
}

static int	ft_parser(const char *mod, va_list ap, int *i, t_struct *all)
{
	specification(all);
	(*i)++;
	ft_flags(mod, i, all);
	ft_width(mod, ap, i, all);
	if (!mod[*i])
		return (0);
	if (mod[*i] == '.')
	{
		all->point = 1;
		(*i)++;
		ft_precision(mod, ap, i, all);
	}
	ft_type(mod, ap, i, all);
	return (1);
}

int	ft_printf(const char *mod, ...)
{
	int			i;
	va_list		ap;
	t_struct	all;

	i = 0;
	va_start(ap, mod);
	all.size = 0;
	while (mod[i])
	{
		if (mod[i] == '%')
			ft_parser(mod, ap, &i, &all);
		else
			ft_putchar_s(mod[i++], &all.size);
	}
	va_end(ap);
	return (all.size);
}
