#ifndef CONTAINER_H
# define CONTAINER_H

// MACROS
# define US unsigned short
# define MAX_SAVES 3
# define MAX_LOGS 10

// ESSENTIAL HEADERS
# include <iostream>
# include <string>
# include <deque>  // Using deque for easy insertion and removal at both ends
# include <vector>

using namespace std;

class PLAYER_SAVE;
vector<PLAYER_SAVE> PLAYER_SAVES;

// [ Contianer ] : Player saves
class PLAYER_SAVE {
private:
    US player_saves;

public:
    static US number_of_player_saves;

    PLAYER_SAVE() : player_saves(number_of_player_saves++) {
        // If the container is full, remove the oldest save
        if (PLAYER_SAVES.size() == MAX_SAVES) {
            PLAYER_SAVES.erase(PLAYER_SAVES.begin());
        }
        PLAYER_SAVES.push_back(*this);
    }

    ~PLAYER_SAVE() {}
};

// [ Container ] : player log
class PLAYER_LOG {
public:
    PLAYER_LOG() = default;

    deque<string> player_logs;  // Using deque for easy insertion and removal

    void add_log(const string& log) {
        if (player_logs.size() == MAX_LOGS) {
            // If the container is full, remove the oldest log
            player_logs.pop_front();
        }
        player_logs.push_back(log);
    }

    void display_logs() const {
        cout << "[ Player Log ] :";
        for (const auto& player_log : player_logs) {
            cout << " | " << player_log;
        }
    }

    ~PLAYER_LOG() {}
};

#endif
