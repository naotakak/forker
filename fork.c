#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>

int main() {
  printf("Before fork yurddddd\n");
  printf("Parent PID: %d\n", getpid());
  int c = fork();
  if (!c) {
    //fork();
    printf("Child PID: %d\n", getpid());
    int r;
    srand(getpid());
    r = (rand() % 16) + 5;
    sleep(r);
    printf("Child %d done in %d seconds\n", getpid(),r);
    return r;
  }
  else{
    int b = fork();
    if (!b) {
      printf("Child PID: %d\n", getpid());
      int r;
      srand(getpid());
      r = (rand() % 16) + 5;
      sleep(r);
      printf("Child %d done in %d seconds\n", getpid(), r);
      return r;
    }
    int a;
    wait(&a);
    printf("Received child exit signal. TIME: %d\n", WEXITSTATUS(a));
    exit(0);
  }
  return 0;
}
