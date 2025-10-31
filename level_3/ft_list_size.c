/* Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; */

#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

/**
 * @brief Conta o número de elementos em uma lista encadeada.
 *
 * A função percorre uma lista encadeada simples, contando quantos nós existem
 * até que o ponteiro `next` de um nó seja NULL (fim da lista).
 *
 * 🧩 Lógica visual:
 * ┌─────────────┐     ┌─────────────┐     ┌─────────────┐
 * │ "Primeiro"  │ --> │ "Segundo"   │ --> │ "Terceiro"  │ --> NULL
 * └─────────────┘     └─────────────┘     └─────────────┘
 *
 * Iterações:
 * 1ª → conta n1  
 * 2ª → conta n2  
 * 3ª → conta n3  
 * 4ª → begin_list == NULL → fim do loop  
 * Resultado final: i = 3
 *
 * @param begin_list Ponteiro para o primeiro elemento (nó) da lista.
 * @return O número total de nós (tamanho da lista).
 *
 * @example
 * // Cria uma lista com 3 nós encadeados:
 * t_list *n1 = malloc(sizeof(t_list));
 * t_list *n2 = malloc(sizeof(t_list));
 * t_list *n3 = malloc(sizeof(t_list));
 * n1->next = n2; n2->next = n3; n3->next = NULL;
 *
 * int size = ft_list_size(n1); // Retorna 3
 */
int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return i;
}

int main(void)
{
	t_list *n1 = malloc(sizeof(t_list));
	t_list *n2 = malloc(sizeof(t_list));
	t_list *n3 = malloc(sizeof(t_list));

	n1->data = "Primeiro";
	n2->data = "Segundo";
	n3->data = "Terceiro";

	// Encadeando os nós
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	printf("Tamanho da lista: %d\n", ft_list_size(n1));

	// Liberando memória
	free(n1);
	free(n2);
	free(n3);

	return 0;
}