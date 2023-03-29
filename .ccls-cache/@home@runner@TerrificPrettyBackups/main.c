#include <pthread.h> //thread library header 
#include <stdio.h>   //i/o library header 

unsigned long sum[4];   //array to store partial sums for each of the 4 threads.

void *thread_fn(void *arg) {  // each thread will execute this funtion 
  long id = (long) arg; //Convert void pointer argument to a long integer (for thread ID)
  int start = id * 2500000; //Calculate the start of partial sum based on thread ID
  
  int i = 0; //for the while loop below 
  while (i<2500000) { // loop to calculate the thread's partical sum 
    sum[id] += (i + start);
    i++;
  }
  return NULL; // return nothing when the function is done
}

int main() {

  pthread_t t1, t2, t3, t4; // creating 4 threads
  pthread_create(&t1, NULL, thread_fn, (void *)0); // calculating partical sums
  pthread_create(&t2, NULL, thread_fn, (void *)1); // calculating partical sums
  pthread_create(&t3, NULL, thread_fn, (void *)2); // calculating partical sums
  pthread_create(&t4, NULL, thread_fn, (void *)3); // calculating partical sums

  pthread_join(t1, NULL); // telling main to wait for all threads to finish computing 
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);

  printf("%lu\n", sum[0] + sum[1] + sum[2] + sum[3]); // compute
  
}