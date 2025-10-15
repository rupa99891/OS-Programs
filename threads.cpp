#include <stdio.h>
#include <pthread.h>
void* threadFunc(void* arg) {
printf("Hello from thread!\n");
return NULL;
}
int main() {
pthread_t tid;
pthread_create(&tid, NULL, threadFunc, NULL);
pthread_join(tid, NULL);
printf("Thread execution completed.\n");
return 0;
}
