#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<pthread.h>

void* thread_execution(void* a);
void* echo_thread(void* a);
void* pwd_thread(void* a);
void* cd_thread(void* a);
// ********************************** ECHO ************************************************************
void echo(char *args[], int l){

	if(l==1) printf("\n");
	else if(!strcmp(args[1],"--help") && l==2) printf("--help\n");
	else if(!strcmp(args[1],"-n")){
		for(int i=2;i<l;i++){
			
			for(int j=0;j<strlen(args[i]);j++){
				if(args[i][j]=='"')
					continue;
				if(args[i][j]=='\\')
					j++;
				printf("%c",args[i][j]);
			}
			printf(" ");
			
		}
	}
	else if(!strcmp(args[1],"-E")){
		for(int i=2;i<l;i++){
			
			for(int j=0;j<strlen(args[i]);j++){
				if(args[i][j]=='"')
					continue;
				if(args[i][j]=='\\')
					j++;
				printf("%c",args[i][j]);
			}
			printf(" ");
			
		}
		printf("\n");
	
	}
	
	else{
		for(int i=1;i<l;i++){
			
			for(int j=0;j<strlen(args[i]);j++){
				if(args[i][j]=='"')
					continue;
				if(args[i][j]=='\\')
					j++;
				printf("%c",args[i][j]);
			}
			printf(" ");
			
		}
		printf("\n");
		
	}
	
	
}

// *************************************** PWD **********************************************************
void pwd(char *args[],int l){
	if(l>2) printf("pwd: too many arguments\n");
	else if(l==1){
		char path[501];
		char *pwd=getcwd(path,501);
		printf("%s\n",pwd);
	}
	else if(!strcmp(args[1],"-P")){
		char path[501];
		char *pwd=getcwd(path,501);
		printf("%s\n",pwd);
	
	}
	else if(!strcmp(args[1],"-L")){
		char path[501];
		char *pwd=getcwd(path,501);
		printf("%s\n",pwd);
	}
	else if(args[1][0]=='-') printf("%s: Invalid Option\n",args[1]);
	else printf("%s: Invalid Option\n",args[1]);
}

// ************************************** CD ***************************************************************
void cd(char *args[],int l){
	if(l==1){
		chdir("/home/ankit");
	}
	else if(l>3) printf("cd: too many arguments\n");
	else if(!strcmp(args[1],"-P")){
		int t;
		if(l==2) t=chdir("/home/ankit");
		else t=chdir(args[2]);
		if(t!=0) printf("cd: %s: No such file or directory\n",args[1]);
	
	}
	else if(!strcmp(args[1],"-L")){
		int t;
		if(l==2) t=chdir("/home/ankit");
		else t=chdir(args[2]);
		if(t!=0) printf("cd: %s: No such file or directory\n",args[1]);
	}
	else if(args[1][0]=='-') printf("%s: Invalid Option\n",args[1]);
	else if(l==3) printf("cd: too many arguments\n");
	else{
	
		int t=chdir(args[1]);
		if(t!=0) printf("cd: %s: No such file or directory\n",args[1]);
		
	}
	char *temp[2]={"pwd","-L"};
	pwd(temp,1);
	
}
// ********************************** MAIN ***********************************************************
int main(){
	
	while(1){
		printf("ankit21014>> ");
		char cmd[200];
   		fgets(cmd, 200, stdin);
   
		if(strlen(cmd)==1)
			continue;
		
		cmd[strlen(cmd)-1]='\0';
		char cpy[200]="./";
		if(!strcmp("exit",cmd))
			break;
		int total_len=0;
		char *args[20];
		char *p=strtok(cmd," ");
		strcat(cpy,p);
		while(p!=NULL){
			args[total_len]=p;
			if(total_len && strcmp(p,"&t")!=0){
				strcat(cpy," ");
				strcat(cpy,p);
			}
				
			total_len++;
			p=strtok(NULL," ");
		}
			
		if(!strcmp(args[0],"cd")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,cd_thread,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else cd(args,total_len);
			
		}
		else if(!strcmp(args[0],"pwd")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,pwd_thread,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else pwd(args,total_len);
		}
		else if(!strcmp(args[0],"echo")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,echo_thread,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else echo(args,total_len);
			
		}
		else if(!strcmp(args[0],"ls")){
		
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,thread_execution,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else{
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				int e=execvp("./ls",args);
				if(e==-1) printf("Error: cannot execute the command\n");
				exit(1);
			}
			else{
				pid_t w=wait(NULL);
				continue;
			}
			}
			
		}
		else if(!strcmp(args[0],"date")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,thread_execution,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else{
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				int e=execvp("./date",args);
				if(e==-1) printf("Error: cannot execute the command\n");
				exit(1);
			}
			else{
				pid_t w=wait(NULL);
				
			}
			}		}
		else if(!strcmp(args[0],"rm")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,thread_execution,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else{
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				int e=execvp("./rm",args);
				if(e==-1) printf("Error: cannot execute the command\n");
				exit(1);
			}
			else{
				pid_t w=wait(NULL);
				
			}
			}		}
		else if(!strcmp(args[0],"cat")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,thread_execution,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else{
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				int e=execvp("./cat",args);
				if(e==-1) printf("Error: cannot execute the command\n");
				exit(1);
			}
			else{
				pid_t w=wait(NULL);
				
			}
			}		}
		else if(!strcmp(args[0],"mkdir")){
			if(!strcmp(args[total_len-1],"&t")){
				pthread_t th;
				if(pthread_create(&th,NULL,thread_execution,&cpy)!=0){
					printf("Error: cannot create tread\n");
				}
				else{
					pthread_join(th,NULL);
				}
				
			}
			else{
			pid_t i=fork();
			if(i==0){
				args[total_len]=NULL;
				int e=execvp("./mkdir",args);
				if(e==-1) printf("Error: cannot execute the command\n");
				exit(1);
			}
			else{
				pid_t w=wait(NULL);
				
			}
			}		
		}
		else printf("Command '%s' not found\n",args[0]);
		strcpy(cpy,"\0");
		
	}
	return 0;
}

void *thread_execution(void* arg){
	system((char*)arg);
	
}
void* cd_thread(void* a){
	char cmd[200];
	strcpy(cmd,(char*)a);
	int l=0;
		char *args[20];
		char *p=strtok(cmd," ");
		while(p!=NULL){
			args[l]=p;	
			l++;
			p=strtok(NULL," ");
		}
	
	cd(args,l);
}
void* echo_thread(void* a){
	char cmd[200];
	strcpy(cmd,(char*)a);
	int l=0;
		char *args[20];
		char *p=strtok(cmd," ");
		while(p!=NULL){
			args[l]=p;	
			l++;
			p=strtok(NULL," ");
		}
	
	echo(args,l);
}
void* pwd_thread(void* a){
	char cmd[200];
	strcpy(cmd,(char*)a);
	int l=0;
		char *args[20];
		char *p=strtok(cmd," ");
		while(p!=NULL){
			args[l]=p;	
			l++;
			p=strtok(NULL," ");
		}
	
	pwd(args,l);
}

