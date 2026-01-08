#include "inverted_search.h"

void update_database(MainNode *HT[], FileNode **file_head)
{
    char filename[20];
    printf("Enter the filename to update: ");
    scanf("%s", filename);

    // Validate the file
    if (validate_file(filename, file_head) == FAILURE)
    {
        printf("ERROR: Invalid or duplicate file.\n");
        return;
    }

    // Read and process the new file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR: File %s cannot be opened.\n", filename);
        return;
    }
    char word[20];
    while (fscanf(fp, "%[^;]", word) == 1)
    {
        //insert at new database file

    }
    printf("INFO: Database updated successfully with file '%s'\n", filename);
}