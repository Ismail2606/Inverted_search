#include "inverted_search.h"

void save_database(MainNode *HT[], FileNode **file_head)
{
    FILE *fp = fopen("backup.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR: Unable to open file for writing.\n");
        return;
    }

    fprintf(fp, "#index;word;file_count;file1;count1;file2;count2;...#\n\n");
    for (int i = 0; i < 28; i++)
    {
        MainNode *mnode = HT[i];
        while (mnode != NULL)
        {
            // Count how many files contain this word
            int file_count = 0;
            SubNode *tmp = mnode->sub_link;
            while (tmp)
            {
                file_count++;
                tmp = tmp->next;
            }

            // Print in the required format:
            // #index;word;file_count;file1;count1;file2;count2;...#
            fprintf(fp, "#%d;%s;%d;", i, mnode->word, file_count);

            SubNode *snode = mnode->sub_link;
            while (snode != NULL)
            {
                fprintf(fp, "%s;%d;", snode->filename, snode->word_count);
                snode = snode->next;
            }

            fprintf(fp, "#\n"); // End of this word entry

            mnode = mnode->next;
        }
    }

    fclose(fp);
    printf("INFO: Data saved successfully in 'backup.txt'\n");
}
