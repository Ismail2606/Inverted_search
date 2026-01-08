#include "inverted_search.h"

int validate_file(char *filename, FileNode **file_head)
{
    // 1. Check extension
    if (txt_ext(filename) == FAILURE)
    {
        printf("ERROR: %s is not a .txt file.\n", filename);
        return FAILURE;
    }

    // 2. Check duplicate
    if (is_duplicate(*file_head, filename) == SUCCESS)
    {
        return FAILURE;
    }

    // 3. Check file open
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR: File %s cannot be opened.\n", filename);
        return FAILURE;
    }

    // 4. Check empty file
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        printf("ERROR: File %s is empty.\n", filename);
        fclose(fp);
        return FAILURE;
    }
    fclose(fp);

    // 5. Insert into file list 
    insert_file(file_head, filename);

    printf("INFO: File %s validated and added.\n", filename);
    return SUCCESS;
}
    // check .txt extension
int txt_ext(char *filename)
{
    char *dot = strrchr(filename, '.');
    if (strcmp(dot, ".txt") == 0)
        return SUCCESS;
    return FAILURE;
}

// check duplicate file
int is_duplicate(FileNode *file_head, char *filename)
{
    while (file_head != NULL)
    {
        if (strcmp(file_head->filename, filename) == 0)
            return SUCCESS;
        file_head = file_head->next;
    }
    return FAILURE;
}

// insert file into file list
void insert_file(FileNode **file_head, char *filename)
{
    FileNode *new = malloc(sizeof(FileNode));
    strcpy(new->filename, filename);
    new->next = NULL;

    
    if (*file_head == NULL)
    {
        *file_head = new;
    }
    else
    {
        FileNode *temp = *file_head;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}