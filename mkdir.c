#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int l,char* args[]){
	if(!strcmp(args[l-1],"\0")) l--;
	if(l==1)printf("mkdir: missing operand\n");
	else if(args[1][0]=='-'&& args[1][1]=='m' && args[1][2]=='=' && strlen(args[1])==6){
		char cmode[3];
		cmode[0]=args[1][3];
		cmode[1]=args[1][4];
		cmode[2]=args[1][5];
		int check=atoi(cmode);
		if(check>777 || check<111) printf("mkdir: invalid mode ‘%d’\n",check);
		else{
			int mode=strtol(cmode,NULL,8);
			
			for(int i=2;i<l;i++){
				if(mkdir(args[i],mode)!=0){
					printf("mkdir: cannot create directory ‘%s’: File exists\n",args[i]);
				}
			}
		}	
		
	}
	else if(!strcmp(args[1],"-v")){
		for(int i=2;i<l;i++){
			if(mkdir(args[i],0777)!=0){
				printf("mkdir: cannot create directory ‘%s’: File exists\n",args[i]);
			}
			else printf("mkdir: created directory '%s'\n",args[i]);
		}	
	
	}
	else if(args[1][0]=='-') printf("rm: invalid option -- '%s'\n",args[1]);
	else{
		for(int i=1;i<l;i++){
			if(mkdir(args[i],0777)!=0){
				printf("mkdir: cannot create directory ‘%s’: File exists\n",args[i]);
			}
		}
	}
	return 0;
	
}
