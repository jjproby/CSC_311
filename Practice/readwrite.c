#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

struct name {
  char first[12];
  char last[12];
};

int main() {
  FILE *another, *stream;
  int fo;
  char message[200];
  stream = fopen("file.txt", "r");
  fo = fread(message,22,1,stream);
  printf("%s\n", message);
  if(!fo){
    perror("fread");
    return 1;
  }
  fclose(stream);
  struct name mom;
  strcpy(mom.first, "Eleanor");
  strcpy(mom.last, "Tabak");

  another = fopen("name.txt", "w");
  fo = fwrite(&mom, sizeof(mom), 1, another);

  fclose(another);
}
