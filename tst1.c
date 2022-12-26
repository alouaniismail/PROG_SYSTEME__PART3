#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

//ctime la primitive est dans time.h:
//char* ctime(const time_t *timer).

int main(){
  time_t curtime;
  time(&curtime);
  printf("Current time=%s\n",ctime(&curtime));

  struct stat buffer;
  stat("file_tst1",&buffer);//stat c'est direct avec const($1).
  time_t curtime2=buffer.st_ctime;//heure derniere modification
  //soit creation dans ce cas.
  printf("Heure derniere modification=%s\n",ctime(&curtime2));//qui retourne
  //la date comprise.
  return 0;
}
