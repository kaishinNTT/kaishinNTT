// ex051.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


void intenn(int t[], int n)
{
	int s;
	for (s = 0; s <= n-1; s++)
	{
		printf_s("%d�Ԃ̐l�̓_������͂��ĉ�����\n", s+1);
		scanf_s("%d", &t[s]);
	}
}
int menu()
{
	int ba;
	printf_s("\n\n���j���[\n1. Max�����ߏ����i���������t�j\n2.�������傫���l���������邩\n3.��������ŏ������ق��Ƀv���X\n4. WK�\�[�g�A���Ԗڂ�\n5.�I��\n�ԍ�����͂��Ă�������\n");
	scanf_s("%d", &ba);
	while (1>ba && ba>5)
	{
		printf_s("���̓G���[�ł��B����1�x�ԍ�����͂��Ă�������\n");
		scanf_s("%d", &ba);
	}
	return(ba);
}
void hahyoji(int c[], int n)
{
	int s;
	for (s = 0; s <= n - 1; s++)
	{
		printf_s("%4d", c[s]);
	}
	printf_s("\n");
}
void jun1max(int a[], int n)
{
	int w[30], j[30], s, k, max, maxs, homax, hok;
	for ( s = 0; s <= n-1; s++)
	{
		w[s] = a[s];
	}
	homax = -1;
	hok = -1;
	for ( k = 1; k <= n; k++)
	{
		max = w[0];
		maxs = 0;
		for ( s = 1; s <= n-1; s++)
		{
			if (max<w[s])
			{
				max = w[s];
				maxs = s;
			}
		}
		if (max!=homax)
		{
			j[maxs] = k;
			homax = max;
			hok = k;
		}
		else
		{
			j[maxs] = hok;
		}
		w[maxs] = -1;
	}
	printf_s("���@1. Max�����ߏ���\n");
	printf_s("�_��:"   );
	hahyoji(a, n);
	printf_s("����:"   );
	hahyoji(j, n);
}
void jun2ikutu(int a[], int n)
{
	int j[30], s, k, c;
	for ( s = 0; s <= n-1; s++)
	{
		c = 0;
		for ( k = 0; k <= n-1; k++)
		{
			if (a[s]<a[k])
			{
				c = c + 1;
			}
			j[s] = c + 1;
		}
		
	}
	printf_s("���@2.�傫�����̂���������\n");
	printf_s("�_��:");
	hahyoji(a, n);
	printf_s("����:");
	hahyoji(j, n);
}
void jun3souatari(int a[], int n)
{
	int j[30], s, k;
	for ( s = 0; s <= n-1; s++)
	{
		j[s] = 1;
	}
	for ( s = 0; s <= n-2; s++)
	{
		for ( k = s+1; k <= n-1; k++)
		{
			if (a[s]>a[k])
			{
				j[k] = j[k] + 1;
			}
			else
			{
				if (a[s]<a[k])
				{
					j[s] = j[s] + 1;
				}
			}

		}
	}
	printf_s("���@3.��������\n");
	printf_s("�_��:");
	hahyoji(a, n);
	printf_s("����:");
	hahyoji(j, n);
}
void jun4wksort(int a[], int n)
{
	int w[30], j[30], max, maxs, s, k;
	for ( s = 0; s <= n-1; s++)
	{
		w[s] = a[s];
	}
	for ( s = 0; s <= n-2; s++)
	{
		max = w[s];
		maxs = s;
		for ( k = s+1; k <= n-1; k++)
		{
			if (max < w[k])
			{
				max = w[k];
				maxs = k;
			}
		}
		w[maxs] = w[s];
		w[s] = max;
	}
	for ( s = 0; s <= n-1; s++)
	{
		k = 0;
		while (a[s]!=w[k])
		{
			k = k + 1;
		}
		j[s] = k + 1;
	}
	printf_s("���@4. WK�\�[�g\n");
	printf_s("�_��:");
	hahyoji(a, n);
	printf_s("����:");
	hahyoji(j, n);
}
void main()
{
	int mn, ba, t[30];
	printf_s("���l�̃N���X�ł����H�l����30�l�ȉ��œ��͂��Ă�������\n");
	scanf_s("%d", &mn);
	intenn(t, mn);
	do
	{
		ba = menu();
		switch (ba)
		{
		case 1:jun1max(t,mn);
			break;
		case 2:jun2ikutu(t, mn);
			break;
		case 3:jun3souatari(t, mn);
			break;
		case 4:jun4wksort(t, mn);
			break;
		default:
			break;
		}
	}while (ba != 5);
}
