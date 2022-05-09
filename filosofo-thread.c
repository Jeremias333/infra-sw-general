#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

#define EATING 0
#define HUNGRY 1
#define THINKING 2

int state[5] = {THINKING};
sem_t s[5];
sem_t mutex;

void *philosofer(void*);
void take_fork(int);
void put_fork(int);
void eat(int);

int main(){

    pthread_t threads[5];
    int phil_id[5] = {0, 1, 2, 3, 4};

    sem_init(&mutex, 0, 1);

    for(int i = 0; i < 5; i++){
        sem_init(&s[i], 0, 0);
    }

    for(int i = 0; i < 5; i++){
        pthread_create(&threads[i], NULL, philosofer, &phil_id[i]);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *philosofer(void *id){

    int *i = id;

    while(1){
        sleep(1);
        take_fork(*i);
        sleep(1);
        put_fork(*i);
    }
}

void take_fork(int id){

    sem_wait(&mutex);
    state[id] = HUNGRY;

    printf("Philosopher %d is HUNGRY\n", id);
    //(id atual + (total-1))/total  &&  (id atual + 1)/total
    if(state[(id+4)%5] != EATING && state[(id+1)%5] != EATING){
        state[id] = EATING;
        printf("Philosopher %d takes fork %d and %d\n", id,(id+4)%5, id);
        printf("Philosopher %d is EATING\n", id);
    }

    sem_post(&mutex);

    if(state[id] == HUNGRY){
        sem_wait(&s[id]);
    }
}

void put_fork(int id){

    sem_wait(&mutex);
    state[id] = THINKING;

    printf("Philosopher %d put fork %d and %d down\n", id, (id+4)%5, id);
    printf("Philosopher %d is thinking\n", id);

    eat((id+4)%5);
    eat((id+1)%5);
    sem_post(&mutex);
}

void eat(int id){
    if(state[id] == HUNGRY && state[(id+4%5)] != EATING &&
        state[(id+1)%5] != EATING){
            state[id] = THINKING;

            printf("Philosopher %d takes fork %d and %d\n", id,(id+4)%5, id);
            printf("Philosopher %d is EATING\n", id);

            sem_post(&s[id]);
    }
}