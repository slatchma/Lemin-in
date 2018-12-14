/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 02:31:52 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 12:04:02 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

int			ft_write_error(t_general *info, int code, int lign)
{
	info->error[code][0] = 1;
	info->error[code][1] = lign;
	info->erroractiv = 1;
	return (-1);
}

static void	ft_errorthree(t_general info)
{
	if (info.error[18][0] == 1)
		ft_printf("Error: line(%d): one of the rooms not exist\n",
		info.error[18][1]);
	if (info.error[19][0] == 1)
		ft_printf("Error: line(%d): there are 2 start's room\n",
		info.error[19][1]);
	if (info.error[20][0] == 1)
		ft_printf("Error: line(%d): there are 2 end's room\n",
		info.error[20][1]);
	if (info.error[21][0] == 1)
		ft_printf("Error: line(): error with start's room or end's room\n");
	if (info.error[22][0] == 1)
		ft_printf("Error: line(): no path found\n");
	if (info.error[23][0] == 1)
		ft_printf("Error: line(1): \"##start\" misplaced\n");
	if (info.error[24][0] == 1)
		ft_printf("Error: line(1): \"##end\" misplaced\n");
	if (info.error[25][0] == 1)
		ft_printf("Error: line(1): number of ants = 0\n");
	if (info.error[9][0] == 1)
		ft_printf("Error: line(%d): has same name as another room\n",
		info.error[9][1]);
	if (info.error[26][0] == 1)
		ft_printf("Error: line(): \"##start\" \"##end\" in same room\n");
}

static void	ft_errortwo(t_general info)
{
	if (info.error[10][0] == 1)
		ft_printf("Error: line(%d): has same coordinates as another room\n",
		info.error[10][1]);
	if (info.error[11][0] == 1)
		ft_printf("Error: line(%d): link already exist\n", info.error[11][1]);
	if (info.error[12][0] == 1)
		ft_printf("Error: line(%d): syntax's problem\n", info.error[12][1]);
	if (info.error[13][0] == 1)
		ft_printf("Error: line(%d): empty line\n", info.error[13][1]);
	if (info.error[14][0] == 1)
		ft_printf("Error: line(%d): link with a room that don't exist\n",
		info.error[14][1]);
	if (info.error[15][0] == 1)
		ft_printf("Error: line(%d): the number is not positiv\n",
		info.error[15][1]);
	if (info.error[16][0] == 1)
		ft_printf("Error: line(%d): \"##start\" use in the link's part\n",
		info.error[16][1]);
	if (info.error[17][0] == 1)
		ft_printf("Error: line(%d): \"##end\" use in the link's part\n",
		info.error[17][1]);
	ft_errorthree(info);
}

void		ft_error(t_general info)
{
	if (info.warningactiv == 1)
		ft_printf("\n---WARNING---\n");
	if (info.error[0][0] == 1)
		ft_printf("Error: line(%d): the number of ants not valid\n",
		info.error[0][1]);
	if (info.error[1][0] == 1)
		ft_printf("Error: line(): room not exist\n");
	if (info.error[2][0] == 1)
		ft_printf("Error: line(): link not exist\n");
	if (info.error[3][0] == 1)
		ft_printf("Error: line(%d): overflow\n", info.error[3][1]);
	if (info.error[4][0] == 1)
		ft_printf("Error: line(): not file\n");
	if (info.error[5][0] == 1)
		ft_printf("Error: line(): start's room not exist\n");
	if (info.error[6][0] == 1)
		ft_printf("Error: line(): end's room not exist\n");
	if (info.error[7][0] == 1)
		ft_printf("Error: line(%d): name contains \"-\"\n", info.error[7][1]);
	if (info.error[8][0] == 1)
		ft_printf("Error: line(%d): name begins with \"L\"\n",
		info.error[8][1]);
	ft_errortwo(info);
}
