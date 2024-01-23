#ifndef CONTAINER_H
# define CONTAINER_H

# include <iostream>
# include <string>
# include <vector>

// Sequence Container
// - vector
// - array
// - deque
// - list
// - forward_list

// [ Container ] : player log
class PLAYER_LOG {
public:
    PLAYER_LOG() = default;
    
    vector<string> player_logs;

    void add_log(const string& log) {
        player_logs.push_back(log);    
    }

    void display_log() const {
        cout << "[ Player Log ] :";
        for (const auto& player_log : player_logs) {
            cout << " | " << player_log;
        }
    }

};
#endif