#include "inverted_search.h"

void display_output(MainNode* HT[])
{
    for(int i=0; i<28; i++)
    {
        MainNode *cur = HT[i];
        while(cur)
        {
            printf("Word: %s | File(s): %d\n", cur->word, cur->file_count);
            SubNode *sub = cur->sub_link;
            while(sub)
            {
                printf("\tFile: %s | Count: %d\n", sub->filename, sub->word_count);
                sub = sub->next;
            }
            cur = cur->next;
        }
    }

}
