#include<iostream>
#include<list>
using namespace std;
int main(){
std::list<int>l1 = { 10,20,30,40 };
l1.push_back(5);
l1.push_front(15);
l1.emplace_back(25);
l1.emplace_front(35);
l1.insert(l1.begin(), 1);

}