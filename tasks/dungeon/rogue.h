#pragma once

#include "dungeon.h"

#include <stdexcept>
#include <set>
#include <queue>

Room* FindFinalRoom(Room* starting_room) {
    std::set<Room*> visited;
    std::set<std::string> keys;
    std::set<Door*> doors;

    std::queue<Room*> q;
    q.push(starting_room);
    visited.insert(starting_room);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now->IsFinal()) {
            return now;
        }

        for (size_t i = 0; i != now->NumKeys(); ++i) {
            keys.insert(now->GetKey(i));
        }

        for (size_t i = 0; i != now->NumDoors(); ++i) {
            doors.insert(now->GetDoor(i));
        }

        for (auto it = doors.begin(); it != doors.end();) {
            bool opened = false;
            if ((*it)->IsOpen()) {
                if (!visited.contains((*it)->GoThrough())) {
                    q.push((*it)->GoThrough());
                    visited.insert((*it)->GoThrough());
                }
                opened = true;
            } else {
                for (const auto& key : keys) {
                    if ((*it)->TryOpen(key)) {
                        if (!visited.contains((*it)->GoThrough())) {
                            q.push((*it)->GoThrough());
                            visited.insert((*it)->GoThrough());
                        }
                        opened = true;
                        break;
                    }
                }
            }

            if (opened) {
                it = doors.erase(it);
            } else {
                ++it;
            }
        }
    }

    return nullptr;
}
