#include "osmMinimizer.h"

type_osm recup_type(char *line)
{
  int i = 0;
  char *tab_type[10] = {"?xml", "osm", "bounds", "node", "tag", "way", "nd", "relation", "member", NULL};
  type_osm tab_enum[10] = {TYPE_XML, TYPE_OSM, TYPE_BOUNDS, TYPE_NODE, TYPE_TAG, TYPE_WAY, TYPE_ND, TYPE_RELATION, TYPE_MEMBER};
  int n = 0;
  type_osm end = NO_TYPE;

  if (line[i] == '<')
    {
      i++;
      if (line[i] == '/')
	{
	  end = END_TYPE;
	  i++;
	}
      while (tab_type[n] != NULL)
	{
	  if (my_strncmp(&line[i], tab_type[n], my_strlen(tab_type[n])) == 0)
	    {
	      return (tab_enum[n] + end);
	    }
	  n++;
	}
    }
  return (NO_TYPE);
}

char *kill_space(char *line)
{
  int i = 0;
  int deb = 0;
  int end = 0;
  char save;

  while (line[i] == ' ' || line[i] == '\t')
      i++;
  deb = i;
  i = my_strlen(line) - 1;
  if (i < 0)
    return (my_strdup(line));
  while (line[i] == ' ' || line[i] == '\t')
      i--;
  end = i;
  save = line[end + 1];
  line[end + 1] = 0;
  char *line_clean = my_strdup(&line[deb]);
  line[end + 1] = save;
  return (line_clean);
}

