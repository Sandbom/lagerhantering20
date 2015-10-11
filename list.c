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
  list_t *current = list;

  if(current != NULL)
    {
      while(current->next != NULL)
	{
	  current = current->next;
	}

      current->next = list_new();
      current->next->elem = elem;
      current->next->next = NULL; 
    }

  else
    {
      list =
    }
}

void list_prepend(list_t *list, int elem)
{
}



bool list_insert(list_t *list, int index, int elem)
{
  list_t *current = head;
  list_t *new = malloc(sizeof(DB_t));
  
  if(index == 1)
    {
      new->elem = elem;
      new->next = current;
    }
  
  else
    {
      for(int i = 1; i < index-1; i++)
	{
	  current = current->next;
	}
      new->next = current->next;
      current->next = new;
    }
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


  
