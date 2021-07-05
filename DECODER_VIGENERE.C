#include<stdio.h>
#include<string.h>
#define MAX 200
int main(){
	char plain[MAX];
	int i=0,j=0,t=0,rem;
	char cipher[MAX];
	char key[MAX];
	char k[MAX];
	printf("Enter the string you want to decode: ");		
	gets(cipher);											//input string cipher
	printf("\nEnter the key: ");
	gets(key);												//input key
	char get[MAX];
	if(strlen(cipher)>strlen(key)){							//membandingkan cipher dan key 
		while(cipher[i]!='\0'){								//yang panjang text melebihi key
			get[t]=key[i%strlen(key)];
			i++;
			t++;
		}
	}
	t=0;i=0;
	if(strlen(cipher)<=strlen(key)){						//membandingkan cipher dan key
		get[t]=key[i];										//panjang text kurang dari key
	}
	i=0;t=0;
	while(key[t]!='\0'){									//jika string bukan huruf/simbol ASCII 65-123
		if((int)(key[t])<65 || (int)(key[t])>123){
			printf("Invalid String");
			return 1;
		}
		t++;
	}
	i=0;t=0;
	while(get[t]!='\0'){
	
		if((int)(get[t])>=65 && (int)(get[t])<=90){			//Menghitung key untuk huruf Kapital
			k[i]=get[t]-65;
		}
		else if((int)(get[t])>=97 && (int)(get[t])<=122){	//Menghitung key untuk huruf non kapital
			k[i]=get[t]-97;
		}
		t++;
		i++;
	}
	t=0;i=0;
	int length=strlen(cipher);
	while(cipher[i]!='\0'){
		if((int)(cipher[i])<65 || (int)(cipher[i])>123){	//Jika bukan alfabet maka akan di skip dekripsinya
			plain[j]=(int)(cipher[i]);
			--t;
		}
		else if((int)(cipher[i])>=65 && (int)(cipher[i])<=90){      //dekripsi huruf kapital
			if((int)(cipher[i])-(int)(k[t])<=90){					//dekripsi huruf sampai Z
				plain[j]=((int)(cipher[i])-((int)(k[t])));
			}
			if((int)(cipher[i])-(int)(k[t])<65){					//dekripsi huruf melebihi Z
				plain[j]=((int)(cipher[i])-((int)(k[t])))+26;
			}
		}
		else if((int)(cipher[i])>=97 && (int)(cipher[i])<=122){		//dekripsi huruf non kapital
			if((int)(cipher[i])-(int)(k[t])<=122){					//dekripsi huruf sampai z
				plain[j]=((int)(cipher[i])-((int)(k[t])));
			}
			if((int)(cipher[i])-(int)(k[t])<97){					//dekripsi huruf melebihi Z
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
