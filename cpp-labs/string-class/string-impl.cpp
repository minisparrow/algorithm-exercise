#include <cstring>
#include <iostream>
#include <valarray>
using namespace std;
class String {
public:
  String(const char *str);       // constructor
  String(const String &another); // copy constructor
  String &operator=(const String &rhs);
  ~String();
  char *data; // save string to memory
};

// constructor
String::String(const char *str) {
  if (str == nullptr) {
    data = new char[1];
    data[0] = '\0'; // 结束符
  } else {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
  }
}

// copy constructor 复制构造函数
String::String(const String &another) {
  // memory alloc
  data = new char[strlen(another.data) + 1];
  strcpy(data, another.data);
}

// operator= 赋值操作符重载 copy assignment operator overloaded
String &String::operator=(const String &rhs) {
  // 检查自我赋值
  if (this == &rhs) {
    return *this; // 如果是自我赋值，直接返回当前对象
  }

  // 释放已有资源
  delete[] data;

  // 分配新内存并复制数据
  data = new char[strlen(rhs.data) + 1]; // 分配内存
  strcpy(data, rhs.data);                // 复制字符串

  // 返回当前对象的引用
  return *this;
}

String::~String() {
  delete[] data;
  data = nullptr;
}

int main() {
  const char *a = "Hello world";
  cout << "a length: " << strlen(a) << endl;
  String str(a); // constructor
  std::cout << str.data << endl;
  str = "Nice to see you";
  std::cout << str.data << endl;
  return 0;
}
