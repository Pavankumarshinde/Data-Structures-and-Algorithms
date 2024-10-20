/*****************************************
 * Assignment 4
 * Name:  Pavankumar Shinde
 * E-mail: co22btech11008
 * Course:  CS ID2230 graphs.
 * Submitted:    20/nov/2023
 *
 * The main driver program for project 4.
 * This program reads the file specified as the first command line
 * argument, counts the number of words, spaces, and characters and
 * displays the results in the format specified in the project description.
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10000
#define MAX_GRID_ROW 100
#define MAX_GRID_COL 100

char grid[MAX_GRID_ROW][MAX_GRID_COL];
int rows = 0, cols = 0;

struct Link
{
    int data;
    char character;
    struct Link *next;
};

struct Queue
{
    int Arr[MAX_QUEUE_SIZE];
    int head;
    int tail;
    int size;
};

// Function to print the grid
void printGrid()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print the elements in the queue
void printQueue(struct Queue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d ", queue->Arr[queue->head + i]);
    }
    puts("\n");
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int data)
{
    if (queue->size < MAX_QUEUE_SIZE && queue->size >= 0)
    {
        queue->Arr[queue->tail] = data;

        if (queue->tail < MAX_QUEUE_SIZE - 1)
        {
            queue->tail++;
        }
        else
        {
            queue->tail = 0;
        }
        queue->size++;
    }
    else
    {
        printf("Queue is full.\n");
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue)
{
    if (queue->size > 0)
    {
        if (queue->head < MAX_QUEUE_SIZE - 1)
        {
            queue->head++;
        }
        else
        {
            queue->head = 0;
        }
        queue->size--;
        return queue->Arr[queue->head - 1];
    }
    return -1; // Return a sentinel value if the queue is empty
}

// Function to create a linked list node and link it to the list
struct Link *linkThese(struct Link *x, int i, int j, char c, int cols, int rows)
{
    struct Link *ptr = (struct Link *)malloc(sizeof(struct Link));
    ptr->data = i * cols + j;
    ptr->character = c;
    ptr->next = NULL;
    if (!x)
        return ptr;
    struct Link *temp = x;
    while (x->next != NULL)
    {
        x = x->next;
    }
    x->next = ptr;
    return temp;
}

int main()
{
    // Initialize the queue
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;

    FILE *filePointer;
    filePointer = fopen("maze1.txt", "r");


    // Read the maze from the file and determine its size
    while (fgets(grid[rows], sizeof(grid[rows]), filePointer))
    {
        rows++;
    }
    cols = strlen(grid[0]) - 1;

    // Array of linked lists to represent the adjacency list
    struct Link *adjacencyList[MAX_GRID_ROW * MAX_GRID_COL];
    int start, end;

    // Construct the adjacency list for the maze
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            struct Link *x = NULL;

            if (grid[i][j] == 'S')
            {
                start = i * cols + j;
            }
            if (grid[i][j] == 'E')
            {
                end = i * cols + j;
            }

            // Create links to neighboring cells if they are not blocked by '#'
            if (i + 1 < rows && grid[i + 1][j] != '#')
            {
                x = linkThese(x, i + 1, j, grid[i + 1][j], cols, rows);
            }
            if (j < cols - 1 && grid[i][j + 1] != '#')
            {
                x = linkThese(x, i, j + 1, grid[i][j + 1], cols, rows);
            }
            if (i > 0 && grid[i - 1][j] != '#')
            {
                x = linkThese(x, i - 1, j, grid[i - 1][j], cols, rows);
            }
            if (j > 0 && grid[i][j - 1] != '#')
            {
                x = linkThese(x, i, j - 1, grid[i][j - 1], cols, rows);
            }

            adjacencyList[i * cols + j] = x;
        }
    }

    // Initialize the starting point in the queue and print the initial state
    enqueue(queue, start);
    // printQueue(queue);

    // Perform Breadth-First Search (BFS) to find the path to the exit 'E'
    while (queue->size > 0)
    {
        int forBreak = 0;
        struct Link *current = (struct Link *)malloc(sizeof(struct Link));
        int curr = dequeue(queue);

        // Skip blocked paths represented by '#'
        if (grid[curr / cols][curr % cols] == '#')
            continue;
        // Break the loop if the exit 'E' is found
        if (grid[curr / cols][curr % cols] == 'E')
            break;

        // Retrieve the linked list corresponding to the current cell
        current = adjacencyList[curr];

        // Mark the visited path with '.'
        if (curr != start)
            grid[curr / cols][curr % cols] = '.';
        // printGrid();

        // Explore neighbors and enqueue unvisited cells
        while (current != NULL)
        {
            if (current->character != '.' && current->character != 'S')
            {
                enqueue(queue, current->data);
                current->character = '.';
            }
            current = current->next;
        }

        if (forBreak)
        {
            break;
        }
    }

    // Print the final state of the queue and the grid
    // printQueue(queue);
    printGrid();

    // Close the file pointers
    fclose(filePointer);
 

    return 0;
}
