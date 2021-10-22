#include <stdio.h>
#include "findPoint.h"

int main() {

    srand(time(NULL));

    int length = 5;
    Point** points = generatePoints(1, 10, 1, 10, 1, 10, length);
    printPoints(points, length);
    printf("\n");

    while (length > 1) {
        points = removePointWithLowestWeight(points, length);
        length--;

        printPoints(points, length);
        printf("\n");
    }

    printf("LAST POINT\nx: %d, y: %d, weight: %d\n", points[0]->x, points[0]->y, points[0]->weight);

    return 0;
}