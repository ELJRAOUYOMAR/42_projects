#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>
# include <string.h>

/* Error codes */
# define ERR_ARGS        "Invalid arguments\n"
# define ERR_MALLOC      "Memory allocation failed\n"
# define ERR_MUTEX       "Mutex initialization failed\n"
# define ERR_THREAD      "Thread creation failed\n"

/* Philo status messages */
# define TAKEN_FORK      "has taken a fork"
# define EATING          "is eating"
# define SLEEPING        "is sleeping"
# define THINKING        "is thinking"
# define DIED            "died"

typedef struct s_philo
{
    int             id;
    pthread_t       thread_id;
    int             left_fork_id;
    int             right_fork_id;
    int             meals_eaten;
    long long       last_meal_time;
    struct s_data   *data;
}   t_philo;

typedef struct s_data
{
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_meals;
    int             meals_specified;
    int             emulation_end;
    long long       start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t end_lock;
    t_philo         *philosophers;
}   t_data;

/* utils */
int ft_atoi(char *str);
int check_args(int ac, char **av);
void    print_status(t_data *data, int id, char *status);
int exit_with_error(char *message, t_data *data);

/* init */
int init_data(t_data *data, int ac, char **av);
int init_mutexes(t_data *data);
int init_philos(t_data *data);

/* time */
long long get_timestamp();
long long	time_difference(long long past, long long present);
void precise_sleep(long long time_sleep_in_ms);

/* routines */
void *philosopher_routine(void *arg);
void take_forks(t_philo *philo);
void eat(t_philo *philo);
void put_down_forks(t_philo *philo);

/* examination */
void *examination_routine(void *arg);
int	check_philo_death(t_data *data, int *i);
int check_each_philo_eat(t_data *data);

/* controller (emulation) */
int start_emulation(t_data *data);
int emulation_finished(t_data *data);

/* clean_up */
void *clean_up(t_data *data);
void join_threads(t_data *data);

#endif