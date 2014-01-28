#include "fs_lib.h"
#include "stdio.h"

#define DEBUG printf("wat\n"); fflush(stdout);

int test_write() {
  int srvhndl, fd, i;
  char *buffer = "wololo"; 

  fs_openserver("127.0.0.1", "TCP", 9000, &srvhndl);
  fs_open(srvhndl, "test3.txt", &fd);
  DEBUG
  fs_write(srvhndl, fd, buffer,5);
  fs_close(srvhndl, fd);
  DEBUG
  for(i=0; i<5; i++){
    printf("%c", buffer[i]);
  }
  printf("\n");
  fflush(stdout);
}

int test_read() {
  int srvhndl, fd, i;
  char buffer[1024];

  fs_openserver("127.0.0.1", "TCP", 9001, &srvhndl);
  fs_open(srvhndl, "test3.txt", &fd);
  DEBUG
  fs_read(srvhndl, fd, buffer,5);
  DEBUG
  for(i=0; i<5; i++){
    printf("%c", buffer[i]);
  }
  printf("\n");
  fflush(stdout);
}

int main(int argc, char **argv){
  test_read();
  return 0;
}