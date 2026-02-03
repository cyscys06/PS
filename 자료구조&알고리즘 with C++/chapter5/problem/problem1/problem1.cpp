#include <bits/stdc++.h>
using namespace std;

struct Work {   
    int workID;
    int startTime;
    int endTime;

    Work(int w, int s, int e) : workID(w), startTime(s), endTime(e) {}

    bool operator<(const Work& work) const {
        // 종료시간끼리 비교
        return this->endTime < work.endTime; 
    }
};

ostream& operator<<(ostream& os, const Work& work) {
    os << left;
    os << "[" << setw(2) << work.workID << "] " 
       << setw(3) << work.startTime << " -> "  << setw(6) << work.endTime 
       << "|";

    for (int i = 1; i <= 20; i++) {
        if (work.startTime < i && i <= work.endTime) {
            os << "*";
        } else {
            os << " ";
        }
    }
    cout << "|\n";

    return os;
}

list<Work> workList; // 작업 리스트

vector<Work> scheduling(list<Work> workList) {
    // 스케쥴링된 작업들을 저장할 벡터
    vector<Work> scheduledWorkList;

    int timeCapacity = 20;
    int currentEndTime = 0; 
    int workCount = 0;

    // 종료시간 기준 정렬(가장 빠른 종료시간부터 선택하므로 내림차순 아님)
    workList.sort();
    auto currentWork = workList.begin();

    while (currentEndTime <= timeCapacity && currentWork != workList.end()) {
        if ((*currentWork).startTime >= currentEndTime) {
            // 가장 빠른 종료시간을 가진 작업을 선택하여 저장
            scheduledWorkList.push_back(*currentWork);
            currentEndTime = (*currentWork).endTime; 
        }
        currentWork++;
    }
    
    // 마지막으로 추가한 작업이 시간 수용량을 초과하는 경우
    if (currentEndTime > timeCapacity) { 
        scheduledWorkList.pop_back();
    }

    return scheduledWorkList;
}

int main() {
    workList.push_back(Work(1, 5, 9));
    workList.push_back(Work(2, 6 ,20));
    workList.push_back(Work(3, 16, 19));
    workList.push_back(Work(4, 7, 10));
    workList.push_back(Work(5, 9, 19));
    workList.push_back(Work(6, 10, 19));
    workList.push_back(Work(7, 6, 12));
    workList.push_back(Work(8, 2, 17));
    workList.push_back(Work(9, 10, 13));
    workList.push_back(Work(10, 4, 7));

    cout << " [전체 작업]\n";
    for (Work work : workList) {
        cout << work;
    }

    vector<Work> scheduledWorkList = scheduling(workList);

    cout << "[스케쥴 조정한 작업]\n";
    for (Work work : scheduledWorkList) {
        cout << work;
    }

    return 0;
}