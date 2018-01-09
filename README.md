# dm_homework
离散数学大作业-北京地铁站最短路径规划
### 作业要求
以1号线、2号线和13号线为例，求任意两站之间的最短路线，并显示所需时间，路过的站点数，票价。
### 代码
```
#include "iostream"
#include "string"
using namespace std;
#define MaxInt 100000
int i;

int stanum;//所经站点数
static bool IsT(string *name, string nam, int n)
{
	int i = 0;
	while (i < n) {
		if (name[i] == nam) {
			return true;
		}
		i++;
	}
	return false;
}                                        //检查是不是节点

int Check(string *name, string nam, int n)
{
	int i = 0;
	while (i < n && name[i] != nam) {
		i++;
	}
	return i;
}

void print(int *pa, string *nam, int v, int i)//V表示是目地结点
{
	if (pa[i] >= 0) {
		print(pa, nam, v, pa[i]);
		cout << endl;
		cout << stanum << " " << nam[pa[i]];
		stanum = stanum + 1;
	}
}

float Dijkstra(double *Map, int *path, int n, int v, int d)
{
	float min, ks;
	int u, t;
	float *dist = new float[n];
	int *s = new int[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = Map[n * v + i];
		s[i] = 0;
		if (i != v && dist[i] < MaxInt) {
			path[i] = v;
		}
		else
			path[i] = -1;
	}
	s[v] = 1;
	for (i = 0; i < n - 1; i++)
	{
		min = MaxInt;
		u = v;
		for (int j = 0; j < n; j++)
		{
			if (!s[j] && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		s[u] = 1;
		for (t = 0; t < n; t++)
		{
			if (!s[t] && dist[u] + Map[n * u + t] < dist[t]) {
				dist[t] = dist[u] + Map[n * u + t];
				path[t] = u;
			}
		}
	}

	ks = dist[d];//现在只返回人要的那个目的值
	return ks;
	delete dist;
}                             //Dijkstra算法内容

int main()
{
	int n = 53;
	double Map[53 * 53];
	double *Ma = Map;//一维数组表示二维数组的内容
	for (int i = 0; i < n * n; i++)
		Map[i] = MaxInt;
	string name[53];
	string *nam = name;

	int path[53];
	int *pa = path;


	name[0] = "苹果园";
	name[1] = "古城";
	name[2] = "八角游乐园";
	name[3] = "八宝山";
	name[4] = "玉泉路";
	name[5] = "五棵松";
	name[6] = "万寿路";
	name[7] = "公主坟";
	name[8] = "军事博物馆";
	name[9] = "木樨地";
	name[10] = "南礼士路";
	name[11] = "复兴门";
	name[12] = "西单";
	name[13] = "天安门西";
	name[14] = "天安门东";
	name[15] = "王府井";
	name[16] = "东单";
	name[17] = "建国门";
	name[18] = "永安里";
	name[19] = "国贸";
	name[20] = "大望路";
	name[21] = "四惠";
	name[22] = "四惠东";
	name[23] = "阜成门";
	name[24] = "车公庄";
	name[25] = "西直门";
	name[26] = "积水潭";
	name[27] = "鼓楼大街";
	name[28] = "安定门";
	name[29] = "雍和宫";
	name[30] = "东直门";
	name[31] = "东四十条";
	name[32] = "朝阳门";
	name[33] = "北京站";
	name[34] = "崇文门";
	name[35] = "前门";
	name[36] = "和平门";
	name[37] = "宣武门";
	name[38] = "长椿街";
	name[39] = "大钟寺";
	name[40] = "知春路";
	name[41] = "五道口";
	name[42] = "上地";
	name[43] = "西二旗";
	name[44] = "龙泽";
	name[45] = "回龙观";
	name[46] = "霍营";
	name[47] = "立水桥";
	name[48] = "北苑";
	name[49] = "望京东";
	name[50] = "芍药居";
	name[51] = "光熙门";
	name[52] = "柳芳";

	for (i = 0; i < n; i++)
	Map[n * i + i] = 0;
	Map[n * 0 + 1] = 1.4;
	Map[n * 1 + 0] = 1.4;
	Map[n * 1 + 2] = 1.4;
	Map[n * 2 + 1] = 1.4;
	Map[n * 2 + 3] = 1.4;
	Map[n * 3 + 2] = 1.4;
	Map[n * 3 + 4] = 1.4;
	Map[n * 4 + 3] = 1.4;
	Map[n * 4 + 5] = 1.4;
	Map[n * 5 + 4] = 1.4;
	Map[n * 5 + 6] = 1.4;
	Map[n * 6 + 5] = 1.4;
	Map[n * 6 + 7] = 1.4;
	Map[n * 7 + 6] = 1.4;
	Map[n * 7 + 8] = 1.4;
	Map[n * 8 + 7] = 1.4;
	Map[n * 8 + 9] = 1.4;
	Map[n * 9 + 8] = 1.4;
	Map[n * 9 + 10] = 1.4;
	Map[n * 10 + 9] = 1.4;
	Map[n * 10 + 11] = 1.4;
	Map[n * 11 + 10] = 1.4;
	Map[n * 11 + 12] = 1.4;
	Map[n * 12 + 11] = 1.4;
	Map[n * 12 + 13] = 1.4;
	Map[n * 13 + 12] = 1.4;
	Map[n * 13 + 14] = 1.4;
	Map[n * 14 + 13] = 1.4;
	Map[n * 14 + 15] = 1.4;
	Map[n * 15 + 14] = 1.4;
	Map[n * 15 + 16] = 1.4;
	Map[n * 16 + 15] = 1.4;
	Map[n * 16 + 17] = 1.4;
	Map[n * 17 + 16] = 1.4;
	Map[n * 17 + 18] = 1.4;
	Map[n * 18 + 17] = 1.4;
	Map[n * 18 + 19] = 1.4;
	Map[n * 19 + 18] = 1.4;
	Map[n * 19 + 20] = 1.4;
	Map[n * 20 + 19] = 1.4;
	Map[n * 20 + 21] = 1.4;
	Map[n * 21 + 20] = 1.4;
	Map[n * 21 + 22] = 1.4;
	Map[n * 22 + 21] = 1.4;//一号线完毕
	
	Map[n * 23 + 24] = 1.2;
	Map[n * 24 + 23] = 1.2;
	Map[n * 24 + 25] = 1.2;
	Map[n * 25 + 24] = 1.2;
	Map[n * 25 + 26] = 1.2;
	Map[n * 26 + 25] = 1.2;
	Map[n * 26 + 27] = 1.2;
	Map[n * 27 + 26] = 1.2;
	Map[n * 23 + 11] = 1.5;
  //阜成门-复兴门
	Map[n * 11 + 23] = 1.5;
  //复兴门~阜成门
	Map[n * 38 + 11] = 1.5;
  //长椿街-复兴门
	Map[n * 11 + 38] = 1.5;
  //复兴门~长椿街
	Map[n * 27 + 28] = 1.2;
	Map[n * 28 + 27] = 1.2;
	Map[n * 28 + 29] = 1.2;
	Map[n * 29 + 28] = 1.2;
	Map[n * 29 + 30] = 1.2;
	Map[n * 30 + 29] = 1.2;
	Map[n * 30 + 31] = 1.2;
	Map[n * 31 + 30] = 1.2;
	Map[n * 31 + 32] = 1.2;
	//Map[n * 32 + 31] = ;
	//Map[n * 32 + 33] = ;
	Map[n * 33 + 32] = 1.2;
	Map[n * 33 + 34] = 1.2;
	Map[n * 34 + 33] = 1.2;
	Map[n * 34 + 35] = 1.2;
	Map[n * 35 + 34] = 1.2;
	Map[n * 35 + 36] = 1.2;
	Map[n * 36 + 35] = 1.2;
	Map[n * 36 + 37] = 1.2;
	Map[n * 37 + 36] = 1.2;
	Map[n * 37 + 38] = 1.2;
	Map[n * 38 + 37] = 1.2;//二号线完毕
	
	Map[n * 39 + 40] = 2.6;
	Map[n * 40 + 39] = 2.6;
	Map[n * 40 + 41] = 2.6;
	Map[n * 41 + 40] = 2.6;
	Map[n * 41 + 42] = 2.6;
	Map[n * 42 + 41] = 2.6;
	Map[n * 42 + 43] = 2.6;
	Map[n * 43 + 42] = 2.6;
	Map[n * 43 + 44] = 2.6;
	Map[n * 44 + 43] = 2.6;
	Map[n * 44 + 45] = 2.6;
	Map[n * 45 + 44] = 2.6;
	Map[n * 45 + 46] = 2.6;
	Map[n * 46 + 45] = 2.6;
	Map[n * 46 + 47] = 2.6;
	Map[n * 47 + 46] = 2.6;

	Map[n * 17 + 32] = 1.9;//建国门~朝阳门
	Map[n * 32 + 17] = 1.9;//朝阳门~建国门
	Map[n * 17 + 33] = 1.9;//建国门~北京站
	Map[n * 33 + 17] = 1.9;//北京站~建国门
	Map[n * 52 + 30] = 1.9;//柳芳~东直门
	Map[n * 30 + 52] = 1.9;//东直门~柳芳
	Map[n * 25 + 39] = 1.9;//西直门~大钟寺
	Map[n * 39 + 25] = 1.9;//大钟寺~西直门

	Map[n * 47 + 48] = 2.6;
	Map[n * 48 + 47] = 2.6;
	Map[n * 48 + 49] = 2.6;
	Map[n * 49 + 48] = 2.6;
	Map[n * 49 + 50] = 2.6;
	Map[n * 50 + 49] = 2.6;
	Map[n * 50 + 51] = 2.6;
	Map[n * 51 + 50] = 2.6;
	Map[n * 51 + 52] = 2.6;
	Map[n * 52 + 51] = 2.6;//三号线完毕



	string start, dest;
	double race = 7.5;

	cout << "请输入起点站名:";
	cin >> start;
	cout << "请输入终点站名:";
	cin >> dest;
	if (IsT(name, start, n)) {
		double distan = Dijkstra(Ma, pa, n, Check(nam, start, n), Check(nam, dest, n));//能查出此结点到其他点最短路径

		int s, d;
		s = Check(nam, start, n);
		d = Check(nam, dest, n);
		stanum = 0;
		print(pa, nam, s, d);
		cout << endl;
		cout << stanum << " " << dest << '\n';
		int fen = distan * 1000 / race / 60;
		int miao = (int(distan * 1000 / race)) % 60;
		int r;
		if (distan>6)
		{
			if (distan>12)
			{
				if (distan>32)
				{
					r = 6 + distan / 20;
				}
				else
					r = 4 + distan / 10;
			}
			else
				r = 4;
		}
		else
			r = 3;

		cout << "总运行距离为:" << distan << "km" << endl;
		cout << "途径总站点数为:" << stanum << endl;
		cout << "运行时间" << fen << "分" << miao << "秒" << endl;
		cout << "总票价为:" << r << "元" << endl;

	}
	else {
		cout << endl;
		cout << "please choise your stations!" << '\n';
	}
	return 0;
}

```
