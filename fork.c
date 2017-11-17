#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>

int main() {
  printf("Before fork yurddddd\n");
  fork();
  int c = fork();
  if (!c) {
    printf("Child PID: %d\n", getpid());
    srand(time(NULL));
    int r = rand() % (20 + 1 - 5) + 5;
    sleep(r);
    printf("Child %d done in %d seconds\n", getpid(),r);
    exit(r);
  }
  else{
    int a;
    int pid = wait(&a);
    printf("Received child exit signal. TIME: %d\n", WEXITSTATUS(a));
    printf("Done! status: %d\n", pid);
  }

  return 0;
}
