#define _XOPEN_SOURCE 500

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(){

  int fd;
  int ret;
  size_t count = 60;
  const char *buf = "HA! YOU'VE BEEN HACKED BY TOMMY AT THE VERIZON STORE!";
  ssize_t pw;
  off_t pos = 30;
  fd = open("fun.txt", O_RDWR, S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH);
  ret = truncate("fun.txt", pos);
  pw = pwrite(fd, buf, count, pos);
  printf("Hacking has been successful\n");

}
