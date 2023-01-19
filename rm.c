#include <stdio.h>
#include <unistd.h>
#include <string.h>


void _rm(char *pathname){
    int value;
    value=unlink(pathname);
    if(value==-1){
        printf("rm: Failed to Remove %s\n",pathname);
    }
}

void _rm1(char *pathname){
    int value;
    value=remove(pathname);
    if(value==-1){
        printf("rm: Failed to Remove %s\n",pathname);
    }
}

// For Other implementation
/*
void _rm2(char *pathname){
    int value;
    value=unlinkat(0,pathname,AT_REMOVEDIR);
    if(value==-1){
        printf("rm: Failed to Remove %s\n",pathname);
    }
}
*/

void rm(char **pathname,int indexx){

    if(indexx!=1){
        if(strcmp(pathname[1],"-r")==0){  // rm -r
            if(indexx==2){printf("rm: missing operand\n"); return;}
            for(int i=2;i<indexx;i++){
                _rm1(pathname[i]);
            }
	}
        else if(strcmp(pathname[1],"-i")==0){ // rm -i
            if(indexx==2){printf("rm: missing operand\n"); return;}
            for(int i=2;i<indexx;i++){
                int inp;
                printf("rm: remove file %s (1/0): ",pathname[i]);
                scanf("%d",&inp);
                if(inp==1){_rm1(pathname[i]);} 
             }
	}
	else{
	    if(indexx==1){printf("rm: missing operand\n"); return;}
      		for(int i=1;i<indexx;i++){
       		    _rm(pathname[i]);
       		 }
 	}
     }
     else{
	printf("rm: missing operands");
	}
}





int main(int argc,char* argv[]){
	rm(argv,argc);
	return 0;
}
