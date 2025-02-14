#include <stdio.h>
#include <unistd.h>


int main(){
   int fd[2];
   char buffer[20];
   
   pipe(fd);
   if (fork() == 0){
     close(fd[1]);
     read(fd[0],buffer,sizeof(buffer));
     printf("Child received: %s\n", buffer);
  } else{
    close(fd[0]);
    write(fd[1]," hello",7);

  }

  return 0;
}
