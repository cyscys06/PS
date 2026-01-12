#include <bits/stdc++.h>
using namespace std;



class Song {
    private:
        string songName;
        string artistName;
        double playtime;
    public:
        Song(string songName, string artistName, double playtime) {
            this->songName = songName;
            this->artistName = artistName;
            this->playtime = playtime;
        }

        Song(const Song& song) {
            this->songName = song.songName;
            this->artistName = song.artistName;
            this->playtime = song.playtime;
        }

        void printAll() {
            cout << "노래 이름: " << songName << endl;
            cout << "아티스트 이름: " << artistName << endl;
            cout << "재생 시간: " << playtime << endl;
        }

        double getPlayTime() const {
            return playtime;
        }
};

struct Node {
    Node* next;
    Node* prev;
    Song song;
};

class Playlist_Iterator {
    private: 
        Node* cur;
    public:
        friend class Playlist;
        Playlist_Iterator(Node* cur) {
            this->cur = cur;
        }

        Song& operator*() {
            return cur->song;
        }

        Node* getCur() {
            return cur;
        }

        Playlist_Iterator& operator++() {
            cur = cur->next; // cur이 cur자신의 next(다음 노드)를 가리키도록 수정
            return *this; // 증가한 자기 자신(객체)를 반환
        }

        Playlist_Iterator operator++(int) {
            Playlist_Iterator term = *this;
            ++(*this); // 자기 자신은 실제로 증가
            return term; // 증가하기 전의 자신을 반환
        }

        Playlist_Iterator& operator--() {
            cur = cur->prev; // cur이 cur자신의 prev(이전 노드)를 가리키도록 수정
            return *this; // 감소한 자기 자신(객체)를 반환
        }

        Playlist_Iterator operator--(int) {
            Playlist_Iterator term = *this;
            --(*this); // 자기 자신은 실제로 감소
            return term; // 감소하기 전의 자신을 반환
        }
        
        friend bool operator==(const Playlist_Iterator& it1, 
            const Playlist_Iterator& it2) {
            return it1.cur == it2.cur;
        }

        friend bool operator!=(const Playlist_Iterator& it1, 
            const Playlist_Iterator& it2) {
            return it1.cur != it2.cur;
        }
};

class Playlist {
    private:
        Node* head = nullptr;
        Node* rear = nullptr;
        string playlistName;
        int songCount = 0;
        double playTime = 0;
    public:
        Playlist(string playlistName) {
            this->playlistName = playlistName;
        }

        void insert(Song& song) {
            Node* newNode = new Node{nullptr, nullptr, song};
            if (head == nullptr) {
                head = rear = newNode;
            } 
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;

            this->songCount += 1;
            this->playTime += song.getPlayTime();
        }

        void remove(Playlist_Iterator cur) {
            Node* node = cur.getCur();
            if (node == nullptr) {
                return;
            }
            
            if (node->prev) node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;

            if (node == head) head = node->next;
            if (node == rear) rear = node->prev;

            delete node;
        }

        void printAll() {
            cout << "재생목록 이름: " << playlistName << endl;
            cout << "노래 개수: " << songCount << endl;
            cout << "총 재생 시간: " << playTime << endl;
        }

        Playlist_Iterator begin() {
            return Playlist_Iterator(head);
        }

        Playlist_Iterator begin() const {
            return Playlist_Iterator(head);
        }

        Playlist_Iterator end() {
            return Playlist_Iterator(nullptr);
        }

        Playlist_Iterator end() const {
            return Playlist_Iterator(nullptr);
        }

        Playlist_Iterator next(Playlist_Iterator& iterator, int num) {
            Playlist_Iterator term = iterator;
            for (int i = 0; i < num; i++) {
                ++term;
            }

            return term;
        }

        Playlist_Iterator prev(Playlist_Iterator& iterator, int num) {
            Playlist_Iterator term = iterator;
            for (int i = 0; i < num; i++) {
                --term;
            }

            return term;
        }
};




int main() {
    Song song1 = Song("a", "s", 1);
    Song song2 = Song("b", "d", 3.4);
    Song song3 = Song("a", "c", 2.3);

    Playlist playlist1 = Playlist("asd");
    playlist1.insert(song1);
    playlist1.insert(song2);
    playlist1.insert(song3);
    playlist1.printAll();

    cout << "노래 목록: \n";
    for (Song& song : playlist1) {
        song.printAll();
    }

    return 0;
}