#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int l,char* args[]){
	if(!strcmp(args[l-1],"\0")) l--;
	if(l==1)printf("mkdir: missing operand\n");
	else if(!strcmp(args[1],"-E")){
		for(int i=2;i<l;i++){
			FILE* fptr;
    			char ch;
    			fptr = fopen(args[i], "r");
 
    			if (fptr==NULL) {
        			printf("file '%s' does not exist \n",args[i]);
        			continue;
    			}
 
    			ch=fgetc(fptr);
 			while (ch != EOF){
 				if(ch=='\n') {
        				printf("$");
        			}
			        printf("%c", ch);
			        ch = fgetc(fptr);
 			}
			fclose(fptr);
		}	
			
	
	}
	else if(!strcmp(args[1],"-n")){
		int line=1;
		char prev='\n';
		for(int i=2;i<l;i++){
			FILE* fptr;
    			char ch;
    			
    			fptr = fopen(args[i], "r");
 
    			if (fptr==NULL) {
        			printf("file '%s' does not exist \n",args[i]);
        			continue;
    			}
    			ch=fgetc(fptr);
 			while (ch != EOF){
 				if(prev=='\n') {
        				printf("     %d  ",line);
        				line++;
        			}
			        printf("%c", ch);
			        prev=ch;
			        ch = fgetc(fptr);
 			}
			fclose(fptr);
		}
	
	}
	else if(args[1][0]=='-') printf("rm: invalid option -- '%c'\n",args[1][0]);
	else{
		for(int i=1;i<l;i++){
			FILE* fptr;
    			char ch;
    			fptr = fopen(args[i], "r");
 
    			if (fptr==NULL) {
        			printf("file '%s' does not exist \n",args[i]);
        			continue;
    			}
 
    			ch=fgetc(fptr);
 			while (ch != EOF){
 				
			        printf("%c", ch);
			        ch = fgetc(fptr);
 			}
		    	fclose(fptr);
		}
	}
	return 0;
}
