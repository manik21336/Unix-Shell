#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int type(struct dirent *namelist){
	return namelist->d_type;
}


static int filter(const struct dirent *namelist){
	
	if((namelist->d_name[0])=='.'){return 0;}
	return 1;
}



extern int alphasort();

void ls(char *in_dire,char* flag)
{
    struct dirent **namelist;
    int n;
//     DIR *d=opendir(in_dire);
    if(strcmp(flag,"-a")==0){  // ls -a
//	printf(" \n\n %d\n\n",aflag);
        n = scandir(in_dire, &namelist, NULL, alphasort);
	for(int i=0;i<n;i++){
	    if(type(namelist[i])==DT_DIR){printf("\033[0;33m%s\033[0m       ", namelist[i]->d_name);continue;}
            printf("%s       ", namelist[i]->d_name);
	    if((i%4)==0){printf("\n");}
            free(namelist[i]);
        }
    }
    else if(strcmp(flag,"-r")==0){ // ls -r
	n = scandir(in_dire, &namelist, NULL, alphasort);
        while (n--){
	    if(type(namelist[n])==DT_DIR){printf("\033[0;33m%s\033[0m       ", namelist[n]->d_name);continue;}
            printf("%s       ", namelist[n]->d_name);
            free(namelist[n]);
        }

    }
    else if(strcmp(flag,"-")==0){
   	 n = scandir(in_dire, &namelist, filter, alphasort);
   	 if (n == -1){
    	   	 perror("scandir");
   	 }
	 else{
		for(int i=0;i<n;i++){
		    if(type(namelist[i])==DT_DIR){printf("\033[0;33m%s\033[0m       ", namelist[i]->d_name);continue;}
        	    printf("%s       ", namelist[i]->d_name);
        	    free(namelist[i]);    
        	}
	  }
    }
    free(namelist);
}


int main(int argc,char *argv[]){

	printf("\033[0m");

	if(argc==2){ls(argv[1],"-");}
	else{ls(argv[2],argv[1]);}
	return 0;
}

