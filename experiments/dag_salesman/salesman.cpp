#include <fstream>
#include <raylib.h>
#include <vector>
#include <cmath>
#include <string>
/*
Tracking tool for checking which areas I visit in PoE using fstream as a learning experience
*/
typedef struct WeightedGraphEdge WeightedGraphEdge;
struct Point {
    double x,y;
};

struct GraphNode {
    std::vector<WeightedGraphEdge*> connections = {};
    Point position;
};

struct WeightedGraphEdge {
    GraphNode* endNode;
    int weight;

    WeightedGraphEdge(GraphNode* node, int _weight): endNode(node), weight(_weight) {};
};


struct Graph {
    std::vector<GraphNode*> nodes;
};


std::vector<GraphNode*> distributeNodes(std::vector<GraphNode*> nodes, double radius, double centerX, double centerY) {
    int n = nodes.size();
    for (int k = 0; k < n; ++k) {
        double angle = 2.0 * M_PI * k / n;
        nodes[k]->position.x = centerX + radius * std::cos(angle);
        nodes[k]->position.y = centerY + radius * std::sin(angle);
    }
    return nodes;
}

std::tuple<std::vector<WeightedGraphEdge*>, int> getSalesmanRoute(Graph graphToTraverse) {
    
}

int main() {

    GraphNode* nodeA = new GraphNode();
    GraphNode* nodeB = new GraphNode();
    GraphNode* nodeC = new GraphNode();
    GraphNode* nodeD = new GraphNode();
    nodeA->connections.emplace_back(new WeightedGraphEdge(nodeA, 3));
    nodeA->connections.emplace_back(new WeightedGraphEdge(nodeB, 4));
    nodeA->connections.emplace_back(new WeightedGraphEdge(nodeC, 6));
    nodeA->connections.emplace_back(new WeightedGraphEdge(nodeD, 7));

    nodeB->connections.emplace_back(new WeightedGraphEdge(nodeC, 4));
    nodeD->connections.emplace_back(new WeightedGraphEdge(nodeC, 3));
    Graph graph;
    graph.nodes.push_back(nodeA);
    graph.nodes.push_back(nodeB);
    graph.nodes.push_back(nodeC);
    graph.nodes.push_back(nodeD);

    
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Traveling salesman visualisation");
    distributeNodes(graph.nodes, 100, GetScreenWidth()/2,GetScreenHeight()/2);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            for (int i=0; i<graph.nodes.size(); i++ ) {
                auto curNode = graph.nodes[i];
                DrawCircle(curNode->position.x,curNode->position.y, 50, DARKBLUE);
                for (auto con : curNode->connections) {
                    Point midpoint {
                        .x = (curNode->position.x + con->endNode->position.x) / 2, 
                        .y = (curNode->position.y+con->endNode->position.y) / 2
                    };
                    DrawLine(curNode->position.x, curNode->position.y, con->endNode->position.x, con->endNode->position.y, GRAY);
                    DrawText(std::to_string(con->weight).c_str(), midpoint.x, midpoint.y, 5, GREEN );
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
};

