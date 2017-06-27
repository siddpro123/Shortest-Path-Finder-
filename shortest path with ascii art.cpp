#include<iostream>
#include <fstream>
using namespace std;
#include <string>


//Shortest Path 
#ifndef _bool_it
typedef unsigned char bool_it;
bool_it false_it = 0;
bool_it true_it = 1;
#endif


int sizee[10 + 1] = { 0 };
char result[25][80];
int arr[100][100] = { 0 };



// A C++ program for Dijkstra's single source shortest path algorithm
// It also shows representation of the graph.

//Source
int src = 0;
// Max Number of vertices in the graph
#define V 10

int returnVertics()
{
	int count = 0;
	for (int i = 1; i <= 10;i++)
		if (sizee[i] != 0)
			count++;
	return count;
}







// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree
int minDistance(int dist[], bool_it sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	int NVertices = returnVertics();
	for (int v = 0; v <= NVertices; v++)
		if (sptSet[v] == false_it && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j)
{
	// Base Case : If j is source
	if (parent[j] == -1 || parent[j]  < 0)
		return;

	printPath(parent, parent[j]);

	cout << j << " ";
}

// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[])
{
	cout << "Vertex\t\tWeight\t\tPath";
	int NVertices = returnVertics();
	for (int i = 1; i <= NVertices; i++)
	{
		if (dist[i] > 300 || dist[i]<0)	cout << "\n" << src << " -> " << i << "\t\t " << "No Path" << "\t" << "No Path" << " ";
		else
		{
			cout << "\n" << src << " -> " << i << "\t\t " << dist[i] << "\t\t" << src << " ";
			printPath(parent, i);
		}


	}
	return 0;
}

// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V])//, int src)
{
	int dist[V];  // The output array. dist[i] will hold
				  // the shortest distance from src to i

				  // sptSet[i] will true_it if vertex i is included / in shortest
				  // path tree or shortest distance from src to i is finalized
	bool_it sptSet[V];

	// Parent array to store shortest path tree
	int parent[V];

	// Initialize all distances as INFINITE and stpSet[] as false_it
	int NVertices = returnVertics();
	for (int i = 0; i <= NVertices; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false_it;
	}

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices

	for (int count = 0; count < NVertices - 1; count++)
	{
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to src
		// in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true_it;

		// Update dist value of the adjacent vertices of the
		// picked vertex.

		for (int v = 0; v <= NVertices; v++)

			// Update dist[v] only if is not in sptSet, there is
			// an edge from u to v, and total weight of path from
			// src to v through u is smaller than current value of
			// dist[v]
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed distance array
	printSolution(dist, NVertices + 1, parent);
	cout << "\n\n";
}


bool isPresent(int x)
{
	for (int i = 1; i <= 10; i++)
	{
		if (sizee[i] == x)
			return true;
	}
	return false;
}



void SetVertex()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)	result[i][j] = ' ';
	}
	int count = returnVertics();
	int i = 1, j = 1;
	int inc = 1;
	while (i <= count * 5)
	{
		result[i][j - 1] = '[';

		result[i][j] = inc + 48;
		inc += 1;
		result[i][j + 1] = ']';
		i += 5;
		j += 10;
	}

}

