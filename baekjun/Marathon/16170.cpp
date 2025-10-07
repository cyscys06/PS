#include <bits/stdc++.h>
using std::cout;
using std::time_t;
using std::tm;
using std::localtime;
using std::put_time;

int main() 
{
    auto now = std::chrono::system_clock::now();
    time_t time_now = std::chrono::system_clock::to_time_t(now);
    
    tm* local_time = localtime(&time_now);

    cout << put_time(local_time, "%Y\n%m\n%d");

    return 0;
}
