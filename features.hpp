#ifndef FEATURES_HPP
#define FEATURES_HPP
#include <vector>
#include <string>
#include <iostream>
#include <set>
namespace apartment {
    class Entity;
    class Bedroom;
    class MasterBed;
    class HalfBath;
    class FullBath;
    class Kitchen;
    class Pantry;
    class Closet;
    class Hallway;
    class DiningRoom;
    class LivingRoom;

    // class for a general room 
    class Entity {
    public:
        Entity(int width, int height) : m_width(width), m_height(height), m_label('E') {}
        Entity(int width, int height, char label) : m_width(width), 
            m_height(height), m_label(label) {}
        int get_width() const {
            return m_width;
        }
        int get_height() const {
            return m_height;
        }
        char get_label() const {
            return m_label;
        }
        virtual bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const {
            (void) neighbors;
            (void) all_rooms;
            return true;
        }
    private:
        int m_width;
        int m_height;
        char m_label;
    };
    // class for a bedroom
    class Bedroom : public Entity {
    public:
        Bedroom(int width, int height) : Entity(width, height, 'B') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a master bedroom
    class MasterBed : public Entity {
    public:
        MasterBed(int width, int height) : Entity(width, height, 'M') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a half bathroom 
    class HalfBath : public Entity {
    public:
        HalfBath(int width, int height) : Entity(width, height, 'H') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a full bathroom 
    class FullBath : public Entity {
    public:
        FullBath(int width, int height) : Entity(width, height, 'F') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a kitchen
    class Kitchen : public Entity {
    public:
        Kitchen(int width, int height) : Entity(width, height, 'K') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a pantry
    class Pantry : public Entity {
    public:
        Pantry(int width, int height) : Entity(width, height, 'P') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a closet 
    class Closet : public Entity {
    public:
        Closet(int width, int height) : Entity(width, height, 'C') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a hallway
    class Hallway : public Entity {
    public:
        Hallway(int width, int height) : Entity(width, height, 'W') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a dining room 
    class DiningRoom : public Entity {
    public:
        DiningRoom(int width, int height) : Entity(width, height, 'D') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
    // class for a living room 
    class LivingRoom : public Entity {
    public:
        LivingRoom(int width, int height) : Entity(width, height, 'L') {}
        bool follows_rules(std::set<char> neighbors, std::vector<char> all_rooms) const override;
    };
}

#endif // FEATURES_HPP