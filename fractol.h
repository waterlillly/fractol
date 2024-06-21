/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:12:56 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/06/21 23:35:01 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/ap_keysym.h>
# include <mlx.h>
# include <errno.h>
# include <error.h>

# define WIDTH	500
# define HEIGHT	500

typedef struct s_map
{
	double	nl;
	double	nh;
	double	ol;
	double	oh;
}				t_map;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		len;
}				t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_con;
	void	*mlx_win;
	int		def_iterations;
	t_img	img;
	double	esc_value;
	double	zoom;
	double	x_move;
	double	y_move;
	double	j_x;
	double	j_y;
}				t_fractol;

/*INIT*/
void		error_exit(char *s, t_fractol *f);
void		init_data(t_fractol *f);
void		init_events(t_fractol *f);
void		init_fractol(t_fractol *f);

/*RENDER*/
void		brot_or_juli(t_complex *c, t_complex *z, t_fractol *f);
void		f_pixel(int x, int y, t_fractol *f);
int			f_render(t_fractol *f);

/*COMPLEX*/
t_map		map_values(double nl, double nh, double ol, double oh);
double		scale(double i, t_map map);
t_complex	add_complex(t_complex res, t_complex c);
t_complex	complexify(t_complex z);

/*MLX_EVENTS*/
int			close_and_exit(t_fractol *f);
int			key_press(int key, t_fractol *f);
int			mouse_moves(int button, int x, int y, t_fractol *f);

/*JULIA*/
int			valid_julia(char **av);
void		choose_julia(t_fractol *f, char **av);
void		julia(t_fractol *f, char **av);

/*COLORS*/
# define BLACK				0x000000  // RGB(0, 0, 0)
# define WHITE				0xFFFFFF  // RGB(255, 255, 255)
# define RED				0xFF0000  // RGB(255, 0, 0)
# define GREEN				0x00FF00  // RGB(0, 255, 0)
# define BLUE				0x0000FF  // RGB(0, 0, 255)

