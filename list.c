//list.c
typedef struct shelf {
  char row;   // A-Z
  int column; // 0-99
} shelf_t;

typedef struct list {
  struct shelf shelf;
  struct list *next;
} list_t;


list_t *list_new()
{
  list_t *list = malloc(sizeof(list_t));
  return list;
}

void list_append(list_t *list, int elem)
{
  
}

void list_prepend(list_t *list, int elem)
{
}

bool list_insert(list_t *list, int index, int elem)
{
  return true;
}

bool list_remove(list_t *list, int index, int *elem)
{
  return true;
}

int *list_get(list_t *list, int index)
{
  return -1;
}
int *list_first(list_t *list)
{
  return -1;
}

int *list_last(list_t *list)
{
  return -1;
)

int list_length(list_t *list)
{
  return -1;
}
