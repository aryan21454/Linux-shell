#include<errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void cmdls(char* dir,char* mode){
	
	if(!strcmp(mode,"-1")){
    		struct dirent* d;
    		DIR *c=opendir(dir);
    		if(c==NULL) printf("ls: cannot access '%s': No such file or directory\n",dir);
    		else{
    			d=readdir(c);
    			while(d!=NULL){
    				if(d->d_name[0]!='.')
    					printf("%s   ",d->d_name);
    				d=readdir(c);
    			}
    			printf("\n");
    		}
    		closedir(c);	
	}
	if(!strcmp(mode,"-a")){
    		struct dirent* d;
    		DIR *c=opendir(dir);
    		if(c==NULL) printf("ls: cannot access '%s': No such file or directory\n",dir);
    		else{
    			d=readdir(c);
    			while(d!=NULL){	
    				printf("%s   ",d->d_name);
    				d=readdir(c);
    			}
    			printf("\n");
    		}
    		closedir(c);
	
	}
	if(!strcmp(mode,"-d")){
    		struct dirent* d;
    		DIR *c=opendir(dir);
    		if(c==NULL) printf("ls: cannot access '%s': No such file or directory\n",dir);
    		else{
    			d=readdir(c);
    			while(d!=NULL){
    				if(d->d_name[0]=='.'){
    					printf("%s   ",d->d_name);
    					break;
    				}
    				d=readdir(c);
    			}
    			printf("\n");
    		}
    		closedir(c);			
	
	}
}
int main(int l, char* args[])
{
	if(!strcmp(args[l-1],"\0")) l--;
	if(l==1){
    		
    		cmdls(".","-1");
    	}
    	else if(args[1][0]!='-'){
    		if(l==2) cmdls(args[1],"-1");
    		else{
    			for(int i=1;i<l;i++){
    				
    				printf("%s: \n",args[i]);
    				cmdls(args[i],"-1");
    			}
    		}
    	}
    	else if(!strcmp(args[1],"-a")){
    		if(l==2) cmdls(".","-a");
    		else if(l==3) cmdls(args[2],"-a");
    		else{
    		for(int i=2;i<l;i++){
    			printf("%s: \n",args[i]);
    			cmdls(args[i],"-a");
    		}
    		}  		
    	}
    	else if(!strcmp(args[1],"-d")){
    		if(l==2) cmdls(".","-d");
    		else if(l==3) cmdls(args[2],"-d");
    		else{
    		for(int i=2;i<l;i++){
    			printf("%s: \n",args[i]);
    			cmdls(args[i],"-d");
    		}
    		}      	
    	}
    	else {
    		printf("ls: invalid option -- '%s'\n",args[1]);
    	}
    	return 0;
   
}
