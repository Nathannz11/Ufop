//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define N 5
#define LEFT (i + N -1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2


sem_t mutex;    /* exclusao mutua para as regioes criticas */
sem_t s[N];         /* um semaforo por filosofo */
int state[N];           /* arranjo para controlar o estado de cada um */
int nfilosofo[N] = {0, 1, 2, 3, 4};

void *philosopher(void*);
void take_forks(int);
void put_forks(int);
void test(int);


int main(){
    int i;
    pthread_t thread_id[N]; //identificadores das threads

    sem_init(&mutex, 0, 1);
    
    for(i = 0; i < N; i++)
        sem_init(&s[i], 0, 0);

    for(i = 0; i < N; i++)
    {
        pthread_create(&thread_id[i], NULL, philosopher, &nfilosofo[i]);
        //criar as threads
        printf("Filosofo %d esta a pensar.\n",i+1);
    }
    for(i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL); //para fazer a junção das threads

    return 0;

}

void *philosopher(void* i) /* i: o numero do filosofo, de 0 a N-1 */
{
    while (true) {      /* repete para sempre */
    int *aux = i;
    sleep(1); //think          /* o filosofo esta pensando */
    take_forks(*aux);      /* pega dois garfos ou bloqueia */
    sleep(1); //eat            /* hummm, espaguete! */
    put_forks(*aux);       /* devolve os dois garfos a mesa */
    }
}

void take_forks(int i)  /* i: o numero do filosofo, de 0 a N-1 */
{
    sem_wait(&mutex); //down      /* entra na região critica */
    state[i] = HUNGRY;  /* registra que o filosofo esta faminto */
    printf("Filosofo %d soltou 1 garfo e está com fome\n", i + 1);
    test(i);            /* tenta pegar dois garfos */
    sem_post(&mutex); //up         /* sai da região critica */
    sem_wait(&s[i]);  //down      /* bloqueia se os garfos não foram pegos */
    sleep(1);
}

void put_forks(int i)       /* i: o numero do filosofo, de 0 a N-1 */
{
    sem_wait(&mutex);//down     /* entra na regiao critica */
    state[i] = THINKING;/* o filosofo acabou de comer */
    printf("O filósofo %d soltou os garfos %d e %d!\n", i+1, LEFT+1, i+1);
    printf("O filósofo %d está pensando!\n", i+1);
    test(LEFT);         /* ve se o vizinho da esquerda pode comer agora */
    test(RIGHT);        /* ve se o vizinho da direita pode comer agora */
    sem_post(&mutex);//up         /* sai da regiao critica */
}

void test(int i)            /* i: o numero do filosofo, de 0 a N-1 */
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        sem_post(&s[i]);//up /* libera se houver garfos bloqueados */
        sleep(2);
        printf("O filósofo %d pegou os garfos %d e %d!\n", i+1, LEFT+1, i+1);
        printf("O filósofo %d está comendo!\n", i+1);
        sem_post(&mutex);
    }
}