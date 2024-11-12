#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Node
{
	int row;
	int col;
	int brow;
	int bcol;
	int Count;
};

char arr[10][10];
bool visit[10][10][10][10];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void move(int& rx, int& ry, int& distance, int& i)
{
	while (arr[rx + dx[i]][ry + dy[i]] != '#' && arr[rx][ry] != 'O')
	{
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int a1, a2, a3, a4;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				a1 = i;
				a2 = j;
			}
			if (arr[i][j] == 'B') {
				a3 = i;
				a4 = j;
			}
		}
	}
	queue<Node> q;
	q.push({ a1,a2,a3,a4,0 });
	visit[a1][a2][a3][a4] = true;
	while (!q.empty())
	{
		int rx = q.front().row;
		int ry = q.front().col;
		int bx = q.front().brow;
		int by = q.front().bcol;
		int count = q.front().Count;
		q.pop();

		if (count >= 10) break;

		for (int i = 0; i < 4; i++)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncount = count + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (arr[nbx][nby] == 'O') continue;
			if (arr[nrx][nry] == 'O')
			{
				cout << ncount;
				return 0;
			}

			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}

			if (visit[nrx][nry][nbx][nby]) continue;
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount });
		}
	}
	cout << -1;

	return 0;
}