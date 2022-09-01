#include "../include/cub3D.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

void	ft_clean_all(t_init *init)
{
	if (init->map)
		ft_free_split(init->map);
	if (init->game)
		free(init->game);
}
