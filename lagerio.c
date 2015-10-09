// Code taken from Tobias Wrigstad IOOPM-15 föreläsning10.pdf
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "lagerio.h"

#define STRIP_NEWLINE true

#define Ask_int(q) ask_question(q, valid_int, str_to_int, true)
#define Ask_str(q) ask_question(q, NULL,      str_to_str, false)




struct shelf{
  char name; // A-Z
  int number; // 0-99
}

char *ask_question_string(char *question)
{
  puts(question);
  return read_string();
}


int ask_int_question(char * question)
{
  puts(question);
  return read_int();
}


int read_int(bool repeat_until_valid_int)
{
  char *buf = alloca(16);
  int len = 16;

  do {
    buf = read_string_with_buffer(buf, len, STRIP_NEWLINE);
  } while (repeat_until_valid_int && is_valid_int(buf) == false);
 
  return atol(buf);
}


bool is_valid_int(char *str)
{
  bool valid_int = true;

  for (char *c = str; *c && valid_int; ++c)
    {
      valid_int = isdigit(*c);
    }
  return valid_int;
}


char *read_string(bool strip_newline)
{
  return read_string_with_buffer(NULL, 0, STRIP_NEWLINE);
}

char *read_string_with_buffer(char *buf, size_t len, bool strip_newline)
{
  ssize_t read = getline(&buf, &len, stdin);
  if(read > 0 && strip_newline)
    {
      buf[read-1] = '\0';
    }
  return buf;
}

shelf_t ask_shelf_question()
{
  return *ask_question("Mata in hyllplats (tecken följt av siffra 0-99)",
		       valid_shelf,
		       str_to_shelf,
		       true);
}

void *ask_question(char *q, v_f validate, m_f convert, bool cleanup)
{
  //Ask question until optional validation of input is satisfied.
  char *input = NULL;

  do {
    puts(q);
    if (input) free(input);
    input = read_string();
  } while (validate && validate(input) == false);
  
  //If a conversion function was specified, convert input.
  void *result = convert ? convert(input) : input;

  if(cleanup) free(input);
  return result;  
}

bool valid_shelf(char *input)
{
  return strlen(input) == 3 && isalpha(input[0]) && valid_int(input+1);
}

shelf_t *str_to_shelf(char *input)
{
  shelf_t *shelf = malloc(sizeof(shelf_t));
  shelf->name = input[0];
  shelf->number = atol(input+1);
  return shelf;
}

int main(int argc, char *argv[])
{
  
  return 0;
}
