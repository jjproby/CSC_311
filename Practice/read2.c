#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {


  printf("%s\n", "hello");
  int fd;
  char word[8];
  ssize_t nr;
  fd = open ("hello.txt", O_RDONLY, S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH);
  printf("%d\n", fd);
  nr = read( fd, &word, sizeof(unsigned long));
  if (nr == -1) {
    printf("-1");
  }
  printf("%s\n", word);

}
