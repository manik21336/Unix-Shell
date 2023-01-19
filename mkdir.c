#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>



void mk(const char* directoryname){
   
    int value=0;
    mode_t m=S_IRWXU;
    value=mkdir(directoryname,m); //if value=0 -> Success
    if(value==-1){
        printf("Failed to create a directory\n");
    }
}

int _mk(const char* directoryname){
    int value=0;
    mode_t m=S_IRWXU;
    value=mkdir(directoryname,m); //if value=0 -> Success
    if(value==-1){
        printf("Failed to create a directory\n");
    }
    return value;
}
void _mkdi(char **path,int indexx){
    const char *directoryname=NULL;
    if(indexx!=1){
          // -v
        if(strcmp(path[1],"-v")==0){
            for(int i=2;i<indexx;i++){
                directoryname=path[i];
                int m=_mk(directoryname);
                if(m==0){
                    printf("mkdir: created directory '%s'\n",directoryname);
                }
            }
	}
   // -m

        else if(strcmp(path[1],"-m")==0){
            for(int i=3;i<indexx;i++){
                directoryname=path[i];
                int m=_mk(directoryname);
                if(m==0){
                    printf("mkdir: created directory '%s'\n",directoryname);
                }
            }
      	}
 //for simple mkdir
	else{
          for(int i=1;i<indexx;i++){
                directoryname=path[i];
                mk(directoryname);
            }
	}
    }
     else{
	printf("mkdir: missing operand");
	}

}



int main(int argc,char* argv[]){
	
	_mkdi(argv,argc);

	return 0;
}
