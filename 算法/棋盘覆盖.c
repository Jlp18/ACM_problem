#include <stdio.h>
int Board[100][100];
int tile = 0;
void ChessBoard(int tr , int tc , int dr , int dc , int size) //tr:�������Ͻǵ��к� tc:�������Ͻǵ��к� dr:��һ�����ǵ㣨����㣩���к�  dc:��һ�����ǵ㣨����㣩���к�  size:���̵Ŀ�� 
{
	if(size == 1)
	{
		return;
	}
	int t = tile++;  //L�͹��Ʊ�� 
	int s = size / 2;  //�ָ�����
	
	//�������Ͻǵ�������
	if(dr <tr + s && dc < tc + s)
	{
		//���⸲�ǵ��ڴ���������
		ChessBoard(tr , tc , dr , dc , s); 
	} 
	else
	{
		//���⸲�ǵ㲻�ڴ���������
		//��t�ŵ�L�͹��Ƹ������½�
		Board[tr+s-1][tc+s-1] = t; 
		//�ݹ鸲����������̷���
		ChessBoard(tr , tc , tr+s-1 , tc+s-1 , s);
	}
	
	//�������Ͻǵ�������
	if(dr < tr + s && dc >= tc + s)
	{
		//���⸲�ǵ��ڴ���������
		ChessBoard(tr , tc+s , dr , dc , s); 
	} 
	else
	{
		//���⸲�ǵ㲻�ڴ���������
		//��t�ŵ�L�͹��Ƹ������½�
		Board[tr+s-1][tc+s] = t;
		//�ݹ鸲����������̷���
		ChessBoard(tr , tc+s , tr+s-1 , tc+s , s);
	}
	
	//�������½ǵ�������
	if(dr >= tr + s && dc < tc + s)
	{
		//���⸲�ǵ��ڴ���������
		ChessBoard(tr+s , tc , dr ,dc , s);
	} 
	else
	{
		//���⸲�ǵ㲻�ڴ���������
		//��t�ŵ�L�͹��Ƹ������Ͻ�
		Board[tr+s][tc+s-1] = t;
		//�ݹ鸲����������̷���
		ChessBoard(tr+s , tc , tr+s , tc+s-1 , s); 
	}
	
	//�������½ǵ�������
	if(dr >= tr + s && dc >= tc + s)
	{
		//���⸲�ǵ��ڴ���������
		ChessBoard(tr+s , tc+s , dr , dc , s); 
	} 
	else
	{
		//���⸲�ǵ㲻�ڴ���������
		//��t�ŵ�L�͹��Ƹ������Ͻ�
		Board[tr+s][tc+s] = t; 
		//�ݹ鸲����������̷���
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
