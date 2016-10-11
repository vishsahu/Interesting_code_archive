import list;
/*Breadth first traversal in directed graph*/
public class d_graph_bfs {
    int V; // number of vertices
    list<int> *adj_list;
    public:
        void d_graph_bfs(int N); // graph constructer
        void addEdge(int U, int V); // add directed edge from U to V
        void bfs(int S); // breadth first traversal from node S
};

void d_graph_bfs::d_graph_bfs(int V){
    this->V = V;
    adj_list = new list<int>[V];
}
void d_graph::addEdge(int U, int V){
    adj_list[U].push_back(V);
}

    
        
    
    
        
        