#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int rand_num() {
  int dev = open("/dev/random", O_RDONLY);
  int buff;
  read(dev, &buff, 4);
  close(dev);
  return buff;
}

int main() {
  int a[10];
  int b[10];
  int i = 0;
  for (; i < 10; i++) {
    a[i] = rand_num();
    printf("%d\n", a[i]);
  }
  printf("-------------------------------\n");
  int f = open("file", O_CREAT|O_WRONLY, 0644);
  write(f, a, 40);
  close(f);
  f = open("file", O_RDONLY);
  read(f, b, 40);
  close(f);
  i = 0;
  for (; i < 10; i++)
    printf("%d\n", b[i]);
  return 0;
}
