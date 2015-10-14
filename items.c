#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include items.h


struct item{  
  char *name;
  char *desc;
  int price;
  int amount;
};

char *itemname(item_t *item){
  return item->name;
}

char *itemdesc(item_t *item){
  return item->desc;
}

char itemprice(item_t *item){
  return item->price;
}

char itemamount(item_t *item){
  return item->amount;
}
