// ex051.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


void intenn(int t[], int n)
{
	int s;
	for (s = 0; s <= n-1; s++)
	{
		printf_s("%d番の人の点数を入力して下さい\n", s+1);
		scanf_s("%d", &t[s]);
	}
}
int menu()
{
	int ba;
	printf_s("\n\nメニュー\n1. Maxを求め消す（同順処理付）\n2.自分より大きい値がいくつあるか\n3.総当たりで小さいほうにプラス\n4. WKソート、何番目か\n5.終了\n番号を入力してください\n");
	scanf_s("%d", &ba);
	while (1>ba && ba>5)
	{
		printf_s("入力エラーです。もう1度番号を入力してください\n");
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
	printf_s("方法1. Maxを求め消す\n");
	printf_s("点数:"   );
	hahyoji(a, n);
	printf_s("順位:"   );
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
	printf_s("方法2.大きいものをかぞえる\n");
	printf_s("点数:");
	hahyoji(a, n);
	printf_s("順位:");
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
	printf_s("方法3.総当たり\n");
	printf_s("点数:");
	hahyoji(a, n);
	printf_s("順位:");
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
	printf_s("方法4. WKソート\n");
	printf_s("点数:");
	hahyoji(a, n);
	printf_s("順位:");
	hahyoji(j, n);
}
void main()
{
	int mn, ba, t[30];
	printf_s("何人のクラスですか？人数を30人以下で入力してください\n");
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
