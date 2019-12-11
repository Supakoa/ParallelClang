#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size_name_of_sushi 30

struct sushi
{
    char name[30];
    int price;
};

int main()
{
    FILE* stream = fopen("./Sushi-bar - แผ่น1.csv", "r");

    char line[1024];
    char sushi[30][23];
    int i=0;

    struct sushi* american = (struct sushi*)malloc(sizeof(struct sushi));
    american->name = {"asd"};
    printf("%s\n", american->name);

    while (fgets(line, 1024, stream))
    {
        char* token = strtok(line, ",");
        printf("%s\n", token);
        // printf("Field 3 would be %s\n", getfield(tmp, 1));
        // NOTE strtok clobbers tmp
        // free(tmp);
    }
}