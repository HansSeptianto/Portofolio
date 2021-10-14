#include <stdio.h>
#include <string.h>
int main(){
	char kata;
	char arr[100];
	scanf("%s", &kata);getchar();
	for(int i=0;i<strlen(kata);i++){
		for(int j=0;strlen(kata);j++){
			arr[j] = kata[j];
			if(kata[i] != kata[j]){
				arr[j] = kata[j];
			}
		}
	}
	return 0;
}
