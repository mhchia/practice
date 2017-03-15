#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <stack>

#include "list.hpp"

using namespace std;

void print_list_iteratively(ListNode* listnode)
{
    while (listnode) {
        cout << listnode->val << " ";
        listnode = listnode->next;
    }
}

void print_list_recursively(ListNode* listnode)
{
    if (listnode == nullptr) {
        return;
    }
    cout << listnode->val << " ";
    print_list_recursively(listnode->next);
}

void print_list_reversely_iteratively(ListNode* listnode)
{
    if (listnode == nullptr) return;
    stack<int> s;
    while (listnode) {
        s.push(listnode->val);
        listnode = listnode->next;
    }
    while (!s.empty()) {
        int val = s.top();
        cout << val << " ";
        s.pop();
    }
}

void print_list_reversely_recursively(ListNode* node)
{
    if (node == nullptr) {
        return;
    }
    print_list_reversely_recursively(node->next);
    cout << node->val << " ";
}

auto get_dice(int low, int high) -> std::function<int(void)>
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(low, high);
    std::function<int(void)> dice = std::bind(distribution, generator);
    // return distribution(generator)();
    return dice;
}

struct Pair
{
    double a, b;
    double multiply() { return a * b; }
};

void test()
{

}

ListNode* create_random_listnode()
{
    auto len_dice = get_dice(3, 10);
    auto val_dice = get_dice(10, 99);
    ListNode* ptr = nullptr;
    int len = len_dice();
    for (int i = 0; i < len; ++i) {
        ListNode* new_node = new ListNode();
        new_node->val = val_dice();
        new_node->next = ptr;
        ptr = new_node;
    }
    return ptr;
}

void print_example()
{
    ListNode* node = create_random_listnode();
    print_list_iteratively(node); puts("");
    print_list_recursively(node); puts("");
    print_list_reversely_iteratively(node); puts("");
    print_list_reversely_recursively(node); puts("");

}

int main(void)
{
}

