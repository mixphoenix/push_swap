#include "../push_swap.h"

void    ft_free_strs(char **strs, int i)
{
    int j;

    j = 0;
    while(j < i)
        free(strs[j++]);
    free(strs);
}

int ft_getsize(const char *str, char c)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (str[i])
    {
        if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
            size++;
        i++;
    }
    return (size);
}

int ft_getlen_word(const char *s, char c)
{
    int i;

    i = 0;
    while(s[i] != c && s[i] != '\0')
        i++;
    return (i);
}

int ft_addstr(char **strs, const char *s, char c, int i)
{
    int j;
    int len_word;

    j = 0;
    while (s[j] && s[j] == c)
        j++;
    len_word = ft_getlen_word((s + j), c);
    strs[i] = malloc(sizeof(char) * (len_word + 1));
    if (!strs[i])
        return (0);
    strs[i] = ft_substr(s, j, len_word);
    return (j + len_word);
}

char    **ft_split(char const *s, char c)
{
    char    **strs;
    int     n_words;
    int     i;
    int     pos;
    int     tmp;

    n_words = ft_getsize(s, c);
    strs = malloc(sizeof(char *) * (n_words + 1));
    if (!strs)
        return (NULL);
    i = 0;
    pos = 0;
    while (i < n_words)
    {
        tmp = ft_addstr(strs, s + pos, c, i);
        if (!tmp)
        {
            ft_free_strs(strs, i);
            return (NULL);
        }
        pos += tmp; 
        i++;
    }
    strs[i] = 0;
    return (strs);
}