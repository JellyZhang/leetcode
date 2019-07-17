#include <string>
#include <iostream>
using namespace std;

int main(){

    std::string a = "abc";
    for (auto i:a){
        std::cout<<i;
    }
    return 0;
}
