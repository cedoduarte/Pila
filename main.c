#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *up;
    Node *down;
};

int main(void)
{
    // variables
    Node *top;
    Node *bottom;
    Node *iNode;
    Node *cNode;
    int i;

    // proceso
    top = (Node *) malloc(sizeof(Node));
    iNode = top;
    iNode->down = NULL;
    for (i = 0; i < 10; ++i) {
        iNode->value = i;
        iNode->up = (Node *) malloc(sizeof(Node));
        top = iNode->up;
        bottom = iNode;
        iNode = top;
        iNode->down = bottom;
    }
    top = bottom;
    top->up = NULL;

    // salida por pantalla
    iNode = top;
    while (iNode != NULL) {
        printf("%d\n", iNode->value);
        iNode = iNode->down;
    }

    // libera memoria
    iNode = top;
    while (iNode != NULL) {
        cNode = iNode->down;
        free(iNode);
        iNode = cNode;
    }
    return 0;
}

