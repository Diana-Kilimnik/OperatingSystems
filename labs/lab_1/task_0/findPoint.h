#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int weight;
} Point;

Point** generatePoints(int weightFrom, int weightTo, int xFrom, int xTo, int yFrom, int yTo, int length);
void printPoints(Point** points, int length);
int randomIntNumberInRange(int from, int to);
int indexPointLowestWeight(Point** points, int length);
int findClosestPointIndex(Point** points, int length, int indexPointFrom);
Point** removePointWithLowestWeight(Point** points, int length);