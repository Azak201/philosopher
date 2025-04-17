#include "philo.h"

int main(int argc, char **argv)
{
	int arr[5];
	int i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv) == -1)
			return (1);
		while (i < 4)
		{
			arr[i] = ft_atoi(argv[i + 1]);
			if (arr[i] <= 0 || arr[0] == 1)
			{
				printf("Error in arguments\n");
				return (1);
			};
			i++;
		}
		if (argc == 6)
			arr[4] = ft_atoi(argv[5]);
		else
			arr[4] = 0;
		if ((create_threads(arr)) != 0)
			return (1);
	}
	return (0);
}

void *rotin(void *thread)
{
	t_philo *ph;

	ph = (t_philo *)thread;

	// philo_sleep
	if (ph->id % 2 == 0)
		usleep(ph->table->time_d * 1000);
	pthread_mutex_lock(&ph->table->fork[ph->id % ph->table->ph_n]);
	pthread_mutex_lock(&ph->table->fork[ph->id - 1]);
	printf("ruten for thread number %i,\t  fork number %i and %i \n", ph->id, ph->id - 1, ph->id % ph->table->ph_n);
	pthread_mutex_unlock(&ph->table->fork[ph->id % ph->table->ph_n]);
	pthread_mutex_unlock(&ph->table->fork[ph->id - 1]);
	// philo_eat

	// philo_thinking
	return (NULL);
}