#include "philo.h"

void ft_free(void *arr, void *var1, void *var2);
t_bool * define_table(int arr[]);

int creat_threads(int arr[])
{
	t_philo *threads;
	int i;

	i = -1;
	threads =define_t_philo(arr);
	if(!threads)
	{
		printf("Error in defining threads");
		return(1);
	}
	while(++i<arr[0])
		pthread_create(&threads[i].thread,NULL,&rotin,&threads[i]);
	i = 0;
	while(i<arr[0])
	{
		pthread_join(threads[i].thread,NULL);
		i++;
	}
	i = 0;
	while(i<arr[0])
	{
		pthread_mutex_destroy(&threads[0].table->fork[i]);
		i++;
	}
	ft_free(threads,threads->table->fork,threads->table);
	return(0);
}

t_philo *define_t_philo(int arr[])
{
	t_philo *threads;
	t_bool *table;
	int i;

	i = -1;
	threads = malloc(sizeof(t_philo) * (arr[0]+1));
	if(!threads)
		return (NULL);
	table = define_table(arr);
	if (!table)
	{
		free(threads);
		return (NULL);
	}
	while(++i < arr[0])
	{
		threads[i].id=i+1;
		threads[i].last_time_eat= 0;
		threads[i].table = table;
		if((pthread_mutex_init(&table->fork[i],NULL))!=0)
			{
				ft_free(threads,table->fork,table);
				return (NULL);
			}
	}
	return threads;
}
t_bool * define_table(int arr[])
{
	t_bool *table;

	table = malloc(sizeof(t_bool)+1);
	if (table == NULL)
	{
		printf("Error: fail in allocate table\n");
		return (NULL);
	}
	table->fork = malloc(sizeof(pthread_mutex_t ) * (arr[0]+1));
	if (table->fork ==NULL)
	{
		printf("Error: fail in allocate table->fork\n");
		free (table);
		return (NULL);
	}
	table->time_d= arr[1];
	table->time_e= arr[2];
	table->time_s= arr[3];
	table->max_eat= arr[4];
	return (table);
}

void ft_free(void *arr, void *var1, void *var2)
{
	int i;
	
	i = 0;
	if(var1)
		free(var1);
	if(var2)
		free(var2);
	if(arr)
		free(arr);
}