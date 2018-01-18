#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int fd;
  fd = open ("hello", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH);
  if (fd == -1){
    printf("%d\n", fd);
  }
    /* error */
  else{
    printf("%d\n", fd);
  }
}
