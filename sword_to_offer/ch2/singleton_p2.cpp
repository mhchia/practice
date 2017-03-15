#include <iostream>
#include <mutex>

using namespace std;

mutex foo;

class Singleton {

private:
    static Singleton* instance;
    Singleton() = default;

public:
    static Singleton* GetInstance()
    {
        foo.lock();
        if (!instance) {
            instance = new Singleton();
        }
        foo.unlock();
        return instance;
    }
    static void Test()
    {
        std::cout << (instance == nullptr) << std::endl;
    }
};



Singleton* Singleton::instance; // global default init

int main(void)
{
    Singleton::Test(); // 1
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    Singleton::Test(); // false
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}

