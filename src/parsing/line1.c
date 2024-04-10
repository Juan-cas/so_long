
#include "../solong.h"

int line1(const char *line)
{
	int	i;

	i = 0;
	while(line[++i])
	{
		if (line[i] != '1')
			return (0);
	}
	return (1);
}