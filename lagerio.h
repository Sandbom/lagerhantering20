/// Valideringsfunktinoen tar emot en pekare till
/// data och kontrollerar om datat kan omvandlas till avsedd typ.
/// Exempel:
/// - valid_int
/// - valid_shelf
typedef bool (*v_f) (char *);

/// Konstruktor som tar emot en sträng med validerat data
/// och omvandlar det till avsedd typ, returnerar en pekare
/// till det nya datat.
/// Exempel:
/// str_to_int
/// str_to_shelf
typedef *(*m_f)(char *);

typedef struct shelf shelf_t;

// Prints q and return answer as string.
char *ask_question_string(char *q);

//Prints q and return answer as integer.
int ask_int_question(char *q);

//
int read_int(bool rep);

//
bool is_valid_int(char *str);

//
char *read_string(bool s_n);

//
char *read_string_with_buffer(char *buf, size_t len, bool s_n);

//
shelf_t ask_shelf_question(void);

//
void *ask_question(char *q, v_f v, m_f co, bool cl);

//
bool valid_shelf(char *input);



