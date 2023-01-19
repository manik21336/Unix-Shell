#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<readline/history.h>
#include<unistd.h>
#include<readline/readline.h>
#include<sys/wait.h>
#include <stdio.h>
#include <pthread.h>


#define Max_letters 1024
#define Max_commands 100

#define clear() printf("\033[H\033[J")

int indexx;
void red () {
  printf("\033[1;31m");
}

void yellow(){
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void spaces(int count){
    for(int i=0;i<count;i++){
        printf(" ");
    }
}

void stars(int count){
    for(int i=0;i<count;i++){
        printf("*");
    }
}
void printlogo(){
    red();
    int n=8;
    printf("\n");
    for (int i = 0; i < n; ++i) {
	red();
	spaces(n-i-1);
        stars(i + 1);
	spaces(n - i - 1);
        stars(n - i + 1);
	spaces(2 * i);
        yellow();
        stars(n - i);
        spaces(n - i - 1);

        stars(i + 1);
	char *s=((i==n-1)? " \033[0;31mimix\n":"\n");
        printf("%s",s);
	}
    red();
    printf("\n Wimix_0.0.1 Linux Shell\n");
    printf(" Author: Manik Sharma\n\n");


    reset();
}




char* pwd(char *d){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    d=cwd;
    return d;
    
}





void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else {
        // waiting for child to terminate
        wait(NULL); 
        return;
    }
}


void* executer(void* str){
	char* d=(char*)str;
	system(d);
	printf("\n");
}

void pthread_ownCmdHandler(char **parsed,char* str){
	pthread_t p;

	if(strcmp(parsed[1],"ls")==0){
		char u_str[200]="./";
		int i;
		for(i=2;str[i+1]!='\0';++i){
			u_str[i]=str[i+1];
		}
		int m=i;
		i++;
		char cwd[1024];
		getcwd(cwd,sizeof(cwd));
		strcat(strcat(u_str," "),cwd);
//		puts(u_str);printf("\n");
		int v=pthread_create(&p,NULL,executer,(void*)u_str);
		if(v!=0){printf("Failed to Create thread\n");}
		pthread_join(p,NULL);
	}
	else if((strcmp(parsed[1],"mkdir"))*(strcmp(parsed[1],"rm"))*(strcmp(parsed[1],"cat"))*(strcmp(parsed[1],"date"))==0){
		char u_str[200]="./";
		int i;
		for(i=2;str[i+1]!='\0';++i){
			u_str[i]=str[i+1];
		}
		u_str[i]='\0';
		int v=pthread_create(&p,NULL,executer,(void*)u_str);
		if(v!=0){printf("Failed to create thread"); return;}
		pthread_join(p,NULL);
	}
	else{
		printf("-bash: %s: Command not found",parsed[1]);
	}


}
int indexxx=0;
int ownCmdHandler(char** parsed)
{
     reset();
    int N_cmds = 11, i, switchOwnArg = 0;
    char* L_cmds[N_cmds];
    char* username;
    L_cmds[0] = "exit";
    L_cmds[1] = "cd";
    L_cmds[2] = "help";
    L_cmds[3] = "hello";
    L_cmds[4] = "pwd";
    L_cmds[5] = "echo";
    L_cmds[6] = "ls";
    L_cmds[7] = "cat";
    L_cmds[8] = "date";
    L_cmds[9] = "mkdir";
    L_cmds[10] = "rm";
 
    for (i = 0; i < N_cmds; i++) {
        if (strcmp(parsed[0], L_cmds[i]) == 0) {
            switchOwnArg = i + 1;
            break;
        }
    }
    switch (switchOwnArg) {
    case 1:
        printf("Goodbye\n");
        exit(0);
    case 2:
        if(parsed[1]==NULL){
            chdir (getenv ("HOME"));
        }
        else if(parsed[1]==".."){
            chdir("..");
        }
        else{
            chdir(parsed[1]);
        }
        return 1;
    case 3:
    	printf("Welcome to Wimix_0.0.1 ");
	printf("Author: Manik Sharma\n\n");
        printf(" Supported Commands: \n");
        printf(" 1)hello \n");
        printf(" 2)cd \n");
        printf(" 3)pwd \n");
        printf(" 4)echo \n");
        printf(" 5)ls \n");
        printf(" 6)cat \n");
        printf(" 7)exit \n");
        printf(" 8)hello \n");

        return 1;
    case 4:
        username = getenv("USER");
        printf("\nHello %s.\nMind that this is "
            "not a place to play around."
            "\nUse \033[1;33mhelp\e[0m to know more..\n",
            username);
        return 1;
    case 5:
 	char* m;
        m=pwd(m);
	printf("%s",m);
        return 1;
    case 6:
        for(int i=1;i<indexx;i++){
            printf("%s ",parsed[i]);
        }
        return 1;
    case 7:                
	char *d;
	char cwd[1024];
	getcwd(cwd,sizeof(cwd));
	d=cwd;
	if(indexx==1){parsed[1]="-";}
	if(fork()==0){
		int v=execl("/home/manik/Assignment_01/Assignment_02/ls",parsed[0],parsed[1],d,NULL);
		if(v==-1){printf("Command could not be executed\n");}
	}
	else{wait(NULL);}
	printf("\n");
        return 1;
    case 8:
	if(fork()==0){
		int v=execv("/home/manik/Assignment_01/Assignment_02/cat",parsed);
		if(v==-1){printf("Command could not be executed\n");}
	}
	else{wait(NULL);}
	printf("\n");
        return 1;

    case 9:
	if(fork()==0){
		int v=execv("/home/manik/Assignment_01/Assignment_02/date",parsed);
		if(v==-1){printf("Command could not be executed\n");}
	}
	else{wait(NULL);}
	printf("\n");
        return 1;

    case 10:
	if(fork()==0){
		int v=execv("/home/manik/Assignment_01/Assignment_02/mkdir",parsed);
		if(v==-1){printf("Command could not be executed\n");}
	}
	else{wait(NULL);}
	printf("\n");
        return 1;

    case 11:
	if(fork()==0){
		int v=execv("/home/manik/Assignment_01/Assignment_02/rm",parsed);
		if(v==-1){printf("Command could not be executed\n");}
	}
	else{wait(NULL);}
	printf("\n");
        return 1;



    default:
	printf("-bash: %s: Command not found",parsed[0]);
        break;
    }
    return 0;
}



