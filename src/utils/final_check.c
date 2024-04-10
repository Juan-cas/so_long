
#include "../solong.h"

static void repopulate_map(char **map, t_objects **status)
{
	t_objects *temp;

	temp = (*status)->next;
	map[(*status)->py_coord][(*status)->px_coord] = 'P';
	while(temp)
	{
		map[temp->col_y][temp->col_x] = 'C';
		temp = temp->next;
	}
}

static void cleanse_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

static void roadtoexit(char **map, t_objects **status)
{
	if (map[(*status)->ey_coord + 1][(*status)->ex_coord] == 'P')
		return ;
	else if (map[(*status)->ey_coord - 1][(*status)->ex_coord] == 'P')
		return ;
	else if (map[(*status)->ey_coord][(*status)->ex_coord + 1] == 'P')
		return ;
	else if (map[(*status)->ey_coord][(*status)->ex_coord - 1] == 'P')
		return ;
	else
	{
		perror("Map doesn't have a valid way to exit");
		exit(1);
	}
}

void final_check(char **map, t_objects **status)
{
	find_coords_e(map, status);
	roadtoexit(map, status);
	cleanse_map(map);
	repopulate_map(map, status);
}