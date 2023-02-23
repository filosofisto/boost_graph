#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/property_map/property_map.hpp>
#include <iostream>
#include <string>

using boost::add_vertex;
using boost::add_edge;
using boost::adjacency_list;
using boost::vecS;
using boost::undirectedS;
using boost::directedS;
using boost::write_graphviz;
using boost::vertex_name_t;
using boost::graph_traits;
using boost::write_graphviz;
using boost::make_label_writer;
using boost::property;

using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;
using std::getline;

void sample1();
void sample2();
void sample3();

int main() {
	sample1();
	sample2();
	sample3();

	return EXIT_SUCCESS;
}

void sample1()
{
	// Define the graph type
	using Graph = adjacency_list<vecS, vecS, undirectedS>;

	// Create a graph object
	Graph g;

	// Add some nodes to the graph
	add_vertex(g);
	add_vertex(g);
	add_vertex(g);
	add_vertex(g);

	// Add some edges to the graph
	add_edge(0, 1, g);
	add_edge(0, 2, g);
	add_edge(1, 3, g);
	add_edge(2, 3, g);

	ofstream file("c:/Develop/graph1.dot");
	write_graphviz(file, g);

	cout << "Graph written to file 'graph.dot'" << endl;
	cout << "Use the bellow command to generate :" << endl;
	cout << "\tdot -Tpng graph1.dot -o graph1.png" << endl;
}

void sample2()
{
	// Define the graph type
	using Digraph = adjacency_list<vecS, vecS, directedS, property<vertex_name_t, string>>;
	using Vertex = graph_traits<Digraph>::vertex_descriptor;

	// Create a graph object
	Digraph g;

	auto vertex_name = get(boost::vertex_name, g);

	// Add some nodes to the graph
	Vertex vA = add_vertex(g); vertex_name[vA] = "SubWorkstream A";
	Vertex vB = add_vertex(g); vertex_name[vB] = "SubWorkstream B";
	Vertex vC = add_vertex(g); vertex_name[vC] = "SubWorkstream C";
	Vertex vD = add_vertex(g); vertex_name[vD] = "SubWorkstream D";

	// Add some edges to the graph
	add_edge(vA, vB, g);
	add_edge(vB, vC, g);
	add_edge(vB, vD, g);
	add_edge(vC, vD, g);

	const char* filename = "c:/Develop/graph2.dot";

	ofstream file(filename);
	write_graphviz(file, g, make_label_writer(vertex_name));
	file.close();

	cout << "Graph written to file 'graph.dot'" << endl;
	cout << "Use the bellow command to generate :" << endl;
	cout << "\tdot -Tpng graph2_with_labels.dot -o graph2.png" << endl;
}

void sample3()
{
	// Define the graph type
	using Digraph = adjacency_list<vecS, vecS, directedS>;

	// Create a graph object
	Digraph g;

	// Add some nodes to the graph
	for (int i = 0; i < 100; i++) {
		add_vertex(g);
	}

	// Add some edges to the graph
	for (int i = 0; i < 100; i+=10) {
		for (int j = i+1, k = 0; j < 100, k < 10; j++, k++) {
			add_edge(i, j, g);
		}
	}

	ofstream file("c:/Develop/graph3.dot");
	write_graphviz(file, g);

	cout << "Graph written to file 'graph3.dot'" << endl;
	cout << "Use the bellow command to generate :" << endl;
	cout << "\tdot -Tpng graph3.dot -o graph3.png" << endl;
}