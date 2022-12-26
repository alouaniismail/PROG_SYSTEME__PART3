#include <stdio.h>
#include <unistd.h>//ça introduit tout..

int main(int argc, char *argv[])
{
   char optstring[]="abc";  // options permises -a -b et -c
   int c;

   
    // tant qu'il reste des options
   while( (c=getopt (argc, argv, optstring)) != EOF )
   {
           // on affiche ces options
          printf("-%c\n",(char) c);
	  printf("%s\n",argv[optind]);//on affiche a chaque fois
	  //ce que -a VAUT.
   }
   
   // on affiche le premier argument.
   printf("%s\n",argv[optind]);//le 1er argument
   //pour définir ce que cette variable EXTERN définit en globalement..
   
  return 0;
} 
