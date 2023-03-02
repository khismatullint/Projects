#include <algorithm>;
#include <iostream>;
#include <vector>;
struct query {
    int q = 0, l = 0, r = 0, id = 0;
    int rez = 0;
};
bool cmp(const query& a, const query& b) {
    if (a.l / 550 == b.l / 550)
        return a.r < b.r;
    else
        return a.l < b.l;
}
bool cmp2(query& a, query& b) { return (a.id < b.id); }
void mo(query& q, int& l, int& r, int& ans, std::vector<int>& cnt,
        const std::vector<int>& v) {
    while (l < q.l) {
        --cnt[v[l]];
        if (cnt[v[l]] == 0)
            --ans;
        ++l;
    }
    while (l > q.l) {
        --l;
        if (cnt[v[l]] == 0)
            ++ans;
        ++cnt[v[l]];
    }
    while (r < q.r) {
        ++r;
        if (cnt[v[r]] == 0)
            ++ans;
        ++cnt[v[r]];
    }
    while (r > q.r) {
        --cnt[v[r]];
        if (cnt[v[r]] == 0)
            --ans;
        --r;
    }
    q.rez = ans;
}

int main() {
    int nec, m;
    std::cin >> nec;
    std::vector<int> v(nec), pos;
    for (size_t i = 0; i < nec; ++i) {
        std::cin >> v[i];
    }
    pos = v;
    sort(pos.begin(), pos.end());
    for (size_t i = 0; i < nec; ++i) {
        v[i] = lower_bound(pos.begin(), pos.end(), v[i]) - pos.begin();
    }
    std::cin >> m;
    std::vector<query> q(m);
    for (size_t i = 0; i < m; ++i) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        q[i].l = l - 1;
        q[i].r = r - 1;
        q[i].id = i;
    }
    std::vector<int> cnt(nec);
    int r = -1, l = 0, ans = 0;
    for (size_t i = 0; i < m; ++i) {
        mo(q[i], l, r, ans, cnt, v);
    }
    std::sort(q.begin(), q.end(), cmp2);
    for (size_t i = 0; i < m; ++i) {
        std::cout << q[i].rez << "\n";
    }
}