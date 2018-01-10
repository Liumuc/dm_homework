#include "iostream"
#include "string"
using namespace std;
#define MaxInt 100000
int i;

int stanum;//����վ����
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
}                                        //����ǲ��ǽڵ�

int Check(string *name, string nam, int n)
{
	int i = 0;
	while (i < n && name[i] != nam) {
		i++;
	}
	return i;
}

void print(int *pa, string *nam, int v, int i)//V��ʾ��Ŀ�ؽ��
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

	ks = dist[d];//����ֻ������Ҫ���Ǹ�Ŀ��ֵ
	return ks;
	delete dist;
}                             //Dijkstra�㷨����

int main()
{
	int n = 53;
	double Map[53 * 53];
	double *Ma = Map;//һά�����ʾ��ά���������
	for (int i = 0; i < n * n; i++)
		Map[i] = MaxInt;
	string name[53];
	string *nam = name;

	int path[53];
	int *pa = path;


	name[0] = "ƻ��԰";
	name[1] = "�ų�";
	name[2] = "�˽�����԰";
	name[3] = "�˱�ɽ";
	name[4] = "��Ȫ·";
	name[5] = "�����";
	name[6] = "����·";
	name[7] = "������";
	name[8] = "���²����";
	name[9] = "ľ�ص�";
	name[10] = "����ʿ·";
	name[11] = "������";
	name[12] = "����";
	name[13] = "�찲����";
	name[14] = "�찲�Ŷ�";
	name[15] = "������";
	name[16] = "����";
	name[17] = "������";
	name[18] = "������";
	name[19] = "��ó";
	name[20] = "����·";
	name[21] = "�Ļ�";
	name[22] = "�Ļݶ�";
	name[23] = "������";
	name[24] = "����ׯ";
	name[25] = "��ֱ��";
	name[26] = "��ˮ̶";
	name[27] = "��¥���";
	name[28] = "������";
	name[29] = "Ӻ�͹�";
	name[30] = "��ֱ��";
	name[31] = "����ʮ��";
	name[32] = "������";
	name[33] = "����վ";
	name[34] = "������";
	name[35] = "ǰ��";
	name[36] = "��ƽ��";
	name[37] = "������";
	name[38] = "������";
	name[39] = "������";
	name[40] = "֪��·";
	name[41] = "�����";
	name[42] = "�ϵ�";
	name[43] = "������";
	name[44] = "����";
	name[45] = "������";
	name[46] = "��Ӫ";
	name[47] = "��ˮ��";
	name[48] = "��Է";
	name[49] = "������";
	name[50] = "��ҩ��";
	name[51] = "������";
	name[52] = "����";

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
	Map[n * 22 + 21] = 1.4;//һ�������

	Map[n * 23 + 24] = 1.2;
	Map[n * 24 + 23] = 1.2;
	Map[n * 24 + 25] = 1.2;
	Map[n * 25 + 24] = 1.2;
	Map[n * 25 + 26] = 1.2;
	Map[n * 26 + 25] = 1.2;
	Map[n * 26 + 27] = 1.2;
	Map[n * 27 + 26] = 1.2;
	Map[n * 23 + 11] = 1.5;
	//������-������
	Map[n * 11 + 23] = 1.5;
	//������~������
	Map[n * 38 + 11] = 1.5;
	//������-������
	Map[n * 11 + 38] = 1.5;
	//������~������
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
	Map[n * 38 + 37] = 1.2;//���������

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

	Map[n * 17 + 32] = 1.9;//������~������
	Map[n * 32 + 17] = 1.9;//������~������
	Map[n * 17 + 33] = 1.9;//������~����վ
	Map[n * 33 + 17] = 1.9;//����վ~������
	Map[n * 52 + 30] = 1.9;//����~��ֱ��
	Map[n * 30 + 52] = 1.9;//��ֱ��~����
	Map[n * 25 + 39] = 1.9;//��ֱ��~������
	Map[n * 39 + 25] = 1.9;//������~��ֱ��

	Map[n * 47 + 48] = 2.6;
	Map[n * 48 + 47] = 2.6;
	Map[n * 48 + 49] = 2.6;
	Map[n * 49 + 48] = 2.6;
	Map[n * 49 + 50] = 2.6;
	Map[n * 50 + 49] = 2.6;
	Map[n * 50 + 51] = 2.6;
	Map[n * 51 + 50] = 2.6;
	Map[n * 51 + 52] = 2.6;
	Map[n * 52 + 51] = 2.6;//���������



	string start, dest;
	double race = 7.5;

	cout << "���������վ��:";
	cin >> start;
	cout << "�������յ�վ��:";
	cin >> dest;
	if (IsT(name, start, n)) {
		double distan = Dijkstra(Ma, pa, n, Check(nam, start, n), Check(nam, dest, n));//�ܲ���˽�㵽���������·��

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

		cout << "�����о���Ϊ:" << distan << "km" << endl;
		cout << ";����վ����Ϊ:" << stanum << endl;
		cout << "����ʱ��" << fen << "��" << miao << "��" << endl;
		cout << "��Ʊ��Ϊ:" << r << "Ԫ" << endl;

	}
	else {
		cout << endl;
		cout << "please choise your stations!" << '\n';
	}
	return 0;
}