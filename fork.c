#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int f;
  printf("Before fork yurddddd\n");
  f = fork();
  int r = rand() % (20 + 1 - 5) + 5;
  int a = rand() % (20 + 1 - 5) + 5;
  if (f == 0) {
    int c = fork();
    printf("Child PID: %d\n", getpid());
    if (c) {
      sleep(r);
    }
    else {
      sleep(a);
    }
    printf("Child %d done\n", getpid());
  }

    int child = wait();
    printf("Child %d exited, slept for xx seconds\n", child);

  return 0;
}