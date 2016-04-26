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
    string namecat;
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
        void addVertex(string);
        bool findecity(string, string);
        bool findpcity(string);
        void print();
        void print_p();
        void print_p_adj(string);
        void fortify(string);
        void resources(string, string, int);
        void pwait();
        void ewait(string city);
        bool resourcecheck(string, int);
        void AIturns();
        int genRand();
        bool win_check();
        bool lose_check();
        int genRand2(int);
        int vertexAttack(vertex_city, vertex_city);
        void checkTakeover(string, string);
        vertex_city &returncity(string);
        void playerattack(string, string);
        ~Graph();
    protected:
    private:
        vector<vertex_city> vertices;
};

#endif // GRAPH_H
