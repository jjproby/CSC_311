#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  unsigned long word = 1720;
  size_t count;
  int fd;
  fd = open ("crazy", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH);
  const char *buf = "My ship is solid!";
  ssize_t nr;

  /* write the string in 'buf' to 'fd'
  nr = write (fd, buf, strlen(buf));
  if (nr == -1){

  } */

  count = sizeof(word);
  nr = write (fd, &word, count);
  if (nr == -1) {
    printf("-1");
  }
  else if (nr != count){
    printf("0");
  }
  else {
    printf("1");
  }
    //error

}
