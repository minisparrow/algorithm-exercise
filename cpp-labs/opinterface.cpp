#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// 定义接口
struct OpInterface {
  struct Concept {
    virtual ~Concept() = default;
    virtual unsigned getNumElements() const = 0;
  };

  template <typename ConcreteOp> struct Model : Concept {
    std::shared_ptr<ConcreteOp> impl;
    Model(std::shared_ptr<ConcreteOp> op) : impl(std::move(op)) {}

    unsigned getNumElements() const override { return impl->getNumElements(); }
  };

  std::unique_ptr<const Concept> self;

  template <typename ConcreteOp>
  OpInterface(std::shared_ptr<ConcreteOp> op)
      : self(std::make_unique<Model<ConcreteOp>>(std::move(op))) {}

  unsigned getNumElements() const { return self->getNumElements(); }
};

// 一个具体的操作类
class MyOp {
public:
  std::vector<int> data = {1, 2, 0, 3, 0, 4};

  unsigned getNumElements() const {
    return std::count_if(data.begin(), data.end(),
                         [](int i) { return i != 0; });
  }
};

int main() {
  auto op = std::make_shared<MyOp>();
  OpInterface opInterface(op);
  std::cout << "Number of elements: " << opInterface.getNumElements()
            << std::endl;
  return 0;
}
