#include "inverted_search.h"

void search(char *word, MainNode *HT[])
{
    int index;

    // Determine the bucket
    if (word[0] >= 'a' && word[0] <= 'z')
        index = word[0] - 'a';
    else if (word[0] >= 'A' && word[0] <= 'Z')
        index = word[0] - 'A';
    else if (word[0] >= '0' && word[0] <= '9')
        index = 26;
    else
        index = 27;

    MainNode *current = HT[index];

    // Traverse sorted list in the bucket
    while (current != NULL && strcmp(current->word, word) != 0)
        current = current->next;

    if (current != NULL && strcmp(current->word, word) == 0)
    {
        printf("Word \"%s\" found in following file(s):\n", word);

        SubNode *sub_current = current->sub_link;
        while (sub_current != NULL)
        {
            printf("\tfile: %s | count: %d\n", sub_current->filename, sub_current->word_count);
            sub_current = sub_current->next;
        }
    }
    else
    {
        printf("Word \"%s\" not found in the database.\n", word);
    }
}
