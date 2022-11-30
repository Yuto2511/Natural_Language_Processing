#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	char fname1[64] = "fairy_tales.txt";
	char fname2[64] = "3_approximation_txt.txt";

	int ch;
	int *alphabet;
	int max = 0, i = 0, k, a, b;

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

	k = 0 + (int)( rand() * (max + 1.0) / (1.0 + RAND_MAX) );
	fprintf(fp2, "%c%c", alphabet[k], alphabet[k+1]);
	a = k + 1;
	b = k + 2;
	for(int j = 0; j < 100; j++){
		k = 0 + (int)( rand() * (max + 1.0) / (1.0 + RAND_MAX) );
		while(1){
			k++;
			if(alphabet[k] == alphabet[a]){
				a = k + 1;
				break;
			}
		}
		while(1){
			a++;
			if(alphabet[a] == alphabet[b]){
				b = a + 1;
				break;
			}

		}
		fprintf(fp2, "%c", alphabet[b]);
	}

	free(alphabet);

	return 0;
}
