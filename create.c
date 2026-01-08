
#include "inverted_search.h"

void read_datafile(char *filename, MainNode *HT[])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR: File %s cannot be opened.\n", filename);
        return;
    }

    char word[20];
    while (fscanf(fp, "%s", word) == 1)
    {
        create_word(word, filename, HT);   
    }

    fclose(fp);
}

void create_word(char *word, char *filename, MainNode *HT[]) 
{
    // create indexes for each character
	int index;
	if(word[0]>='a' && word[0]<='z')
		index=word[0]-'a';
	else if(word[0]>='A' && word[0]<='Z')
		index=word[0]-'A';
	else if(word[0]>='0' && word[0]<='9')
		index=26;
	else
		index=27;
	
	MainNode *current = HT[index];
	MainNode *prev = NULL;
	// Traverse to find the correct position or existing word
	while (current != NULL && strcmp(current->word, word) != 0)
	{
		prev = current;
		current = current->next;
	}
	// If word already exists, update its sublist
	if (current != NULL && strcmp(current->word, word) == 0)
	{
		SubNode *sub_current = current->sub_link;
		SubNode *sub_prev = NULL;
		// Traverse sublist to find the file
		while (sub_current != NULL && strcmp(sub_current->filename, filename) != 0)
		{
			sub_prev = sub_current;
			sub_current = sub_current->next;
		}
		// If file found, increment word count
		if (sub_current != NULL && strcmp(sub_current->filename, filename) == 0)
		{
			sub_current->word_count++;
		}
		else // Insert new file node
		{
			SubNode *new_sub = malloc(sizeof(SubNode));
			strcpy(new_sub->filename, filename);
			new_sub->word_count = 1;
			new_sub->next = sub_current;
			if (sub_prev == NULL)
			{
				current->sub_link = new_sub;
			}
			else
			{
				sub_prev->next = new_sub;
			}
			current->file_count++;
		}
	}
	else // Insert new main node
	{
	    MainNode *new_node = malloc(sizeof(MainNode));
        strcpy(new_node->word, word);
        new_node->file_count = 1;
        new_node->next = current;

        // Create first subnode
        SubNode *new_sub = malloc(sizeof(SubNode));
        strcpy(new_sub->filename, filename);
        new_sub->word_count = 1;
        new_sub->next = NULL;
        new_node->sub_link = new_sub;

        if (prev == NULL)
            HT[index] = new_node;
        else
            prev->next = new_node;
    }
}




