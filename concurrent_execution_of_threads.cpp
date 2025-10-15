#include <stdio.h>
#include <pthread.h>
void* task1(void* arg) {
for(int i=0;i<5;i++) printf("Task 1 running\n");
return NULL;
}
void* task2(void* arg) {
for(int i=0;i<5;i++) printf("Task 2 running\n");
return NULL;
}
int main() {
pthread_t t1, t2;
pthread_create(&t1, NULL, task1, NULL);
pthread_create(&t2, NULL, task2, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
printf("Both threads finished execution.\n");
return 0;
} 
