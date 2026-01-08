/*
Project: Inverted Search
Author: Ismail Pasha
Module: Data Structures and Algorithms
Description: This is the main file for the Inverted Search project which creates an inverted index from multiple text files and allows searching.
*/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
    MainNode *HT[28] = {NULL};  // initialize hash table
    FileNode *file_head = NULL; // head of the file list
    MainNode *head = NULL;      // head of the main linked list 
    int choice;
    while (1)
    {
        printf("\n-------- Inverted Search --------\n");
        printf("1. Create Indexes\n");
        printf("2. Display Data\n");
        printf("3. Search Word\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                for (int i = 1; i < argc; i++)
                {
                    if (validate_file(argv[i],&file_head) == SUCCESS)
                        read_datafile(argv[i], HT);
                    else
                        printf("Skipping invalid/duplicate file: %s\n", argv[i]);
                }
                break;

            case 2:
                display_output(HT);
                break;

            case 3:
                char word[20];
                printf("Enter word to search: ");
                scanf("%s", word);
                search(word, HT); //fun call
                break;

            case 4:
                save_database(HT, &file_head);
                break;
            case 5:
                update_database(HT, &file_head);
                break;
            case 6:
				printf("Exit Done!\n");
				exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}


