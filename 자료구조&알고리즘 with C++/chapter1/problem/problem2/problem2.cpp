#include <bits/stdc++.h>
using namespace std;

struct card
{
    int number;

    enum shape {
        HEART,
        SPADE,
        CLUB,
        DIAMOND
    } shape;

    string to_string() {
        ostringstream os;

        if (number > 0 && number <= 10)
        {
            os << number;
        }
        else
        {
            switch (number)
            {
            case 1:
                os << "Ace";
                break;
            case 11:
                os << "Jack";
                break;
            case 12:
                os << "Queen";
                break;
            case 13:
                os << "King";
                break;
            }
        }
        
        os << " of ";
        
        switch (shape) {
            case HEART:
                os << "hearts";
                break;
            case SPADE:
                os << "spades";
                break;
            case CLUB:
                os << "clubs";
                break;
            case DIAMOND:
                os << "diamonds";
                break;
        }

        return os.str();
    }
};

struct game {
    array<card, 52> deck;
    vector<card> p1, p2, p3, p4;

    void buildDeck() {
        for (int i = 0; i < 13; i++) {
            deck[i] = card{i + 1, card::HEART}; // 하트 1~13
        }
        for (int i = 0; i < 13; i++) {
            deck[i + 13] = card{i + 1, card::SPADE}; // 스페이드 1~13
        }
        for (int i = 0; i < 13; i++) {
            deck[i + 26] = card{i + 1, card::CLUB}; // 클로버 1~13
        }
        for (int i = 0; i < 13; i++) {
            deck[i + 39] = card{i + 1, card::DIAMOND}; // 다이아몬드 1~13
        }
    }

    void dealCards() {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        // 현재 시간을 기반으로 한 정수값을 생성하여 unsigned 변수에 저장
        // 프로그램을 실행할 때마다 다른 시드값이 나옴

        shuffle(deck.begin(), deck.end(), default_random_engine(seed));
        // default_random_engine(seed): 특정 시드값과 대응하는 난수 순서를 만들어냄
        // ex: 마크 시드값이랑 같음

        p1 = {deck.begin(), deck.begin() + 13};
        p2 = {deck.begin() + 13, deck.begin() + 26};
        p3 = {deck.begin() + 26, deck.begin() + 39};
        p4 = {deck.begin() + 39, deck.end()};
    }

    bool compareAndRemove(vector<card>& p1, vector<card>& p2) {
        if (p1.back().number == p2.back().number) {
            p1.pop_back();
            p2.pop_back();

            return true;
        }
        return false;
    }

    void playOneRound() {
        // 모든 경우의 수를 비교
        if (compareAndRemove(p1, p2)) {
            compareAndRemove(p3, p4);
            return;
        }
        else if (compareAndRemove(p1, p3)) {
            compareAndRemove(p2, p4);
            return;
        }
        else if (compareAndRemove(p1, p4)) {
            compareAndRemove(p2, p3);
            return;
        }
        else if (compareAndRemove(p2, p3)) {
            // p1, p4 이미 비교함
            return;
        }
        else if (compareAndRemove(p2, p4)) {
            // p1, p3 이미 비교함
            return;
        }
        else if (compareAndRemove(p3, p4)) {
            // p1, p2 이미 비교함
            return;
        }

        // 여기부터는 모든 카드가 다른 경우
        // 덱 셔플해서 다시 비교
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        // 새로운 시드 할당
        shuffle(p1.begin(), p1.end(), default_random_engine(seed));
        shuffle(p2.begin(), p2.end(), default_random_engine(seed));
        shuffle(p3.begin(), p3.end(), default_random_engine(seed));
        shuffle(p4.begin(), p4.end(), default_random_engine(seed));
    }

    bool isGameComplete() {
        return p1.empty() || p2.empty() || p3.empty() || p4.empty();
        // 4명중 한명이라도 덱 비면 게임 끝
    }

    void playGame() {
        while(!isGameComplete()) {
            playOneRound();
        }
    }

    int getWinner() {
        if (p1.empty()) {
            return 1;
        }
        else if (p2.empty()) {
            return 2;
        }
        else if (p3.empty()) {
            return 3;
        }
        else {
            return 4;
        }
    }
};

int main() {
    game newGame;
    newGame.buildDeck();
    newGame.dealCards();
    newGame.playGame();

    int winner = newGame.getWinner();

    cout << winner << "번 플레이어가 이겼습니다.\n";
    return 0;
}