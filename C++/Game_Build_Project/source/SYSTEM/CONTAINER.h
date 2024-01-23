#ifndef CONTAINER_H
# define CONTAINER_H

# include <iostream>
# include <string>
# include <deque>  // Using deque for easy insertion and removal at both ends

using namespace std;

// [ Container ] : player log
class PLAYER_LOG {
public:
    PLAYER_LOG() = default;

    deque<string> player_logs;  // Using deque for easy insertion and removal

    void add_log(const string& log) {
        if (player_logs.size() == 10) {
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
        cout << endl;
    }
};

#endif