int Input_take(char *in){
    red();
    char* buf;
    char* username=getenv("USER");
    printf("\n[%s]",username);
    yellow();
    buf =readline("$ ");
    reset();
    if (strlen(buf) != 0) {
        add_history(buf);
        strcpy(in, buf);
        return 0;
    } else {
        return 1;
    }
}


void parseSpace(char* str, char** parsed)
{
    int i; 
    for (i = 0; i < Max_commands; i++) {
        parsed[i] = strsep(&str, " ");

        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
    indexx=i;
}

int processString(char* str, char** parsed)
{
    char *s=(char*)malloc(1024*sizeof(char));
    int i;
    for(i=0;str[i]!='\0';i++){
	s[i]=str[i];
    }
    s[i]='\0';
    parseSpace(str, parsed);
    int flag=((str[0]=='&')? 1:0);
    if(flag){pthread_ownCmdHandler(parsed,s);free(s); return 0;}
    if(ownCmdHandler(parsed))
        return 0;
}
  

int main(){
    red();
        clear();
        printf("------------------------Welcome to Custom Shell--------------------\n\n");
        char* username=getenv("USER");
        printf("Username: %s",username);
        printf("\n");
        sleep(5);
        clear();
    printlogo();
     reset();
    char input[Max_letters], *parsedargs[Max_commands];
    int execFlag=0;
    while(1){
        if(Input_take(input)){
            continue;
        }
        execFlag =processString(input,parsedargs);
        if(execFlag==1){
            execArgs(parsedargs);
        }
    }
    return 0;
}
