#ifndef ENV_h
#define ENV_H

char *_getenv(const char *name);
void get_path(void);
char **get_path_arr(void);

struct node
{
	char *dir;
	struct node *next;
};
struct node *linked_path(void);

#endif
