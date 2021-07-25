#include "ft_printf.h"

static void	ft_width_smaller(char *s_neg, char *s, t_struct *all, int neg)
{
	int		size_difference_precision;

	size_difference_precision = all->precision - ft_strlen(s);
	if (all->point && all->precision > ft_strlen(s))
	{
		if (neg)
			ft_putchar_s('-', &all->size);
		while (size_difference_precision--)
			ft_putchar_s('0', &all->size);
		ft_putstr_size(s, &all->size);
	}
	else
		ft_putstr_size(s_neg, &all->size);
}

static void	ft_width_bigger(char *s, t_struct *all)
{
	if (all->hyphen && (!all->point || (all->point
				&& all->precision <= ft_strlen(s))))
		ft_mini_tangle_first(s, all, all->hyphen);
	else if (all->hyphen && all->precision > ft_strlen(s)
		&& all->precision < all->width)
		ft_mini_tangle_second(s, all, 0);
	else if (all->precision >= all->width)
		ft_mini_tangle_third(s, all, 0, 0);
	else if (!all->point && all->zero)
		ft_mini_tangle_third(s, all, 1, 0);
	else if ((!all->hyphen && all->precision <= ft_strlen(s)) || !all->point)
		ft_mini_tangle_first(s, all, all->hyphen);
	else if (!all->hyphen && all->point && (all->precision > ft_strlen(s)))
		ft_mini_tangle_fifth(s, all, 0);
}

void	ft_positive_int(int d, char *s, t_struct *all)
{
	if (d == 0 && all->point && all->precision <= 0)
	{
		while (all->width--)
			ft_putchar_s(' ', &all->size);
	}
	else if (all->width > ft_strlen(s))
		ft_width_bigger(s, all);
	else if (all->width <= ft_strlen(s))
		ft_width_smaller(s, s, all, 0);
	else
		ft_putstr_size(s, &all->size);
}

void	ft_negative_int(char *s, char *s_neg, t_struct *all)
{
	if (all->width <= ft_strlen(s_neg))
		ft_width_smaller(s_neg, s, all, 1);
	else
	{
		if (all->hyphen && (!all->point || (all->point == 1 \
		&& all->precision < ft_strlen(s_neg))))
			ft_mini_tangle_first(s_neg, all, all->hyphen);
		else if (all->hyphen && all->precision > ft_strlen(s)
			&& all->precision < all->width)
			ft_mini_tangle_second(s, all, 1);
		else if (all->point && all->precision >= all->width)
			ft_mini_tangle_third(s, all, 0, 1);
		else if (!all->point && all->zero)
			ft_mini_tangle_third(s, all, 1, 1);
		else if ((!all->hyphen && all->point
				&& all->precision <= ft_strlen(s)) || !all->point)
			ft_mini_tangle_fourth(s, all);
		else
			ft_mini_tangle_fifth(s, all, 1);
	}
}
