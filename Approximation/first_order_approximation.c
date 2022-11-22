#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	char fname1[128] = "frequency_appearance.txt";
	char fname2[128] = "approximation_txt.txt";


	//エラー
	fp1 = fopen(fname1, "r");
	if(fp1 == NULL){
		printf("%s file not open.\n", fname1);
		return -1;
	}

	//新規ファイル作成
	/*
	strcat(fname2, fname1);
	fp2 = fopen(fname2, "w");
	*/


	return 0;
}
