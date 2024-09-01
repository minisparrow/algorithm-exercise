#include <iostream>
#include <vector>
#include <algorithm>

// 定义一个Trait来提供操作能力
template<typename ConcreteOp>
class ExampleTrait {
public:
    unsigned getNumElements() const {
        return std::count_if(static_cast<const ConcreteOp*>(this)->data.begin(),
                             static_cast<const ConcreteOp*>(this)->data.end(),
                             [](int i) { return i != 0; });
    }
};

// 一个具体的操作类实现了Trait
class MyOp : public ExampleTrait<MyOp> {
public:
    std::vector<int> data = {1, 2, 0, 3, 0, 4};

    MyOp() {}
};

int main() {
    MyOp op;
    std::cout << "Number of elements: " << op.getNumElements() << std::endl;
    return 0;
}

