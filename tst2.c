#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h> //surtout celle-ci sys et pas stat!!(2 fois nn)
#include<sys/stat.h>
#include<pwd.h>

//la primitive dans pwd.h de getpwuid
//est: struct passwd* getpwuid(uid_t uid)
//et il faut se rappeler que pour un fichier
//avec un i-node le marquant
//on a l'information uid_t st_uid qui définit le uid du propriétaire.

int main(void){
  struct passwd* pw;
  if((pw=getpwuid(getuid()))==NULL){
    fprintf(stderr,"getpwuid: no password entry\n");
    return ( EXIT_FAILURE );
  }

  printf("login_name %s\n",pw->pw_name);
  printf( "user id     %d\n", pw->pw_uid );
  printf( "group id    %d\n", pw->pw_gid );
  printf( "home dir    %s\n", pw->pw_dir );
  printf( "login shell %s\n", pw->pw_shell );
  //application pour un fichier pour savoir le pw d'un fichier notamment
  //celui de file_tst2.

  struct stat buffer;
  stat("file_tst2",&buffer);
  uid_t uid=buffer.st_uid;//UID propritaire.
  struct passwd* pw2;
  pw2=getpwuid(uid);//struct passwd* getpwuid(uid_t uid).
  printf("login_name %s\n",pw2->pw_name);
  printf("user id %d\n",pw2->pw_uid);
  //voilà.
  //on déclare un struct passwd*
  //puis on récupère depuis stat le st_uid
  //qu'on passe en parametre
  //pour avoir pw2 updated puis pw2->name/pw2->uid définit(en %d pour le 2ieme)
  //le login_name ainsi que le user id (l'identificateur de l'utilisateur
  //du UID propriétaire).
  //avec cela on a le créateur (la 1ere partie suffit largement).
  return 0;
}
