#include <stdio.h>
#include <stdlib.h>

void teste1(int ** matriz){
	//alterar tamanho la na mais para 6
	matriz[0][1]=1;
	matriz[1][0]=1;
	matriz[1][4]=1;
	matriz[4][1]=1;
	matriz[4][5]=1;
	matriz[5][4]=1;
	matriz[0][2]=1;
	matriz[2][0]=1;
	matriz[2][5]=1;
	matriz[5][2]=1;
	matriz[2][3]=1;
	matriz[3][2]=1;
}

void teste2(int ** matriz){
	//alterar tamanho la na mais para 9
	matriz[0][1]=1;
	matriz[1][0]=1;
	matriz[1][5]=1;
	matriz[5][1]=1;
	matriz[0][4]=1;
	matriz[4][0]=1;
	matriz[4][7]=1;
	matriz[7][4]=1;
	
	matriz[7][6]=1;
	matriz[6][7]=1;
	
	matriz[7][8]=1;
	matriz[8][7]=1;
	matriz[1][7]=1;
	matriz[7][1]=1;
	matriz[8][3]=1;
	matriz[3][8]=1;
	matriz[1][2]=1;
	matriz[2][1]=1;

}
