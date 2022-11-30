#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE * fp1;
	FILE * fp2;
	char fname1[128];
	char fname2[] = "frequency_appearance.txt";
	char ch;

	char hex;
	int alphabet[27][27];
	int sort[28][2];
	int buf1, buf2, buf;

	//ファイル名入力
	printf("input a file name\n");
	scanf("%s", fname1);

	//エラー
	fp1 = fopen(fname1, "r");
	if(fp1 == NULL){
		printf("%s file not found.\n", fname1);
		return -1;
	}

	//新規ファイル作成
	fp2 = fopen(fname2, "w");


	//文字頻度
	/*
	while( (ch = fgetc(fp1)) != EOF ){
		for(int i = 0x41; i <= 0x5A; i+=0x01 ){
			if( ch == i || ch == i+0x20 ){
				alphabet[i-0x41] += 1;
			}
		}
		if( ch == 0x0A ) alphabet[27] += 1;
		else if( ch == 0x20 ) alphabet[26] += 1;
	}
	*/

	while( (ch = fgetc(fp1)) != EOF ){
		for( int i = 0x41; i <= 0x5A; i+=0x01 ){
			if( ch == i || ch == +0x20 ){
				alphabet[buf-0x41][i-0x41] += 1;
			}
			else if( ch == 0x20 ) alphabet[buf-0x41][26] += 1;
		}
		buf = ch;

	}

	//ソート
	for(int i = 0; i <= 28; i++){
		sort[i][0] = i;
		sort[i][1] = alphabet[i];
	}
	for(int i = 0; i <= 27; i++ ){
		for(int j = i+1; j <= 27; j++ ){
			if(sort[i][1] < sort[j][1]){
				buf1 = sort[i][0];
				sort[i][0] = sort[j][0];
				sort[j][0] = buf1;
				buf2 = sort[i][1];
				sort[i][1] = sort[j][1];
				sort[j][1] = buf2;
			}
		}
	}

	//ソート結果
	for(int i = 0x00; i <= 0x1B; i+=0x01){
		if(sort[i][0] == 26) fprintf(fp2, "%d [ ] -> %d\n", i+1, sort[i][1]);
		else if(sort[i][0] == 27) fprintf(fp2, "%d [\] -> %d\n", i+1, sort[i][1]);
		else fprintf(fp2, "%d [%c] -> %d\n", i+1, sort[i][0]+0x41, sort[i][1]);
	}


	return 0;

}
