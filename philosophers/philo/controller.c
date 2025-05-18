# include "philo.h"

int start_emulation(t_data *data)
{
    int i;
    pthread_t   examinator;
    
    data->start_time = get_timestamp();
    if (data->start_time == -1)
        return (1);
    i = 0;
    while (i < data->num_philos)
    {
        data->philosophers[i].last_meal_time = data->start_time;
        if (pthread_create(&data->philosophers[i].thread_id, NULL,
            philosopher_routine, &data->philosophers[i]))
            return (1);
        i++;
    }
    if (pthread_create(&examinator, NULL, examination_routine, data))
        return (1);
    if (pthread_detach(examinator))
        return (1);
    return (0);
}

int emulation_finished(t_data *data)
{
    int end;

    pthread_mutex_lock(&data->end_lock);
    end = data->emulation_end;
    pthread_mutex_unlock(&data->end_lock);
    return (end);
}