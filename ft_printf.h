#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_struct
{
	int	hyphen;
	int	width;
	int	precision;
	int	zero;
	int	point;
	int	size;

}	t_struct;

int		ft_printf(const char *mod, ...);
void	ft_precision(const char *mod, va_list ap, int *i, t_struct *all);
void	ft_width(const char *mod, va_list ap, int *i, t_struct *all);
void	ft_flags(const char *mod, int *i, t_struct *all);
int		ft_type_int(int d, t_struct *all);
void	ft_type_string(char *str, t_struct *all, int i);
void	ft_type_char(char c, t_struct *all);
int		ft_type_unsigned_int(int u, t_struct *all);
int		ft_type_hex_int(const char *mod, int *i, unsigned int x, t_struct *all);
int		ft_type_pointer(long p, t_struct *all);
void	ft_mini_tangle_first(char *s, t_struct *all, int hyphen);
void	ft_mini_tangle_second(char *s, t_struct *all, int neg);
void	ft_mini_tangle_third(char *s, t_struct *all, int width, int neg);
void	ft_mini_tangle_fifth(char *s, t_struct *all, int neg);
void	ft_mini_tangle_fourth(char *s, t_struct *all);
void	ft_positive_int(int d, char *s, t_struct *all);
void	ft_negative_int(char *s, char *s_neg, t_struct *all);
void	ft_pointer(int d, char *s, t_struct *all);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_atoi_invalid(const char *str);
void	ft_putchar_s(char c, int *data);
void	ft_putstr_size(char *s, int *size);
char	*ft_itoa(int n);
char	*ft_itoa_neg(int n);
char	*ft_unitoa(unsigned int n);
char	*ft_itoa_hex(long n, int big, int i);

#endif