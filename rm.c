#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int l,char* args[]){
	if(!strcmp(args[l-1],"\0")) l--;
	if(l==1)printf("rm: missing operand\n");
	else if(!strcmp(args[1],"-i")){
		for(int i=2;i<l;i++){
			printf("rm: remove regular empty file '%s'? ",args[i]);	
			char ch;
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y'){
				if(remove(args[i])!=0){
					printf("rm: cannot remove '%s': No such file or directory\n",args[i]);
				}
								
			}
			else continue;
		
		}
	
	}
	else if(!strcmp(args[1],"-v")){
		for(int i=2;i<l;i++){
			if(remove(args[i])!=0){
				printf("rm: cannot remove '%s': No such file or directory\n",args[i]);
			}
			else printf("removed '%s'\n",args[i]);
		}	
	
	}
	else if(args[1][0]=='-') printf("rm: invalid option -- '%c'\n",args[1][0]);
	else{
		for(int i=1;i<l;i++){
			if(remove(args[i])!=0){
				printf("rm: cannot remove '%s': No such file or directory\n",args[i]);
			}
		}
	}
	return 0;
}
