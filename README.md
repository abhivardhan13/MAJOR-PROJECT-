# MAJOR-PROJECT
Disaster Relief Routing System

## Project Description

This **Disaster Relief Routing System** is designed to optimize the distribution of resources during a disaster. It models the affected regions as a graph where areas are represented as nodes, and roads connecting these areas are edges. The objective is to determine the most efficient routes for relief operations, taking into account road damage and the priority of specific areas.

### Features:
- **Graph Representation**: Areas are modeled as nodes, and roads between them are edges in the graph.
- **Priority Areas**: Some areas may need to be prioritized due to higher relief requirements, which can affect routing decisions.
- **Optimized Path Calculation**: The system uses an algorithm to find the shortest paths from an origin area to other areas, considering the priority and damage factors.

---

## How It Works

1. **Graph Model**: The areas affected by the disaster are represented as nodes in a graph. The connections between these areas are modeled as edges with associated distances (weights).
2. **Priority Levels**: Certain areas may have special priority, such as hospitals or shelters. These areas are given reduced travel distances due to their importance.
3. **Shortest Path Calculation**: The system employs an algorithm to calculate the shortest path from a designated origin area to all other areas. The calculation adjusts based on the priority levels of the areas.

### Inputs:
1. **Total Areas**: The number of areas (or nodes) in the model.
2. **Connections**: The roads (or edges) between areas, including the travel length.
3. **Priority Levels**: Areas can have different priority levels, which reduce the travel distance to those areas by a certain percentage.
4. **Origin Area**: The area from which the program calculates the shortest paths.

### Outputs:
- The system provides the shortest path from the origin area to all other areas.
- If some areas are not reachable, the program will display that those areas are unreachable.

---

## Features

- **Dynamic Graph Creation**: Users can dynamically create areas and define connections between them.
- **Handling Priority Levels**: Users can set priority levels for specific areas, which affects the pathfinding calculation.
- **Shortest Path Algorithm**: Uses a pathfinding algorithm to compute the shortest routes from the selected origin area.
- **User-Driven Input**: All parameters such as areas, connections, and priorities are provided by the user during runtime.

---

## Running the Program

### Step 1: Clone, Compile, and Run

To get started with the project, follow these steps:

1. **Clone the Repository**: Begin by cloning this repository to your local machine:

    ```bash
    git clone https://github.com/yourusername/disaster-relief-routing-system.git
    ```

2. **Compile the Code**: Navigate to the project directory and compile the code using a C++ compiler:

    ```bash
    g++ -std=c++11 -o ReliefRoutingSystem ReliefRoutingSystem.cpp
    ```

    This will generate an executable file called `ReliefRoutingSystem` (or `ReliefRoutingSystem.exe` on Windows).

3. **Run the Program**: Execute the compiled program:

    ```bash
    ./ReliefRoutingSystem
    ```

    The program will prompt you for the number of areas, connections, priority levels, and the origin area. Follow the instructions in the terminal to proceed.

---

## Sample Interaction
Here’s an example of the program's interaction with the user:
```
mathematica

Enter the number of areas: 5
Enter the number of connections: 4
Enter connection 1 (start area, end area, length): 0 1 2
Enter connection 2 (start area, end area, length): 1 2 3
Enter connection 3 (start area, end area, length): 2 3 4
Enter connection 4 (start area, end area, length): 3 4 5
Enter the number of priority levels to set: 2
Enter area index and priority level for area 2: 2 1
Enter area index and priority level for area 4: 4 3
Enter the origin area for optimized path calculation: 0
In this case, the output will show the shortest paths from Area 0 to all other areas:

mathematica

Shortest distances from origin (Area 0):
Area 0 -> Distance: 0
Area 1 -> Distance: 2
Area 2 -> Distance: 5
Area 3 -> Distance: 9
Area 4 -> Distance: 14
```
