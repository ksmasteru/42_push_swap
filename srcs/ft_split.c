#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_words(char *cmd, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] == sep)
			i++;
		if (cmd[i] != sep && cmd[i])
			count++;
		while (cmd[i] != sep && cmd[i])
			i++;
	}
	return (count);
}

char	*make_words(char *str, char sep)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i = 0;
	while (str[i] && str[i] != sep)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	**ft_split(char *cmd, char sep)
{
	int		words_count;
	char	**args;
	int		i;
	int		x;

	i = 0;
	x = 0;
	words_count = count_words(cmd, sep);
    if (words_count == 0)
        return (NULL);
	args = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!args)
		return (NULL);
	while (cmd[i])
	{
		while (cmd[i] == sep && cmd[i] != '\0')
			i++;
		if (cmd[i] != '\0')
			args[x++] = make_words(cmd + i, sep);
		while (cmd[i] != sep && cmd[i])
			i++;
	}
	args[x] = NULL;
	return (args);
}

void	free_splited(char ***res, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(res[j++]);
	free(res);
}