#include <unistd.h>

int main(int argc, char const *argv[]) {

  int fd;
  int buf = 10;
  int len = 20;
  fd = open ("hello", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH);
  ssize_t ret;
  while ( len != && (ret = read (fd, buf, 20)) != 0) {
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
