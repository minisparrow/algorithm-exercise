#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main() {
    // 定义一个 lambda 表达式
    auto comp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    };

    // 使用 decltype 获取 comp 的类型
    using CompType = decltype(comp);

    // 定义优先队列，使用 lambda 作为比较函数
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompType> pq(comp);

    // 向优先队列中添加元素
    pq.push({3, 1});
    pq.push({2, 2});
    pq.push({1, 3});

    // 打印优先队列的元素
    while (!pq.empty()) {
        auto elem = pq.top();
        pq.pop();
        cout << "{" << elem.first << ", " << elem.second << "}" << endl;
    }

    return 0;
}

