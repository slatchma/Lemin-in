/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 19:04:28 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/08 01:08:54 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

typedef struct		s_dsplay
{
	char			*name;
	int				ant;
	struct s_dsplay	*next;
}					t_dsplay;

typedef struct		s_way
{
	int				id;
	int				step;
	int				bestway;
	char			*save;
	struct s_way	*next;
}					t_way;

typedef struct		s_link
{
	struct s_room	*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				coord[2];
	int				start;
	int				end;
	struct s_link	*roomlink;
	struct s_room	*next;
}					t_room;

typedef struct		s_general
{
	int				ants;
	int				state;
	int				phase;
	int				signalstart;
	int				signalend;
	unsigned int	error[30][2];
	int				erroractiv;
	int				warningactiv;
}					t_general;

t_room				*ft_lemin_parsing(t_room *listroom, t_general *info,
					char **savetext);
int					ft_room(t_room **listroom, t_general *info, int nb,
					char *line);
t_room				*ft_lstroom(t_room *listroom, char *line, t_general *info,
					int nb);
int					ft_link(t_room **listroom, t_general *info, int nb, char
					*line);
void				ft_error(t_general info);
int					ft_write_error(t_general *info, int code, int lign);
t_room				*ft_lstlink(t_room *listroom, char *line, t_general *info,
					int nb);
int					ft_lasttest(t_room *listroom, t_general *info);
t_way				*ft_backtracking(t_room *listroom, t_way *lstway,
					t_general *info);
int					*ft_treatment(t_room *listroom, t_way *lstway,
					t_general info);
void				ft_searchcomb(int *tabsave, int **tab,
					int min_idmax_ants[3], t_way *lstway);
int					ft_wayunic(int **tab, t_way *lstway);
t_room				*ft_searchstart(t_room *listroom);
int					ft_idem(t_room *roomstart, char *way);
void				ft_waystep(t_way **lstway);
void				ft_display(int ants, int *savecomb, t_way *lstway,
					int compt);
int					ft_mintab(int compt, int step[compt]);
void				ft_print_ant(int compt, t_dsplay *dway[compt],
					int step[compt], int ants);
void				ft_init_step(int **tab, t_way *lstway);
void				ft_general_initialize(t_general *info);
int					ft_tcheck(t_dsplay *dway);
int					ft_verif(int compt, t_dsplay *dway[compt]);
int					ft_particular(t_general *info, t_room *listroom,
					char *savetext);
void				ft_print_ant_two(int compt, t_dsplay *dway[compt]);
t_dsplay			*ft_ant_next(t_dsplay *dway);
#endif
