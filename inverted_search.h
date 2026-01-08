#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 1
#define FAILURE 0
#define DATA_NOT_FOUND -1

typedef struct FileNode {
    char filename[20];
    int word_count;
    struct FileNode *next;
} FileNode;

typedef struct MainNode {
    char word[20];
    int file_count;
    struct SubNode *sub_link;
    struct MainNode *next;
} MainNode;

typedef struct SubNode {
    char filename[20];
    int word_count;
    struct SubNode *next;
} SubNode;

/*prototypes*/
int validate_file(char *filename, FileNode **file_head);
int txt_ext(char *filename);
int is_duplicate(FileNode *head, char *filename);
void insert_file(FileNode **head, char *filename);
void read_datafile(char *filename, MainNode *HT[]);
void display_output(MainNode *HT[]);
void create_word(char *word, char *filename, MainNode* HT[]);
void search (char *word, MainNode *HT[]);
void update_database(MainNode *HT[], FileNode **file_head);
void save_database(MainNode *HT[], FileNode **file_head);
#endif
