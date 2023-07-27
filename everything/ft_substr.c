#include "../push_swap.h"

size_t  ft_strlen(const char *s)
{
    size_t x;
    
    x = 0;
    while(s[x] != '\0')
        x++;
    return(x);
}

char    *ft_strchr(const char *s, int c)
{
    char *p ;

    p = (char *)s;
    if(c == '\0')
        return(p + ft_strlen(s));
    while(*p)
    {
        if(*p == (char) c)
            return(p);
        p++;
    }
    return(NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *substring;

    i = 0;
    substring = (char *)malloc(len + 1);
    if(!s)
        return (NULL);
    if(!substring)
        return (NULL);
    while(s[start] != '\0' && ft_strlen(s) >= start && i < len)
    {
        substring[i] = s[start + i];
        i++;
    }
    substring[i] = '\0';
    return (substring);
}

void ft_str_free(char **str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}