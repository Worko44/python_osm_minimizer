
#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct	s_conf
{
  char *key;
  char **value;
  struct s_conf *next;
}		t_conf;

typedef struct	s_tag
{
  char *key;
  char *value;
}		t_tag;

typedef struct	s_info
{
  char *type;
  char *value;
  struct s_info *next;
}		t_info;

#endif
