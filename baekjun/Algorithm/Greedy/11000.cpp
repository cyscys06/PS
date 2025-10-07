#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> Subject(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Subject[i].first >> Subject[i].second;
    }
    sort(Subject.begin(), Subject.end());

    priority_queue<int, vector<int>, greater<int>> Ftime; 
    Ftime.push(Subject[0].second); 
    
    for (int i = 1; i < N; i++) 
    {
        int start = Subject[i].first;
        int end = Subject[i].second;

        if (Ftime.top() <= start) 
        {                         
            Ftime.pop();
        }
        
        Ftime.push(end);
    }
    cout << size(Ftime);
    return 0;
}