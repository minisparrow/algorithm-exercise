
#include <iostream>
#include <queue>
#include <vector>

void test_maxPQ() {
  // 默认的 priority_queue 是最大堆
  std::priority_queue<int> maxPQ;
  maxPQ.push(5);
  maxPQ.push(10);
  maxPQ.push(3);

  std::cout << "最大优先队列 (最大堆): ";
  while (!maxPQ.empty()) {
    std::cout << maxPQ.top() << " "; // 输出 10 5 3
    maxPQ.pop();
  }
  std::cout << std::endl;
}

void test_minPQ() {
  // 最小优先队列
  std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
  minPQ.push(5);
  minPQ.push(10);
  minPQ.push(3);

  std::cout << "最小优先队列 (最小堆): ";
  while (!minPQ.empty()) {
    std::cout << minPQ.top() << " "; // 输出 3 5 10
    minPQ.pop();
  }
  std::cout << std::endl;
}

void test_cumstom() {
  // 自定义优先级队列，比较器使得优先队列按降序排列
  auto cmp = [](int left, int right) { return left < right; };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> customPQ(cmp);

  customPQ.push(5);
  customPQ.push(10);
  customPQ.push(3);

  std::cout << "自定义优先队列: ";
  while (!customPQ.empty()) {
    std::cout << customPQ.top() << " "; // 按照比较器顺序输出
    customPQ.pop();
  }
  std::cout << std::endl;
}

void test_greater_function() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9};
  // std::sort(numbers.begin(), numbers.end(), std::greater<int>());
  auto greater = [&](int left, int right) -> bool { return left > right; };
  std::sort(numbers.begin(), numbers.end(), greater);
  for (int n : numbers) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}

int main() {
  test_maxPQ();
  test_minPQ();
  test_cumstom();
  test_greater_function();
  return 0;
}
