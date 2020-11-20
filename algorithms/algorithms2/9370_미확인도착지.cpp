#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include <climits>
using namespace std;

const int INF = 1000000007; //#define쓰면 바꾸라 나온다

struct line_info
{
	int now;
	int value;
};

bool operator < (line_info t, line_info u)
{
	return t.value > u.value;
}

int T; //테스트케이스
int n, m, t; //교차로, 도로, 목적지 후보 개수
int s, g, h; //예술가들의 출발지, g-h 예술가가 지나간 도로
int a, b, d; // a 와 b 사이에 d값의 양방향 도로
int x; //t 개의 목적지 후보

int loads[2001][2001]; //길 지도 loads[a][b] a위치에서 b의 위치로 이동가능하며 c의 값들이 있다. 도로는 1개
vector<int> goals; // 목적지들


/// <summary>
/// 출발점으로부터 다른 점까지의 최단거리 검색(다익스트라)
/// </summary>
/// <param name="start">출발점</param>
/// <returns></returns>
vector<int> dijkstra(const int& start)
{
	//각 노드까지 이동하는데 필요한 시간
	vector<int> dist(n + 1, INF); //memset 은 0과 -1 만 되어서 그냥 벡터를 사용
	dist[start] = 0;
	
	priority_queue<line_info> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int cost = pq.top().value;
		int here = pq.top().now;
		pq.pop();

		//더 낮은 코스트만 찾는다
		if (cost <= dist[here])
		{
			for (int i = 1; i <= n; i++)
			{
				if (i == here || loads[here][i] == -1) continue;
				
				int nextCost = cost + loads[here][i];
				//최단경로 갱신
				if (nextCost < dist[i])
				{
					dist[i] = nextCost;
					pq.push({ i,nextCost });
				}

			}

		}
	}

	return dist;
}

//루트를 s - g - h - 목적지  혹은 s - h - g - 목적지 로 한다음 짧은걸 선택하면 될 것이다. 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> T;
	for (int test = 0; test < T; test++)
	{
		memset(loads, -1, sizeof(int) * 2001 * 2001);
		goals.clear();

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		
		for (int lineCnt = 0; lineCnt < m; lineCnt++)
		{
			cin >> a >> b >> d;
			loads[a][b] = d;
			loads[b][a] = d;
		}

		for (int goalCnt = 0; goalCnt < t; goalCnt++)
		{
			cin >> x;
			goals.push_back(x);
		}

		sort(goals.begin(), goals.end());

		vector<int> root = dijkstra(s);
		vector<int> branch1 = dijkstra(g);
		vector<int> branch2 = dijkstra(h);

		vector<int> ret;
		for (int i = 1; i <= n; i++)
		{
			//시작지점에서 i번 도시까지 걸린 cost가 g,h점을 경유해서 돌아간 cost와 같은경우 ret에 저장
			if (root[i] == root[g] + branch1[h] + branch2[i] || root[i] == root[h] + branch2[g] + branch1[i])
			{
				ret.push_back(i);
			}
		}

		for (int i = 0; i < goals.size(); i++)
		{
			int here = goals[i];
			for (int j = 0; j < ret.size(); j++)
			{
				if (here == ret[j])
					cout << here << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}