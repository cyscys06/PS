#include <bits/stdc++.h>
using namespace std;

class Job {
    string ID;
    string requestName;
    int printCount;
    
    public: 
        Job(string id, string name, int count) {
            ID = id;
            requestName = name;
            printCount = count;
        }

        void printAll() {
            cout << "인쇄 처리 완료.\n";
            cout << "ID: " << ID << endl;
            cout << "인쇄 요청자 이름: " << requestName << endl;        
            cout << "인쇄 페이지 수: " << printCount << endl;
            cout << endl;
        }
};

class Printer {
    queue<Job> waiting;

    public:
        void insert(Job job) { // 새로운 작업 추가
            waiting.push(job);
        }
        void print() { // 추가된 작업 처리 및 처리된 작업 삭제
            int count = waiting.size();
            for (int i = 0; i < count; i++) {
                Job job = waiting.front();
                job.printAll(); // 작업 처리
                waiting.pop(); // 작업 삭제
            }
        }
};

int main() {
    Job job1 = Job("123", "choi", 23);
    Job job2 = Job("124", "kim", 3);
    Job job3 = Job("125", "park", 13);
    
    Printer printer;
    printer.insert(job1);
    printer.insert(job2);
    printer.insert(job3);

    printer.print();

    return 0;
}