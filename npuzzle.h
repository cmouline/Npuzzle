/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecouderc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:05:28 by ecouderc          #+#    #+#             */
/*   Updated: 2015/07/04 21:11:33 by ecouderc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <signal.h>
# include <curses.h>
# include <locale.h>

# define ASCII_1	" ____  _____    _______ _____  _____ ________ "
# define ASCII_2	"|_   \\|_   _|  |_   __ \\_   _||_   _|  __   _|"
# define ASCII_3	"  |   \\ | |______| |__) || |    | | |_/  / / |"
# define ASCII_4	"  | |\\ \\| |______|  ___/ | '    ' |    .'.' _"
# define ASCII_5	" _| |_\\   |_    _| |_     \\ \\__/ /   _/ /__/ |"
# define ASCII_6	"|_____|\\____|  |_____|     `.__.'   |________|"
# define ASCII_10	"________ _____    ________ "
# define ASCII_20	"  __   _|_   _|  |_   __  |"
# define ASCII_30	"_/  / /   | |      | |_ \\_|"
# define ASCII_40	"   .'.' _  | |   _  |  _| _ "
# define ASCII_50	"_/ /__/ |_| |__/ |_| |__/ |"
# define ASCII_60	"________|________|________|"
# define BLACK		"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[37m"
# define GREY		"\e[0;90m"
# define LRED		"\e[0;91m"
# define LGREEN		"\e[0;92m"
# define LYELLOW	"\e[0;93m"
# define LBLUE		"\e[0;94m"
# define LMAGENTA	"\e[0;95m"

# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define ABS(x)		(((x) < 0) ? -(x) : (x))
# define MIN(x, y)	(((x) < (y)) ? (x) : (y))
# define MAX(x, y)	(((x) < (y)) ? (y) : (x))

# define HASH_NUM	100000

# define PAD_CHAR " "

typedef struct		s_node
{
	int				i;
	int				j;
}					t_node;

typedef	struct		s_state
{
	unsigned int	id;
	int				**tab;
	t_node			start;
	int				score_g;
	int				score_f;
	int				open;
	int				closed;
	int				came_from;
	struct s_state	*neighbor[4];
	void			*openset;
}					t_state;

typedef struct		s_set
{
	t_state			*state;
	int				nb;
	struct s_set	*prev;
	struct s_set	*next;
}					t_set;

typedef struct		s_env
{
	int				fd;
	int				size;
	t_state			state_0;
	t_set			*openset[HASH_NUM];
	t_state			*current;
	t_set			*hist[HASH_NUM];
	t_node			*goal;
	t_set			*path;
	void			*win;
	int				win_h;
	int				win_w;
	int				solv;
	int				heur;
	int				man;
	int				ham;
	int				lin;
	int				oor;
	int				mxs;
	int				final_score;
	unsigned int	open_nb;
	unsigned int	open_max;
	unsigned int	open_select;
}					t_env;

typedef struct		s_col
{
	short			r;
	short			g;
	short			b;
}					t_col;

void				ft_error(char *s);
void				ft_read(t_env *e);
t_set				*ft_elem(t_state *state);
void				ft_add(t_set **set, t_set *elem);
void				ft_add_sort(t_set **set, t_set *elem);
void				ft_reposition(t_set **set, t_set *elem, t_set **old);
void				ft_remove(t_set **set, t_set *elem);
t_set				*ft_find(t_env *e, t_set *set, t_state *state);
int					heuristic_cost_estimate(t_env *e, t_state *state);
int					ft_manhattan(t_env *e, t_state *state);
int					ft_outof(t_env *e, t_state *state);
int					ft_hamming(t_env *e, t_state *state);
int					ft_linear(t_env *e, t_state *state);
int					ft_maxswap(t_env *e, t_state *state);
void				ft_print_grid(t_env *e, int **tab);
void				ft_print_goal(t_env *e);
void				ft_print_pos(t_env *e);
int					check_empty(t_env*e);
t_set				*ft_lowest_score(t_env *e);
int					reconstruct_path(t_env *e);
int					ft_astar_init(t_env *e);
int					ft_astar_init(t_env *e);
void				ft_goal(t_env *e);
int					ft_check_goal(t_env *e, int **tab);
t_state				*ft_state_cpy(t_env *e, t_state *state);
uint32_t			ft_state_id(t_env *e, t_state *state);
t_set				*ft_state_comp(t_env *e, t_set *hist, t_state *state);
void				ft_state_free(t_env *e, t_state *state);
int					**ft_tab_cpy(t_env *e, int **tab);
int					ft_tab_comp(t_env *e, int **tab1, int **tab2);
void				ft_tab_free(t_env *e, int **tab);
uint32_t			hash(const char *data, int len);
unsigned int		ft_count(t_set *set);
unsigned int		ft_count_hist(t_set **hist);
unsigned int		ft_max_hist(t_set **hist);
void				ft_sort(t_set **set);
void				ft_solvability(t_env *e);
int					ft_init_ncurses(t_env *e);
void				ft_stop_ncurses(int sig);
void				ft_ncurses(t_env *e);
void				ft_init_color();
void				ft_print_curr_grid(t_env *e, int **tab);
void				ft_print_text(t_env *e, t_set *path, int max_moves);

#endif
