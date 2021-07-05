#include<stdio.h>
#include<string.h>
#define MAX 200

int main(){
	char plain[MAX];
	int i=0,j=0,t=0,rem;
	char cipher[MAX];
	char key[MAX];
	char k[MAX];
	printf("Enter the string you want to encode: ");
	gets(plain);   												//mengambil input string
	printf("\nEnter the key: ");
	gets(key);     												//mengambil input key
	char get[MAX];
	if(strlen(plain)>strlen(key)){   							//membandingkan key dengan plaintext
		while(plain[i]!='\0'){									//yang panjang text melebihi key
			get[t]=key[i%strlen(key)];
			i++;
			t++;
		}
	}
	t=0;i=0;
	if(strlen(cipher)<=strlen(key)){							//membandingkan cipher dan key
		get[t]=key[i];											//panjang text kurang dari key
	}
	i=0;t=0;
	while(key[t]!='\0'){										//jika string bukan huruf/simbol ASCII 65-123
		if((int)(key[t])<65 || (int)(key[t])>123){
			printf("Invalid String");
			return 1;
		}
		t++;
	}
	i=0;t=0;
	while(get[t]!='\0'){
	
		if((int)(get[t])>=65 && (int)(get[t])<=90){				//Menghitung key untuk huruf Kapital
			k[i]=get[t]-65;
		}
		else if((int)(get[t])>=97 && (int)(get[t])<=122){		//Menghitung key untuk huruf non kapital
			k[i]=get[t]-97;
		}
		t++;
		i++;
	}
	t=0;i=0;
	int length=strlen(plain);
	while(plain[i]!='\0'){										//Jika bukan alfabet maka akan di skip enkripsinya
		if((int)(plain[i])<65 || (int)(plain[i])>123){
			cipher[j]=(int)(plain[i]);
			--t;	//for rest chars escape
		}
		else if((int)(plain[i])>=65 && (int)(plain[i])<=90){	//enkripsi huruf kapital
			if((int)(plain[i])+(int)(k[t])<=90){				//enkripsi huruf sampai Z
				cipher[j]=((int)(plain[i])+((int)(k[t])));
			}
			if((int)(plain[i])+(int)(k[t])>90){					//enkripsi huruf melebihi Z
				cipher[j]=((int)(plain[i])+((int)(k[t])))-26;
			}
		}
		else if((int)(plain[i])>=97 && (int)(plain[i])<=122){	//enkripsi huruf non kapital
			if((int)(plain[i])+(int)(k[t])<=122){				//enkripsi huruf sampai Z
				cipher[j]=((int)(plain[i])+((int)(k[t])));
			}
			if((int)(plain[i])+(int)(k[t])>122){				//enkripsi huruf melebihi Z
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
