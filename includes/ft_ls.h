/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define TRUE 1
# define FALSE 0
# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGLIGHT "\033[47m"
# define BGGRAY "\033[47m"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../libft/includes/libft.h"

typedef int					t_bool;

typedef struct				s_files
{
	char						*name;
	char						*link;
	struct s_files			*next;
	struct s_files			*prev;
	struct s_files			*sub_dir;
	struct stat				stat;
	time_t					mtime;
	time_t					atime;
	mode_t					st_mode;
	nlink_t					st_nlink;
	uid_t						st_uid;
	gid_t						st_gid;
	off_t						st_size;
	ino_t						st_ino;
	blkcnt_t					st_blocks;
	struct dirent			*dptr;
}								t_files;

typedef struct				s_flags
{
	t_bool					l;
	t_bool					a;
	t_bool					t;
	t_bool					sm_r;
	t_bool					lg_r;
	t_bool					f;
	t_bool					g;
	t_bool					u;
}								t_flags;

typedef struct				s_r
{
	DIR						*ds;
	struct dirent			*dptr;
	t_files					*files;
}								t_r;

typedef struct				s_start
{
	int						start;
	int						selected;
}								t_start;

typedef struct				s_lists
{
	t_files					*files;
	t_files					*tmp;
	t_files					*tmp2;
}								t_lists;

typedef struct				s_single
{
	t_files					*alist;
	struct stat				fstat;
	char						*nw_path;
}								t_single;

void							ft_foldercolorR(char *ptr);
void							ft_execcolorR(char *ptr);
void							ft_symlinkcolor(t_files *file, t_flags flags);
void							ft_init_flags(t_flags *f);
void							ft_which_flags(char *ops, t_flags *f);
void							ft_printpermissions(struct stat st);
void							ft_printinfo(struct stat st, t_flags flags);
void							ft_printtime(struct stat st, t_flags flags);
void							ft_printR(t_files *tmp, t_flags flags);
void							ft_printType(t_files *tmp, t_flags flags);
void							ft_lpb(t_files **b_lst, struct dirent *dptr, char *pwd, t_flags flags);
void							ft_list_swap(t_files **head, t_files **a, t_files **b);
void							insertionSort(t_files **head, t_flags flags);
void							sortedInsert(t_files** head, t_files* new_node);
void							sortedInsertTime(t_files** head, t_files* new_node);
void							ft_select(char *pwd, char **av, t_flags flags, int start);
void							ft_symlink_path(t_files *file, char *path, t_flags f);
void							ft_is_directory(t_files *tmp, char *curr_dir, t_flags f);
void							ft_block(char *curr_dir, t_flags flags);
void							sortedAccessTime(t_files** head, t_files* new_node);
void							sortedInsertTime(t_files** head, t_files* new_node);
void							ft_free_lst(t_files *file);
void							ft_free_lst_rvrs(t_files *file);
void							ft_free_R(t_files *file);
void							*ft_select_check(char *name);
char							*make_path_fl(char *dir, char *file);
t_start						ft_find_flags(char **options, t_flags *f);
t_files						*ft_listnew(struct dirent *ent, char *path, t_flags flags);
t_files						*reverse_lst(t_files *head);
t_files						*ft_list(char *curr_dir, t_flags flags);

#endif
