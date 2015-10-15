
#ifndef _PROTO_H_
#define _PROTO_H_

t_info	*recup_info(char *line);
char	*recup_info_type(t_info *info, char *type);
void	free_info(t_info *info);
t_conf *read_file_conf(char *path);
void free_conf(t_conf *conf);
int	calc_size_value(char *buff);
char **free_tab(char **tab);
char **add_in_tab(char **tab, char *add);
char *kill_space(char *line);
type_osm recup_type(char *line);


#endif
