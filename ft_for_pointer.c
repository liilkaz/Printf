#include "ft_printf.h"

static void	ft_mini_tangle_pointer(char *s, t_struct *all, int flag)
{
	int		size_difference_width;

	size_difference_width = all->width - ft_strlen(s) - 2;
	if (!flag)
	{
		while (size_difference_width-- >0)
			ft_putchar_s(' ', &all->size);
	}
	ft_putstr_size("0x", &all->size);
	ft_putstr_size(s, &all->size);
	if (flag)
	{
		while (size_difference_width-- > 0)
			ft_putchar_s(' ', &all->size);
	}
}

static void	ft_width_bigger_pointer(char *s, t_struct *all)
{
	if (all->hyphen && (!all->point || (all->point && \
	all->precision <= ft_strlen(s))))
		ft_mini_tangle_pointer(s, all, 1);
	else
		ft_mini_tangle_pointer(s, all, 0);
}

static void	ft_zero_pointer(char *s, t_struct *all)
{
	if (all->width)
	{
		all->width -= 2;
		while (all->width--)
			ft_putchar_s(' ', &all->size);
	}
	ft_putstr_size("0x", &all->size);
}

static void	ft_width_smaller_pointer(char *s, t_struct *all)
{
	int		size_difference_precision;

	size_difference_precision = all->precision - ft_strlen(s);
	ft_putstr_size("0x", &all->size);
	if (all->point && all->precision > ft_strlen(s))
	{
		while (size_difference_precision--)
			ft_putchar_s('0', &all->size);
	}
	ft_putstr_size(s, &all->size);
}

void	ft_pointer(int d, char *s, t_struct *all)
{
	if ((d == 0 || s == 0) && all->point && all->precision <= 0)
		ft_zero_pointer(s, all);
	else if (all->width > ft_strlen(s))
		ft_width_bigger_pointer(s, all);
	else
		ft_width_smaller_pointer(s, all);
}
