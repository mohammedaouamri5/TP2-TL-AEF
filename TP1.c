#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Word {
  int index;
  int lenght;
  int count;
  struct Word *Next;
};

int IsWord(struct Word *word, char *content, int __index, int __lenght);

struct Word *Inser(struct Word *p_head, int index, int length, char *content) {
  if (p_head == NULL) {
    struct Word *word = (struct Word *)malloc(sizeof(struct Word));
    word->index = index;
    word->lenght = length;
    word->count = 1;
    word->Next = NULL;
    return word;
  }

  struct Word *temp = p_head;
  while (temp->Next != NULL) {
    if (IsWord(temp, content, index, length)) {
      temp->count++;
      return p_head;
    }
    temp = temp->Next;
  }

  struct Word *word = (struct Word *)malloc(sizeof(struct Word));
  word->index = index;
  word->lenght = length;
  word->count = 1;
  word->Next = NULL;
  temp->Next = word;
  return p_head;
}

void PrintWord(int __start, int __end, char *file) {
  for (int i = __start; i < __end; i++) {
    putchar(file[i]);
  }
}

void PRINT(struct Word *p_head, char *content) {
  for (struct Word *temp = p_head; temp != NULL; temp = temp->Next) {
    printf("Word : ");
    PrintWord(temp->index, temp->index + temp->lenght, content);
    printf("\n");
    printf("Count : %d\n", temp->count);
    printf("lenght : %d\n", temp->lenght);
    printf("index : %d\n", temp->index);
    printf("\n***************\n");
  }
}

char *ReadFile(char *filename) {
  FILE *input = fopen(filename, "rb");
  fseek(input, 0, SEEK_END);                // TO END
  int size = ftell(input);                  // GET THE SIZE
  fseek(input, 0, SEEK_SET);                // TO THE BEGINNING
  char *content = (char *)malloc(size + 1); // +1 for the null terminator
  size_t bytesRead = fread(content, 1, size, input);
  fclose(input);
  return content;
}

int IsSeperator(char c) {
  return c == '\t' || c == ' ' || c == '\n' || c == '\r' || c == ',' ||
         c == '.' || c == '!' || c == '?' || c == ';' || c == ':' || c == EOF ;  
}

int GetNextWord(char *content, int *__index, int *__start, int *__end) {
  for (*__start = *__index; (*__index) == 0 || !IsSeperator(content[*__index]);
       (*__index)++) {
  }
  for (*__end = *__index; IsSeperator(content[*__index]); (*__index)++) {
  }
  return *__index;
}

int IsWord(struct Word *word, char *content, int __index, int __lenght) {
  if (word == NULL) {
    return FALSE;
  }
  if (word->lenght != (__lenght)) {
    return FALSE;
  }
  for (int i; i <= word->lenght; i++) {
    if (content[i + __index] != content[i + word->index]) {
      return FALSE;
    }
  }
  return TRUE;
}

enum STATE {
  ERROR,
  START,
  LOOP_LETER,
  LOOP_NUMBER,
};

int is_number(char c) { return c >= '0' && c <= '9'; }
int is_letter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

enum STATE type(char *c, int *__index, enum STATE state) {
  // printf("[%c]\n", c[*__index]);
  if (IsSeperator(c[(*__index)])) {
    return state;
  }

  if (state == START) {
    if (is_number(c[(*__index)])) {
      *__index += 1;
      return type(c, __index, LOOP_NUMBER);
    } else if (is_letter(c[*__index])) {
      *__index += 1;
      return type(c, (__index), LOOP_LETER);
    }
  }

  if (state == LOOP_LETER) {
    if (is_number(c[*__index]) || is_letter(c[(*__index)])) {
      *__index += 1;
      return type(c, __index, LOOP_LETER);
    }
  }

  if (state == LOOP_NUMBER) {
    if (is_number(c[*__index])) {
      *__index += 1;
      return type(c, __index, LOOP_NUMBER);
    }
  }

  return ERROR;
}

int main(int argc, char *argv[]) {
  char *file = ReadFile(argv[1]);
  printf("%s", file);
  printf("\n------------------------------------\n");
  int is_start = TRUE;
  enum STATE state = START;
  for (int __index = 0, __end = 0; file[__index]; __index++) {
    printf("****\n"); 

    for (; IsSeperator(file[__index]); __index++) {
    }
    __end = __index;
    enum STATE state = START;
    state = type(file, &__end, state);
    for (; IsSeperator(file[__end]); __end++) {}

    {
      printf("%s\n", state == ERROR ? "ERROR" : "OK");
      printf("Word : [");
      PrintWord(__index, __end, file);
      printf("]\n%s\n", state == LOOP_LETER ? "KEY_WORD" : "NUMBER");
      __index = __end - 1; 
    }
  }
  return 0;
}
