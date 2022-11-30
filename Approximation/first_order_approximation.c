#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	char fname1[64] = "fairy_tales.txt";
	char fname2[64] = "approximation_txt.txt";

	int ch;
	int *alphabet;
	int max = 0, i = 0, k;

	//printf("input a file name\n");
	//scanf("%s", fname1);

	//エラー
	fp1 = fopen(fname1, "r");
	if(fp1 == NULL){
		printf("%s file not open.\n", fname1);
		return -1;
	}


	while( fgetc(fp1) != EOF ) max++;
	alphabet = (int*)malloc(sizeof(int) * max);

	fp1 = fopen(fname1, "r");
	while( (ch = fgetc(fp1)) != EOF ){
		alphabet[i] = ch;
		i++;
	}


	//新規ファイル作成
	fp2 = fopen(fname2, "w");

	srand((unsigned int)time(NULL));

	for(int j = 0; j < 200; j++){
		k = 0 + (int)( rand() * (max + 1.0) / (1.0 + RAND_MAX) );
		fprintf(fp2, "%c", alphabet[k]);
	}

	free(alphabet);

	return 0;
}
