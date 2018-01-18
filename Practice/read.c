#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {

  int fd;
  void *buf;
  int len = 20;
  
  fd = open ("hello", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH);
  ssize_t ret;
  ret = read (fd, buf, 20);
  while ( len != 0 && ret != 0) {
    if (ret == -1) {
      if (errno == EINTR) continue;
      perror ("read");
      break;
    }
    len -= ret;
    buf += ret;
  }
  return 0;
}
