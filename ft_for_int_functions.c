#include "ft_printf.h"

void	ft_mini_tangle_first(char *s, t_struct *all, int hyphen)
{
	int		size_difference_width;

	size_difference_width = all->width - ft_strlen(s);
	if (hyphen)
		ft_putstr_size(s, &all->size);
	while (size_difference_width--)
		ft_putchar_s(' ', &all->size);
	if (!hyphen)
		ft_putstr_size(s, &all->size);
}

void	ft_mini_tangle_second(char *s, t_struct *all, int neg)
{
	int		size_difference_precision;
	int		size_dif_pr_wi;

	size_difference_precision = all->precision - ft_strlen(s);
	size_dif_pr_wi = all->width - all->precision - neg;
	if (neg)
		ft_putchar_s('-', &all->size);
	while (size_difference_precision--)
		ft_putchar_s('0', &all->size);
	ft_putstr_size(s, &all->size);
	while (size_dif_pr_wi--)
		ft_putchar_s(' ', &all->size);
}

void	ft_mini_tangle_third(char *s, t_struct *all, int width, int neg)
{
	int		size_difference;

	if (width)
		size_difference = all->width - ft_strlen(s) - neg;
	else
		size_difference = all->precision - ft_strlen(s);
	if (neg)
		ft_putchar_s('-', &all->size);
	while (size_difference--)
		ft_putchar_s('0', &all->size);
	ft_putstr_size(s, &all->size);
}

void	ft_mini_tangle_fourth(char *s, t_struct *all)
{
	int		size_difference_width;

	size_difference_width = all->width - ft_strlen(s) - 1;
	while (size_difference_width--)
		ft_putchar_s(' ', &all->size);
	ft_putchar_s('-', &all->size);
	ft_putstr_size(s, &all->size);
}

void	ft_mini_tangle_fifth(char *s, t_struct *all, int neg)
{
	int		size_difference_precision;
	int		size_dif_pr_wi;

	size_difference_precision = all->precision - ft_strlen(s);
	size_dif_pr_wi = all->width - all->precision - neg;
	while (size_dif_pr_wi--)
		ft_putchar_s(' ', &all->size);
	if (neg)
		ft_putchar_s('-', &all->size);
	while (size_difference_precision--)
		ft_putchar_s('0', &all->size);
	ft_putstr_size(s, &all->size);
}
