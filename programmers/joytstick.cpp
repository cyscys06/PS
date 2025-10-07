#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string name) 
{
    int answer = 0;
    int len = name.length();

    for (char c : name) 
    {
        if (c < 26 - c + 1)
        {
            answer += c;
        }
        else
        {
            answer += 26 - c + 1;
        }
    }
    
    int left_index = 0, left_count = 0, right_index = 0, right_count = 0;
    for (int i = 0; i < len; i++) 
    {

        while (left_index < len && name[left_index] == 'A')
        {
            left_count++;
            left_index--;
            if (left_index == -1)
            {
                left_index = len - 1;
            }
        }
        
        while (right_index < len && name[right_index] == 'A')
        {
            right_index++;
            right_count++;
        }

        if (left_count < right_count)
        {
            answer += left_count
        }
        else
        {
            answer += right_count;
        }
    }

    return answer;
}

int main() 
{
    string name;
    cin >> name;
    cout << solution(name);
    return 0;
}
