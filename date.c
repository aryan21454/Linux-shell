#include<stdio.h>
#include<string.h>
#include<time.h>
int main(int l,char* args[]){
	
	if(!strcmp(args[l-1],"\0")) l--;
	if(l==1){
		char *week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday"," Friday","Sunday"};
		char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December" };
		char ap[]="AM";
		char zone[10];
 		time_t rawtime;
  		struct tm* t;
  		int ch=time(&rawtime);
  		if(!ch){
  			perror("Error");
  			return 0;
  		}
  		t=localtime(&rawtime);
  		if(t==NULL){
   			perror("Error");
  			return 0; 		
  		}
  		printf("%s ",week[t->tm_wday]);
  		printf("%d ",t->tm_mday);
 	 	printf("%s ",months[t->tm_mon]);
		printf("%d ",t->tm_year+1900);
		int hr=t->tm_hour;
		if(hr>12){
			hr-=12;
			ap[0]='P';
		}
		if(hr>9) printf("%d:",hr);
		else printf("0%d:",hr);
		if(t->tm_min>9) printf("%d:",t->tm_min);
		else printf("0%d:",t->tm_min);
		if(t->tm_sec>9) printf("%d ",t->tm_sec);
		else printf("0%d ",t->tm_sec);
		strftime(zone, 10, "%z", t);
		printf("%s %s\n",ap,zone);
		}
	else if(!strcmp(args[1],"-u")&& l==2){
		char *week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday"," Friday","Sunday"};
		char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December" };
		char ap[]="AM";
		char zone[10];
 		time_t rawtime;
  		struct tm* t;
  		int ch=time(&rawtime);
  		if(!ch){
  			perror("Error");
  			return 0;
  		}
  		t=gmtime(&rawtime);
  		if(t==NULL){
   			perror("Error");
  			return 0; 		
  		}
  		printf("%s ",week[t->tm_wday]);
  		printf("%d ",t->tm_mday);
 	 	printf("%s ",months[t->tm_mon]);
		printf("%d ",t->tm_year+1900);
		int hr=t->tm_hour;
		if(hr>12){
			hr-=12;
			ap[0]='P';
		}
		if(hr>9) printf("%d:",hr);
		else printf("0%d:",hr);
		if(t->tm_min>9) printf("%d:",t->tm_min);
		else printf("0%d:",t->tm_min);
		if(t->tm_sec>9) printf("%d ",t->tm_sec);
		else printf("0%d ",t->tm_sec);
		printf("%s UTC\n",ap);
		
	
	}
	else if(!strcmp(args[1],"-R")&& l==2){
		char *week[]={"Sun","Mon","Tues","Wed","Thurs"," Fri","Sun"};
		char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		char zone[10];
		time_t rawtime;
  		struct tm* t;
  		int ch=time(&rawtime);
  		if(!ch){
  			perror("Error");
  			return 0;
  		}
  		t=localtime(&rawtime);
  		if(t==NULL){
   			perror("Error");
  			return 0; 		
  		}
  		printf("%s, ",week[t->tm_wday]);
  		printf("%d ",t->tm_mday);
 	 	printf("%s ",months[t->tm_mon]);
		printf("%d ",t->tm_year+1900);
		int hr=t->tm_hour;
		if(hr>9) printf("%d:",hr);
		else printf("0%d:",hr);
		if(t->tm_min>9) printf("%d:",t->tm_min);
		else printf("0%d:",t->tm_min);
		if(t->tm_sec>9) printf("%d ",t->tm_sec);
		else printf("0%d ",t->tm_sec);
		strftime(zone, 10, "%z", t);
		printf("%s \n",zone);
		}	
			
	
	
	
	else if(l==2){
		printf("date: invalid date ‘%s'\n",args[1]);
	}
	else printf("date: invalid date ‘%s'\n",args[2]);
	return 0;
}
