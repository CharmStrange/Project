#include <iostream>
#include <vector>
#include <chrono>  // 시간 기능을 사용
#include <thread>  // 스레드 기능을 사용
using namespace std;

// 말판 기본 화면 구성 클래스
class BoardDraw {
public:
    int size; // 말판의 크기
    vector<vector<char>> board; // 2차원 벡터

    // 생성자는 말판의 시작 배치를 담당
    BoardDraw(int boardSize) : size(boardSize) {
        board.resize(size, vector<char>(size, '.'));
        board[size / 2 - 1][size / 2 - 1] = 'X';
        board[size / 2][size / 2] = 'X';
        board[size / 2][size / 2 - 1] = 'O';
        board[size / 2 - 1][size / 2] = 'O';
    }

    // 말판의 상태를 출력해주는 함수
    void ShowBoard() {
        cout << "  ";
        for (int i = 0; i < size; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << i << " ";
            for (int j = 0; j < size; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
};

class UserPlay {
public:
    vector<vector<char>>& board;

    // 생성자는 말판을 참조
    UserPlay(vector<vector<char>>& gameBoard) : board(gameBoard) {}

    // 말을 놓을 수 있는지의 여부를 확인
    bool OK(int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board.size())
            return false;
        return board[x][y] == '.';
    }

    // 주어진 위치에 말을 배치
    void place(int x, int y) {
        board[x][y] = 'X';
        Take(x, y, 'X');
    }

    // 컴퓨터의 말을 뒤집기
    void Take(int x, int y, char player) {
        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, -2, -2, 2, 2 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1, -2, 2, -2, 2 };

        for (int dir = 0; dir < 12; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            while (newX >= 0 && newX < board.size() && 
                   newY >= 0 && newY < board.size() && 
                   board[newX][newY] != '.' && board[newX][newY] != player) {
                newX += dx[dir];
                newY += dy[dir];
            }

            if (newX >= 0 && newX < board.size() && 
                newY >= 0 && newY < board.size() && board[newX][newY] == player) {
                int tempX = x + dx[dir];
                int tempY = y + dy[dir];
                while (tempX != newX || tempY != newY) {
                    board[tempX][tempY] = player;
                    tempX += dx[dir];
                    tempY += dy[dir];
                }
            }
        }
    }
};

class ComPlay {
public:
    vector<vector<char>>& board;

    // 생성자
    ComPlay(vector<vector<char>>& gameBoard) : board(gameBoard) {}

    // 말을 놓을 수 있는지의 여부를 확인
    bool OK(int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board.size())
            return false;
        return board[x][y] == '.';
    }

    // 주어진 위치에 말을 배치
    void place(int& x, int& y) {
        int bestScore = -1;
        int bestX = -1;
        int bestY = -1;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (OK(i, j)) {
                    int score = Weight(i, j);
                    if (score > bestScore) {
                        bestScore = score;
                        bestX = i;
                        bestY = j;
                    }
                }
            }
        }

        x = bestX;
        y = bestY;
        board[x][y] = 'O';
        Take(x, y, 'O');
    }

    // 컴퓨터의 말 배치에서 가중치를 계산
    int Weight(int x, int y) {
        int score = 0;

        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, -2, -2, 2, 2 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1, -2, 2, -2, 2 };

        for (int dir = 0; dir < 12; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            int count = 0;
            while (newX >= 0 && newX < board.size() && 
                   newY >= 0 && newY < board.size() && 
                   board[newX][newY] != '.' && board[newX][newY] != 'O') {
                newX += dx[dir];
                newY += dy[dir];
                count++;
            }

            if (newX >= 0 && newX < board.size() && 
                newY >= 0 && newY < board.size() && 
                board[newX][newY] == 'O') {
                score += count;
            }
        }

        return score;
    }


    // 사용자의 말 뒤집기
    void Take(int x, int y, char player) {
        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, -2, -2, 2, 2 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1, -2, 2, -2, 2 };

        for (int dir = 0; dir < 12; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            while (newX >= 0 && newX < board.size() && newY >= 0 && newY < board.size() && board[newX][newY] != '.' && board[newX][newY] != player) {
                newX += dx[dir];
                newY += dy[dir];
            }

            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board.size() && board[newX][newY] == player) {
                int tempX = x + dx[dir];
                int tempY = y + dy[dir];
                while (tempX != newX || tempY != newY) {
                    board[tempX][tempY] = player;
                    tempX += dx[dir];
                    tempY += dy[dir];
                }
            }
        }
    }
};

class BoardCheck {
public:
    const vector<vector<char>>& board;

    // 생성자
    BoardCheck(const vector<vector<char>>& gameBoard) : board(gameBoard) {}

    // 사용자와 컴퓨터의 말 개수를 세기
    int GetStone(char player) const {
        int count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == player)
                    count++;
            }
        }
        return count;
    }

    // 
    bool full() const {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.')
                    return false;
            }
        }
        return true;
    }

    // 게임이 종료되는 조건
    bool GameOver() const {
        int computerCount = GetStone('O');
        int userCount = GetStone('X');

        if (computerCount == userCount && computerCount + userCount < board.size() - 2) {
            cout << "무승부!" << endl;
            return true;
        }
        else if (computerCount + userCount == board.size() * board.size() - 2) {
            cout << "게임 종료!" << endl;
            return true;
        }
        return false;
    }
};

// 현재 사용자와 컴퓨터의 말의 개수를 출력하는 함수
void PrintStoneCount(const vector<vector<char>>& board) {
    int computerCount = 0;
    int userCount = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 'O')
                computerCount++;
            else if (board[i][j] == 'X')
                userCount++;
        }
    }
    cout << endl << "현재 사용자 말 개수: " << userCount << endl;
    cout << "현재 컴퓨터 말 개수: " << computerCount << endl << endl;
}

// 컴퓨터의 차례에서 2초 대기하는 함수
void Delay() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    int boardSize;
    
    while (true) {
        cout << "게임판 크기를 입력하세요: ";
        cin >> boardSize;

        if (boardSize < 6) {
            cout << "말판의 크기가 너무 작습니다! 다시 입력해 주세요. " << endl;
            continue;
        }

        break;
    }

    // 각 클래스에 대한 객체를 생성
    BoardDraw boardDraw(boardSize);
    UserPlay userPlay(boardDraw.board);
    ComPlay comPlay(boardDraw.board);
    BoardCheck boardCheck(boardDraw.board);

    // Othello Game 시작
    while (true) {
        boardDraw.ShowBoard();
        PrintStoneCount(boardDraw.board);
        int x, y;

        while (true) {
            cout << "사용자 차례입니다. x와 y 좌표를 입력하세요: ";
            cin >> x;
            cin >> y;
            if (userPlay.OK(x, y))
                break;
            cout << "그 곳엔 말을 놓을 수 없습니다! 다시 입력해 주세요." << endl;
        }

        userPlay.place(x, y);
        if (boardCheck.GameOver())
            break;

        cout << endl << "컴퓨터가 말을 놓는 중..." << endl << endl;
        Delay();  // 2초 대기
        comPlay.place(x, y);
        if (boardCheck.GameOver())
            break;
    }

    boardDraw.ShowBoard();
    PrintStoneCount(boardDraw.board);

    return 0;
}
