#include "ft_printf.h"

void	ft_precision(const char *mod, va_list ap, int *i, t_struct *all)
{
	if (mod[*i] == '*')
	{	
		all->precision = va_arg(ap, int);
		(*i)++;
		if (all->precision < 0 )
		{
			all->precision = -1;
			all->point = 0;
		}
	}
	else
	{	
		if (mod[*i] == '-')
		{
			all->precision = -1;
			all->hyphen = 1;
			(*i)++;
			all->width = ft_atoi_invalid(&mod[*i]);
		}
		else
			all->precision = ft_atoi_invalid(&mod[*i]);
		while (mod[*i] >= '0' && mod[*i] <= '9')
			(*i)++;
	}
}

void	ft_width(const char *mod, va_list ap, int *i, t_struct *all)
{
	if (mod[*i] == '*')
	{	
		all->width = va_arg(ap, int);
		(*i)++;
		if (all->width < 0)
		{
			all->hyphen = 1;
			all->zero = 0;
			all->width = -all->width;
		}
	}
	else
	{	
		all->width = ft_atoi_invalid(&mod[*i]);
		while (mod[*i] >= '0' && mod[*i] <= '9')
			(*i)++;
	}
}

void	ft_flags(const char *mod, int *i, t_struct *all)
{
	while (mod[*i] == '-' || mod[*i] == '0')
	{
		if (mod[*i] == '-')
			all->hyphen = 1;
		else if (mod[*i] == '0' && !all->hyphen)
			all->zero = 1;
		(*i)++;
	}
	if (all->hyphen == 1)
		all->zero = 0;
}
