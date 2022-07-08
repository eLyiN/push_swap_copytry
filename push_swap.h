/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:39:12 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/01 12:02:51 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
    int *array;
    size_t  size;
    size_t  max_size;
}   t_stack;

typedef struct s_instruction
{
    char *line;
    void    *next;
    void    *prev;
}   t_instruction;

typedef struct s_state
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_instruction *instructions;
    t_instruction *last_instr;
    void    *next;
} t_state;

typedef struct s_program
{
    t_stack stack_a;
    t_stack stack_b;
    t_instruction *instr;
    int debug;
} t_program;


#endif