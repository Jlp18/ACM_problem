#include <stdio.h>
int Board[100][100];
int tile = 0;
void ChessBoard(int tr , int tc , int dr , int dc , int size) //tr:棋盘左上角的行号 tc:棋盘左上角的列号 dr:第一个覆盖点（特殊点）的行号  dc:第一个覆盖点（特殊点）的列号  size:棋盘的宽度 
{
	if(size == 1)
	{
		return;
	}
	int t = tile++;  //L型骨牌编号 
	int s = size / 2;  //分割棋盘
	
	//覆盖左上角的子棋盘
	if(dr <tr + s && dc < tc + s)
	{
		//特殊覆盖点在此子棋盘中
		ChessBoard(tr , tc , dr , dc , s); 
	} 
	else
	{
		//特殊覆盖点不在此子棋盘中
		//用t号的L型骨牌覆盖右下角
		Board[tr+s-1][tc+s-1] = t; 
		//递归覆盖其余的棋盘方格
		ChessBoard(tr , tc , tr+s-1 , tc+s-1 , s);
	}
	
	//覆盖右上角的子棋盘
	if(dr < tr + s && dc >= tc + s)
	{
		//特殊覆盖点在此子棋盘中
		ChessBoard(tr , tc+s , dr , dc , s); 
	} 
	else
	{
		//特殊覆盖点不在此子棋盘中
		//用t号的L型骨牌覆盖左下角
		Board[tr+s-1][tc+s] = t;
		//递归覆盖其余的棋盘方格
		ChessBoard(tr , tc+s , tr+s-1 , tc+s , s);
	}
	
	//覆盖左下角的子棋盘
	if(dr >= tr + s && dc < tc + s)
	{
		//特殊覆盖点在此子棋盘中
		ChessBoard(tr+s , tc , dr ,dc , s);
	} 
	else
	{
		//特殊覆盖点不在此子棋盘中
		//用t号的L型骨牌覆盖右上角
		Board[tr+s][tc+s-1] = t;
		//递归覆盖其余的棋盘方格
		ChessBoard(tr+s , tc , tr+s , tc+s-1 , s); 
	}
	
	//覆盖右下角的子棋盘
	if(dr >= tr + s && dc >= tc + s)
	{
		//特殊覆盖点在此子棋盘中
		ChessBoard(tr+s , tc+s , dr , dc , s); 
	} 
	else
	{
		//特殊覆盖点不在此子棋盘中
		//用t号的L型骨牌覆盖左上角
		Board[tr+s][tc+s] = t; 
		//递归覆盖其余的棋盘方格
		ChessBoard(tr+s , tc+s , tr+s , tc+s , s); 
	}
}
int main()
{
	ChessBoard(0 , 0 , 0 , 1 , 4);
	int i , j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			printf("%d\t",Board[i][j]);
		}
		printf("\n");
	}
	return 0;
}
