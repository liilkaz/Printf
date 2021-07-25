#include "ft_printf.h"

static void	ft_red_zone(char *str, t_struct *all, int size_width, int size_wi)
{
	int	i;

	i = -1;
	if (all->precision < ft_strlen(str))
	{
		while (size_wi--)
			ft_putchar_s(' ', &all->size);
		while (++i < all->precision)
			ft_putchar_s(str[i], &all->size);
	}
	else
	{
		while (size_width--)
		{
			if (all->zero)
				ft_putchar_s('0', &all->size);
			else
				ft_putchar_s(' ', &all->size);
		}
		ft_putstr_size(str, &all->size);
	}
}

static void	ft_green_zone(char *str, t_struct *all, int size_wi)
{
	int	i;

	i = -1;
	if (all->width > all->precision && !all->hyphen)
	{
		while (size_wi--)
			ft_putchar_s(' ', &all->size);
	}
	while (++i < all->precision)
		ft_putchar_s(str[i], &all->size);
	if (all->width > all->precision && all->hyphen)
	{
		while (size_wi--)
			ft_putchar_s(' ', &all->size);
	}
}

void	ft_type_string(char *str, t_struct *all, int i)
{
	int		size_difference_width;

	if (!str)
		str = "(null)";
	size_difference_width = all->width - ft_strlen(str);
	if (all->width > ft_strlen(str) && !all->hyphen && \
	(all->precision > 0 || !all->point))
		ft_red_zone(str, all, size_difference_width, \
		all->width - all->precision);
	else if (all->width > ft_strlen(str) && all->hyphen && \
	(!all->point || all->precision > ft_strlen(str)))
	{
		ft_putstr_size(str, &all->size);
		while (size_difference_width--)
			ft_putchar_s(' ', &all->size);
	}
	else if (all->width && all->point && all->precision <= 0)
	{
		while (all->width--)
			ft_putchar_s(' ', &all->size);
	}
	else if (all->precision <= ft_strlen(str) && all->precision > 0)
		ft_green_zone(str, all, all->width - all->precision);
	else if (!(!all->width && all->point && all->precision <=0))
		ft_putstr_size(str, &all->size);
}

void	ft_type_char(char c, t_struct *all)
{
	int		size_difference_width;

	size_difference_width = all->width - 1;
	if (all->hyphen && all->width > 1)
	{
		ft_putchar_s(c, &all->size);
		while (size_difference_width-- > 0)
			ft_putchar_s(' ', &all->size);
	}
	else if (all->width > 1 && !all->hyphen && !all->zero)
	{
		while (size_difference_width-- > 0)
			ft_putchar_s(' ', &all->size);
		ft_putchar_s(c, &all->size);
	}
	else if (all->zero)
	{
		while (size_difference_width-- > 0)
			ft_putchar_s('0', &all->size);
		ft_putchar_s(c, &all->size);
	}
	else
		ft_putchar_s(c, &all->size);
}
