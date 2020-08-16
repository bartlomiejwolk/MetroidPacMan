#include "PathFinding.h"
#include "Tile.h"

USING_NS_CC;

PathFinding::PathFinding(Maze* maze) : m_Maze(maze)
{
}


PathFinding::~PathFinding()
{
}

void PathFinding::FindPath(Vec2 startPos, Vec2 endPos)
{
	MetroidPacMan::Tile* startNode = m_Maze->GridPosToTile(startPos);
	MetroidPacMan::Tile* endNode = m_Maze->GridPosToTile(endPos);

	// TODO create usings for these types
	std::vector<MetroidPacMan::Tile> openSet = { *startNode };
	std::set<MetroidPacMan::Tile> closedSet;
	
	while (openSet.size() > 0)
	{
		MetroidPacMan::Tile currentNode = openSet[0];

		// Set current node to the node from the open set that has the smallest F value.
		for (size_t i = 0; i < openSet.size(); i++)
		{
			if (openSet[i].GetFCost() < currentNode.GetFCost() || openSet[i].GetFCost() == currentNode.GetFCost() && openSet[i].HCost < currentNode.HCost)
			{
				currentNode = openSet[i];
			}
		}

		// Remove node from open set.
		openSet.erase(std::remove(begin(openSet), end(openSet), currentNode), end(openSet));

		// Add current node to closed set.
		closedSet.insert(currentNode);

		if (currentNode == *endNode)
		{
			return;
		}
	}
}