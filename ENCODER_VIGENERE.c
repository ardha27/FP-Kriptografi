#include<stdio.h>
#include<string.h>
#define MAX 200

int main(){
	char plain[MAX];
	int i=0,j=0,t=0,rem;
	char cipher[MAX];
	char key[MAX];
	char k[MAX];
//	CHAR k[MAX];
	printf("Enter the string you want to encode: ");
	gets(plain);
	printf("\nEnter the key: ");
	gets(key);
	char get[MAX];
	if(strlen(plain)>strlen(key)){
		while(plain[i]!='\0'){
			get[t]=key[i%strlen(key)];
//			printf("%c ",get[t]);
			i++;
			t++;
		}
	}
	t=0;i=0;
	if(strlen(cipher)<=strlen(key)){
		get[t]=key[i];
	}
	i=0;t=0;
	while(key[t]!='\0'){
		if((int)(key[t])<65 || (int)(key[t])>123){
			printf("Invalid String");
			return 1;
		}
		t++;
	}
	i=0;t=0;
	while(get[t]!='\0'){
	
		if((int)(get[t])>=65 && (int)(get[t])<=90){
			k[i]=get[t]-65;
		}
		else if((int)(get[t])>=97 && (int)(get[t])<=122){
			k[i]=get[t]-97;
		}
		t++;
		i++;
	}
//	}
	t=0;i=0;
//	rem=k%26;
	int length=strlen(plain);
	while(plain[i]!='\0'){
		if((int)(plain[i])<65 || (int)(plain[i])>123){
			cipher[j]=(int)(plain[i]);
			--t;	//for rest chars escape
		}
		else if((int)(plain[i])>=65 && (int)(plain[i])<=90){
			if((int)(plain[i])+(int)(k[t])<=90){
				cipher[j]=((int)(plain[i])+((int)(k[t])));
			}
			if((int)(plain[i])+(int)(k[t])>90){
				cipher[j]=((int)(plain[i])+((int)(k[t])))-26;
			}
		}
		else if((int)(plain[i])>=97 && (int)(plain[i])<=122){
			if((int)(plain[i])+(int)(k[t])<=122){
				cipher[j]=((int)(plain[i])+((int)(k[t])));
			}
			if((int)(plain[i])+(int)(k[t])>122){
				cipher[j]=((int)(plain[i])+((int)(k[t])))-26;
			}
		}
		i++;
		j++;
		t++;
		
	}
	cipher[j]='\0';
	printf("%s\n",plain);
	printf("%s\n",cipher);
	
	return 0;
}
