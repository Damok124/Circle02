/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:48:56 by zharzi            #+#    #+#             */
/*   Updated: 2022/09/13 17:49:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MLX_ERROR 1

# include "X11/keysym.h"
# include "X11/X.h"
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "ft_printf.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_vars {
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*hexcolor;
	unsigned int	color;
}			t_vars;

typedef struct s_spot {
	int	x;
	int	y;
	int	z;
}			t_spot;

void	ft_test(void);
/////////////////////////
//	CATEGORY
/////////////////////////
char	ft_base_key(int *tab, int key);
int		ft_manual_color(t_vars *vars, int key);
int		ft_renew_image(t_vars *vars);
int		ft_keypress(int key, t_vars *vars);
int		ft_click_cross(t_vars *vars);
void	ft_end_mlx(t_vars *vars);
void	ft_pixel_put(t_vars *vars, int x, int y, unsigned int color);
int		ft_dot(int button, int x, int y, t_vars *vars);

#endif
