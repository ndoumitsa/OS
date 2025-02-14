#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
     for (int i=0; i<3; i++){
        pid_t pid=fork();

        if(pid < 0){
         printf("Fork failed\n");
         return 1;
       } else if (pid == 0){
         printf("Child %d, PID: %d, Parent PID:%d\n" ,i+1, getpid(), getppid());
         return 0;
       }
    }

    for (int i =0; i<3; i++){


          wait(NULL);

   }
   return 0;

}
