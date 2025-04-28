#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_bool
{
	int ph_n;
	long time_d;
	long time_e;
	long time_s;
	long max_eat;
	pthread_mutex_t *fork;
} t_bool;

typedef struct s_philo
{
	int id;
	pthread_t thread;
	long last_time_eat;
	t_bool *table;
} t_philo;

int ft_atoi(const char *nptr);
int check_args(int argc, char **arg);
void *define_t_philo(int arr[]);
int create_threads(int arr[]);
void *rotin(void *thread);
void *define_table(int arr[]);

void *ft_free(void *arr, void *var1, void *var2);

#endif