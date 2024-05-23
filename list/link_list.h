/*
 * @Author: andy andyonlines@qq.com
 * @Date: 2024-05-17 22:16:44
 * @LastEditors: andy andyonlines@qq.com
 * @LastEditTime: 2024-05-24 01:28:11
 * @FilePath: /data-structure-and-algorithms/list/link_list.h
 * @Description: 单向链表的头文件
 * 
 * Copyright (c) 2024 by andy, All Rights Reserved. 
 */
#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include<stdio.h>
#include<stdlib.h>

//节点结构体
//这里data的类型为void*
//是为了模拟泛类，data可以指向任何类型
typedef struct list_node
{
    void * data;
    struct list_node * next;
} list_node;

//链表结构体
typedef struct
{
    list_node *head;
    size_t size;
}link_list;

void link_list_init(link_list *list);
void link_list_insert(link_list *list,void *data,size_t data_size,int i);
void link_list_for_each(link_list *list,void (*func)(void*));
void list_show(link_list *list,void (*func)(void*));
void del_next_node(list_node *node);
void link_list_del(link_list *list, int i);
void link_list_clear(link_list *list);
int link_list_get_elem(link_list *list, int i, void *elem,size_t data_size);
#endif