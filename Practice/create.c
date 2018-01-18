#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int fd;
  fd = creat( "pracCreat", 0644);
  if (fd == -1){
    printf("%d\n", fd);
  }
    /* error */
  else{
    printf("%d\n", fd);
  }
}
