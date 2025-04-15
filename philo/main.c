#include "philo.h"


int main(int argc,char **argv)
{
	int arr[5];
	int i;

	i=0;
	if(argc ==5)
	{
		if(check_args(argc,argv)==-1)
			return 0;
		while(i<4)
		{
			arr[i]= ft_atoi(argv[i+1]);
			i++;
		}
		arr[4]=0;
		if((creat_threads(arr))!=0);
		return (0);
	}
	// else if (argc == 6)
	// {
	// }
	return (0);
}



void *rotin(void* thread)
{
	t_philo *philo;

	philo = (t_philo *)thread;
	
	//philo_sleep
	pthread_mutex_lock(&philo->table->fork[philo->id]);
	printf("ruten for thread number %i",philo->id);
	pthread_mutex_unlock(&philo->table->fork[philo->id]);
	// philo_eat


	// philo_thinking
	return (NULL);
}