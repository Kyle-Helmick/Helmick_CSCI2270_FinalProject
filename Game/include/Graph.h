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
    int resources = 0;
    vector <vertex_adj> adj;
    int attack = 10;
    int def = 10;
    int health = 100;
};

class Graph
{
    public:
        Graph();
        void addEdge();
        void addVertex(string cityname);
        void print();
        virtual ~Graph();
    protected:
    private:
        vector<vertex_city> vertices;
};

#endif // GRAPH_H
