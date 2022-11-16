#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE * fp1 = NULL;
	FILE * fp2 = NULL;
	char fname1[16];
	char fname2[16] = "revise_";
	char ch;

	//ファイル名入力
	printf("input a file name\n");
	scanf("%s", fname1);

	//エラー
	fp1 = fopen(fname1, "r");
	if(fp1 == NULL){
		printf("%s file not open.\n", fname1);
		return -1;
	}

	//新規ファイル作成
	strcat(fname2, fname1);
	fp2 = fopen(fname2, "w");

	//記号置換
	while( (ch = fgetc(fp1)) != EOF ){
		if( (ch >= 0x21 && ch <= 0x40)
			|| (ch >= 0x5b && ch <= 0x60)
			|| (ch >= 0x7b && ch <= 0x7e)){
			fputc(0x20, fp2);
		}
		else fputc(ch, fp2);
		
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}
