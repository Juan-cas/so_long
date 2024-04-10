
#include "../solong.h"

static void	next_data_node(t_objects **data_struct, t_objects *new_node)
{
	t_objects *holder;

	if (!data_struct)
		return ;
	if (!(*data_struct))
		*data_struct = new_node;
	else
	{
		holder = *data_struct;
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new_node;
	}
}

static t_objects *new_data(size_t y, size_t x)
{
	t_objects 	*big_list;

	big_list = (t_objects *)malloc(sizeof(t_objects));
	if (!big_list)
	{
		perror("Malloc Failed");
		exit(1);
	}
	big_list->col_x = x;
	big_list->col_y = y;
	big_list->next = NULL;
	return (big_list);
}

void collx_y(size_t y, size_t x, t_objects **status)
{
	t_objects *temp;

	temp = new_data(y, x);
	next_data_node(status, temp);
}