/*FANCY COLORS*/
# define MAGENTA_BURST		0xFF00FF  // A vibrant magenta
# define LIME_SHOCK			0xCCFF00  // A blinding lime
# define NEON_ORANGE		0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE	0x660066  // A deep purple
# define AQUA_DREAM			0x33CCCC  // A bright turquoise
# define HOT_PINK			0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE		0x0066FF  // A radiant blue
# define LAVA_RED			0xFF3300  // A bright, molten red
# define VIOLET_FLAME		0xEE82EE  // A fiery violet
# define TURQUOISE_TWIST	0x40E0D0 // A twisted turquoise
# define SILVER_MOON		0xC0C0C0  // A cool silver
# define GOLDEN_SUN			0xFFD700  // A glowing gold
# define PINK_CHEER			0xFFB6C1  // A cheerful pink
# define TEAL_WAVE			0x008080  // A calming teal wave
# define ORANGE_SPIRIT		0xFFA500  // An energetic orange spirit
# define PURPLE_MYSTERY		0x800080  // A mysterious purple
# define CYAN_DREAM			0x00FFFF  // A dreamy cyan
# define BROWN_EARTH		0x8B4513  // A warm earth brown
# define GRAY_SKY			0xA9A9A9  // A soft gray sky
# define MAROON_DARK		0x800000  // A dark, rich maroon
# define NAVY_BLUE			0x000080  // A deep navy blue
# define PEACH_FIZZ			0xFFDAB9  // A fizzy peach
# define ROSE_GOLD			0xFFC0CB  // A soft rose gold
# define INDIGO_DARK		0x4B0082  // A dark, royal indigo
# define JADE_GREEN			0x009966  // A lush jade green
# define CHOCOLATE			0xD2691E  // A rich chocolate brown
# define LEMON_YELLOW		0xFFE639  // A bright, sunny lemon yellow
# define COBALT_BLUE		0x004085  // A deep cobalt blue
# define MINT_GREEN			0x7FFF00  // A fresh mint green
# define RUBY_RED			0xFF4500  // A bold ruby red
# define AMBER				0xF4A460  // A warm amber
# define PERIWINKLE			0xB06ABC  // A unique periwinkle
# define CORAL_PINK			0xFF7F50  // A vibrant coral pink
# define EMERALD_GREEN		0x008000  // A deep, rich emerald green
# define SAGE_GREEN			0x814F68  // A muted sage green
# define PLUM_PURPLE		0x9370DB  // A regal plum purple
# define TANGERINE			0xFFA54F  // A citrusy tangerine
# define WISTERIA			0x7789D6  // A delicate wisteria
# define SALMON				0xFA8072  // A bold salmon
# define THISTLE_PURPLE		0xD8BFD8  // A light thistle purple
# define OLIVE_DRAB			0x6B8E23  // A deep olive drab
# define POWDER_BLUE		0xB0E0E6  // A soft powder blue
# define STEEL_BLUE			0x4682B4  // A metallic steel blue
# define ROSE_QUARTZ		0xF49CA5  // A soft rose quartz
# define IVORY				0xFFFFF0  // A creamy ivory
# define BEIGE				0xF5F5DC  // A neutral beige
# define SANDSTONE			0xECC10B  // A sandy sandstone
# define MOSS_GREEN			0x98FB98  // A natural moss green
# define LAVENDER			0xE6E6FA  // A soft lavender
# define SNOW				0xFFF0F8F  // A pure snow white
# define ALMOND				0xEAECEE  // A pale almond
# define HONEYDEW			0xF0FFF0  // A light honeydew
# define AZURE				0xF0FFFF  // A clear azure
# define SEA_GREEN			0x2E8B57  // A deep sea green
# define DARK_SLATE_GRAY	0x2F4F4F  // A dark slate gray
# define LIGHT_SLATE_GRAY	0xB0C4DE  // A light slate gray
# define SKY_BLUE			0x87CEEB  // A clear sky blue
# define FOREST_GREEN		0x228B22  // A deep forest green
# define PALE_VIOLET		0xD1CDC8  // A soft pale violet
# define DEEP_SKY_BLUE		0x00BFFF  // A deep sky blue
# define DODGER_BLUE		0x1E90FF  // A vivid dodger blue
# define LIGHT_CORAL		0xF08080  // A bright light coral
# define MEDIUM_AQUAMARINE	0x7FFFD4 // A medium aquamarine
# define DARK_SEA_GREEN		0x2F4F4F  // A dark sea green
# define LIGHT_SEA_GREEN	0x20B2AA  // A light sea green
# define SPRING_GREEN		0x2E8B57  // A spring green
# define LIME_GREEN			0x32CD32  // A bright lime green
# define ANTIQUE_WHITE		0xFAEBD7  // A soft antique white
# define GHOST_WHITE		0xFFF8E7  // A very light ghost white
# define HAWTHORN_ROSE		0xFF7EA7  // A soft hawthorn rose
# define INDIAN_RED			0xCD5C5C  // A strong indian red
# define WILLIAMSHIRE_PINK	0xFF69B4  // A soft williamshire pink
# define ORCHID				0xDA70D6  // A beautiful orchid
# define THISTLE			0xD8BFD8  // A light thistle
# define GHOST_STORM		0x88EEFF  // A mystical ghost storm
# define FROG_GUTS			0x001F3F  // A deep frog guts green
# define BABY_PINK			0xFFB6C1  // A cute baby pink
# define OLD_LACE			0xFDF5E6  // A delicate old lace
# define POWDER_CHALK		0xF5F5F5  // A soft powder chalk
# define CREAM				0xF5F5DC  // A creamy cream
# define PAPAYA_WHIP		0xFFDFA0  // A vibrant papaya whip
# define MINT_TURF			0x7FFF00  // A fresh mint turf
# define AVOCADO			0x58D68D  // A rich avocado green
# define BUTTERSCOTCH		0xDE3163  // A sweet butterscotch
# define CANDY_APPLE		0xFF1493  // A juicy candy apple red
# define CINNAMON			0xDC4E29  // A warm cinnamon
# define CREAM_TEA			0xB87333  // A creamy tea
# define DARK_OLIVE_GREEN	0x556B2F  // A dark olive green
# define FLORAL_WHITE		0xFFFAF0  // A soft floral white
# define FUCHSIA			0xFF00FF  // A bright fuchsia
# define GAINSBOROUGH_ROSE	0x990099  // A deep gainsborough rose
# define HOLLY_GREEN		0x33691E  // A deep holly green
# define IRIS				0x99705A  // A soft iris
# define JAFFA_ORANGE		0xFF4000  // A bold jaffa orange
# define KELLY_GREEN		0x32CD32  // A bright kelly green
# define LEMON_CHIFFON		0xFFFACD  // A soft lemon chiffon
# define MACAROON			0xFFDABD  // A soft macaroon
# define NICKEL				0xC0C0C0  // A shiny nickel
# define OCHRE				0xFFA500  // A golden ochre
# define PEARL				0xFDD0C7  // A soft pearl
# define QUARTZ				0x7FFFD4  // A clear quartz
# define ROSE_BLOOM			0xFFC0CB  // A soft rose bloom
# define SAFFRON			0xFFA07A  // A bright saffron
# define TAUPE				0x673147  // A soft taupe
# define UBE				0x548B54  // A deep ube
# define VANILLA			0xFFC0CB  // A creamy vanilla
# define WATERMELON			0xFFB6C1  // A juicy watermelon
# define XANTHUS			0xD2B48C  // A soft xanthus
# define YELLOW_JEWEL		0xFFD700  // A bright yellow jewel
# define ZINC				0xB87333  // A shiny zinc
# define AMETHYST			0x9966CC  // A deep amethyst
# define BURNT_ORANGE		0xCC5500  // A burnt orange
# define CERULEAN			0x007BA7  // A deep cerulean
# define DUSK				0x4E5180  // A soft dusk
# define EGGPLANT			0x614051  // A deep eggplant
# define FAWN				0xE5AA70  // A soft fawn
# define GINGER				0xB06500  // A warm ginger
# define HONEY				0xE0CDA9  // A sweet honey
# define INDIGO				0x4B0082  // A deep indigo
# define JADE				0x00A86B  // A bright jade
# define KIWI				0x8EE53F  // A fresh kiwi
# define LAVENDER_BLUSH		0xFFF0F5  // A soft lavender blush
# define MINT				0x3EB489  // A fresh mint

#endif
