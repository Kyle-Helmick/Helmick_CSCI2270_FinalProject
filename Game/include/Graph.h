#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct vertex_city;

struct vertex_adj
{
    vertex_city *v;
};

struct vertex_city
{
    string name;
    bool p_controlled = false;
    bool visited = false;
    int resources = 10;
    vector <vertex_adj> adj;
    int attack;
    int def;
    int health = 100;
    int ID;
    int aggression;
};

class Graph
{
    public:
        Graph();
        void addEdge();
        void addVertex(string cityname);
        bool findecity(string p_city, string e_city);
        bool findpcity(string city_name);
        void print();
        void print_p();
        void print_p_adj(string name);
        void attack(string attack, string def);
        void fortify(string city);
        void resources(string from, string to, int amount);
        void pwait();
        void ewait(string city);
        void turnresources();
        bool resourcecheck(string city, int amount);
        void AIturns();
        int genRand();
        bool win_check();
        bool lose_check();
        int genRand2(int adjsize);
        ~Graph();
    protected:
    private:
        vector<vertex_city> vertices;
};

#endif // GRAPH_H
