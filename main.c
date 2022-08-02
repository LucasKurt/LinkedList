#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *start;
    int length;
} List;

void beginInsert(List *list, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->start;
    list->start = new_node;
    list->length++;
    system("cls");
}

void endInsert(List *list, int value) {
    Node *node ,*new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if(list->start == NULL) {
        list->start = new_node;
    } else {
        node = list->start;
        while(node->next != NULL) {
            node = node->next;
        }
        node->next = new_node;
    }
    list->length++;
    system("cls");
}

void showList(List *list) {
    Node *node = list->start;
    printf("Tamanho da lista %d\n", list->length);
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n\nPressione qualquer tecla para continuar...");
    getch();
    system("cls");
}

void invertList(List *list) {
    Node *prev, *current, *next;
    prev = NULL;
    current = list->start;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->start = prev;
    printf ("Endereco do primeiro no: %x \n", &prev);
}

int main() {
    List list;
    list.start = NULL;
    list.length = 0;

    int opt, value;

    do {
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Imprimir a lista\n");
        printf("4 - Inverter a lista\n");
        printf("5 - Sair\n");

        scanf("%d", &opt);
        switch(opt) {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &value);
            beginInsert(&list, value);
            break;
        case 2:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &value);
            endInsert(&list, value);
            break;
        case 3:
            showList(&list);
            break;
        case 4:
            invertList(&list);
            showList(&list);
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        default:
            system("cls");
        }
    } while (opt != 5);

    return 0;
}

