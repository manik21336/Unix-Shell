#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define limit 45
#include <unistd.h>
#include <string.h>



void _date(int key){
	   	char buf[limit];
		struct timeval t_val;
		time_t ctime;
		gettimeofday(&t_val,NULL);
		ctime=t_val.tv_sec;
		switch(key){
			case 1:
				strftime(buf,30,"%m-%d-%Y   %T.\n",localtime(&ctime));
	 			puts(buf);
				return;
			case 2:
				strftime(buf,30,"%a, %d %b %Y %T %z\n",localtime(&ctime));
	 			puts(buf);
				return;
		}

		
		
		return;
}


void _date2(){
	time_t t=time(&t);
	if(t==-1){
		printf("Function failed\n");
	}
	struct tm *prime_time=gmtime(&t);
	if(prime_time==NULL){
		printf("Function failed\n");
	}
	printf("%s\n",asctime(prime_time));



}




int main(int argc,char* argv[]){
	printf("\033[0m");
	if(argc==2){
		if(strcmp(argv[1],"-I")==0){ // date -I
			time_t c_time=time(NULL);
			struct tm tm= *localtime(&c_time);
			printf("%02d-%02d-%04d\n",tm.tm_mday, tm.tm_mon+1,tm.tm_year+1900);
		}
		else if(strcmp(argv[1],"-R")==0){ // date -R
			_date(2);

		}

		else{// date
			printf("date: cannot find --%s",argv[1]);
			return 0;
		}
	}
	else{
		_date2();
	}

	return 0;
}