void setLines()
{
	int i = 1, j = 1;
	int count = returnVertics();
	int weight;
	for (i = 1; i <= count && arr[i][1] != 0; i++)
	{
		int u = arr[i][1];
		for (j = 2; j < 80 && arr[i][j] != 0; j += 2)
		{
			int adj = arr[i][j];
			weight = arr[i][j + 1];
			int number = weight;
			int digits = 0; while (number != 0) { number /= 10; digits++; }
			if (u < adj)
			{
				int row = ((u - 1) * 5) + 1;//row no.
				int start = ((u - 1) * 10) + 3;//((u - 1) * 5) + 3;// col no.
				int a;
				for (a = start; a <= start + (adj - u) * 9; a++)//((start-1) +(adj-1)*10)-2
				{
					if (result[row][a] == ' ')
						result[row][a] = '-';
					if ((result[row][a] == '|'))
						result[row][a] = '=';
				}
				a--;
				result[row][a] = '+';

				start = row + 1;
				for (int b = start; b <= ((adj - 1) * 5); b++)
				{

					if (b == ((adj - 1) * 5) - 1)//at last

					{//result[b][a] = weight + 48;

						int county = 1;
						a--;
						int score = weight;
						int div;
						for (div = 1; div <= score; div *= 10);

						do
						{
							div /= 10;
							result[b][++a] = (score / div) + 48;

							score %= div;
							county++;
						} while (county <= digits);

						a = a - digits + 1;

					}

					else if (b == ((adj - 1) * 5))//at last
						result[b][a] = 'V';
					else result[b][a] = '|';
				}

			}
			else if (u > adj)
			{
				int row = ((u - 1) * 5) + 1;//row no.
				int start = ((u - 1) * 10);//((u - 1) * 5) + 3;// col no.
				int a;

				for (a = start; a >= start - (u - adj) * 9; a--)//((start-1) +(adj-1)*10)-2
				{
					if (result[row][a] == ' ')
						result[row][a] = '-';
					if ((result[row][a] == '|'))
						result[row][a] = '=';
				}
				result[row][a] = '+';



				start = row - 1;
				for (int b = start; b >= start - ((u - adj) * 5 - 2); b--)//((adj - 1) * 5)
				{
					if (b == start - ((u - adj) * 5 - 2) + 1)//at secondlast
					{//result[b][a] = weight + 48;

						int county = 1;
						a--;
						int score = weight;
						int div;
						for (div = 1; div <= score; div *= 10);

						do
						{
							div /= 10;
							//cout << score / div << endl;
							result[b][++a] = (score / div) + 48;

							score %= div;
							county++;
						} while (county <= digits);

						a = a - digits + 1;

					}

					else if (b == start - ((u - adj) * 5 - 2))//at last
						result[b][a] = '^';
					else result[b][a] = '|';
				}

			}



		}

	}
}

void main()
{
	string line;
	string buffer;
	ifstream graphFile("graph.dat");

	if (graphFile.is_open())
	{
		int Iindex = 1, Jindex = 1;

		while (getline(graphFile, line))
		{
			Jindex = 1;
			int inc = 0;

			while (line[inc] != '\0')
			{
				while (line[inc] != '\0' && line[inc] != ' ')
					buffer += line[inc++];

				arr[Iindex][Jindex++] = stoi(buffer);
				buffer = "";
				if (line[inc] != '\0')
					inc++;
			}

			Iindex++;
		}

		graphFile.close();
	}

	int a = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (!isPresent(arr[i][1]))
			sizee[a++] = arr[i][1];
		for (int j = 1; j <= 7; j++)
		{
			if (j != 1 && j % 2 == 0)
			{
				if (!isPresent(arr[i][j]))
					sizee[a++] = arr[i][j];
			}


		}

	}

	SetVertex();

	setLines();
	cout << "\t\t---------------------------------------------" << endl;
	cout << "\t\tAN ASCII ART IMAGE OF THE GRAPH ON THE SCREEN" << endl;
	cout << "\t\t---------------------------------------------" << endl;

	cout << "\n\n\t\tTOTAL VERTICES:" << returnVertics() << endl << endl << endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
			cout << result[i][j];
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------";
	cout << "--------------------------------------------------------------------------------";



	int graph[V][V];

	for (int i = 0; i <= returnVertics(); i++)
	{
		for (int j = 0; j <= returnVertics(); j++)
		{
			graph[i][j] = 0;
		}
	}

	for (int i = 1;i <= returnVertics()+1;i++)
	{
		for (int j = 1;j <= returnVertics() + 2;j++)
		{
			if (j != 1)
			{
				graph[arr[i][1]][arr[i][j]] = arr[i][j + 1];
				j++;
			}
		}
	}

	cout << "\t\t---------------------------------------------" << endl;
	cout << "\t\tSHORTEST PATH OF THE GRAPH WITH DIJKSTRA ALGO" << endl;
	cout << "\t\t---------------------------------------------" << endl;

	cout << "\n--------------------------------------------------------------------------------";
	for (int i = 1; i <= returnVertics(); i++)
	{
		src = i;
		dijkstra(graph);
		cout << "--------------------------------------------------------------------------------";
	}
	cout << "--------------------------------------------------------------------------------";


}