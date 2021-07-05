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
	printf("Enter the string you want to decode: ");
	gets(cipher);
	printf("\nEnter the key: ");
	gets(key);
	char get[MAX];
	if(strlen(cipher)>strlen(key)){
		while(cipher[i]!='\0'){
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
	int length=strlen(cipher);
	while(cipher[i]!='\0'){
		if((int)(cipher[i])<65 || (int)(cipher[i])>123){
			plain[j]=(int)(cipher[i]);
			--t;	//for rest chars escape
		}
		else if((int)(cipher[i])>=65 && (int)(cipher[i])<=90){
			if((int)(cipher[i])-(int)(k[t])<=90){
				plain[j]=((int)(cipher[i])-((int)(k[t])));
			}
			if((int)(cipher[i])-(int)(k[t])<65){
				plain[j]=((int)(cipher[i])-((int)(k[t])))+26;
			}
		}
		else if((int)(cipher[i])>=97 && (int)(cipher[i])<=122){
			if((int)(cipher[i])-(int)(k[t])<=122){
				plain[j]=((int)(cipher[i])-((int)(k[t])));
			}
			if((int)(cipher[i])-(int)(k[t])<97){
				plain[j]=((int)(cipher[i])-((int)(k[t])))+26;
			}
		}
		i++;
		j++;
		t++;
		
	}
	cipher[j]='\0';
	printf("%s\n",cipher);
	printf("%s\n",plain);
	return 0;
}
