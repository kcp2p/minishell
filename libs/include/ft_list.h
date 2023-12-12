/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krchuaip <krittin@42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:23:11 by krchuaip          #+#    #+#             */
/*   Updated: 2023/12/12 19:23:12 by krchuaip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_list_bi
{
	void				*content;
	struct s_list_bi	*prev;
	struct s_list_bi	*next;
}						t_list_bi;

/* list */
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

size_t		ft_lstsize(t_list *lst);

/* list bidirectional */
t_list_bi	*ft_lstnew_bi(void *content);
t_list_bi	*ft_lstpop_bi(t_list_bi **lst);
t_list_bi	*ft_lstlast_bi(t_list_bi *lst);

void		ft_lstadd_front_bi(t_list_bi **lst, t_list_bi *new);
void		ft_lstadd_back_bi(t_list_bi **lst, t_list_bi *new);
void		ft_lstdelone_bi(t_list_bi **lst, void (*del)(void *));
void		ft_lstclear_bi(t_list_bi **lst, void (*del)(void *));
void		ft_lstiter_bi(t_list_bi *lst, void (*f)(void *));

size_t		ft_lstsize_bi(t_list_bi *lst);

#endif //FT_LIST_H
