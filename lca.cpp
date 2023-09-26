// LCA最近公共祖先模板
#include <bits/stdc++.h>

using namespace std;

const int MXN = 5 * 1e5 + 5;
int N, M, S, iptx, ipty; //N为边，M为询问lca的次数，S为根节点编号
// v数组代表v[root]，和root连接的节点
vector<int> v[MXN];
//fa[x][i]代表着，x节点的第2^i个父亲节点
int fa[MXN][32], dep[MXN];

//dfs建树
void dfs(int root, int faIndex) {
	fa[root][0] = faIndex;
	dep[root] = dep[faIndex] + 1;
	for (int i = 1; i <= 30; i++) {
		// 当i等于2时，root的第4个父亲等于root的第2个父亲的第二个父亲
		fa[root][i] = fa[fa[root][i - 1]][i - 1];
	}
	int sz = v[root].size();
	// root节点下的节点再建树
	for (int i = 0; i < sz; i++) {
		if (v[root][i] == faIndex) continue;
		dfs(v[root][i], root);
	}
}

int lca(int ix, int iy) {
	if (dep[ix] > dep[iy]) swap(ix, iy); // 保证iy的深度要大于ix的深度
	int h = dep[iy] - dep[ix];
	for (int j = 0; h > 0; ++j, h >>= 1) { // 然后通过二进制来开始跳转，使得iy的深度和ix一样
		if (h & 1 == 1) iy = fa[iy][j];
	}
	if (iy == ix) return ix;
	// 一开始j很大，相当与很远的父亲，肯定是相等的，然后一步步减少，第一次找到不相等的时候，我们就可以把ix、iy给上升到这个位置
	for (int j = 30; j >= 0 && iy != ix; j--) { // 猜测二进制的位置
		if (fa[ix][j] != fa[iy][j]) { // 调整ix和iy，不停的往前
			ix = fa[ix][j], iy = fa[iy][j];
		}
	}
	return fa[iy][0];
}

int main() {
	memset(fa, 0, sizeof(fa));
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &iptx, &ipty);
		v[iptx].push_back(ipty);
		v[ipty].push_back(iptx);
	}
	dfs(S, 0);

	for (int i = 0; i < M; i++) {
		scanf("%d %d",&iptx,&ipty);
		printf("%d\n",lca(iptx,ipty));
	}

	return 0;
}
