/*
 * @Author: andyonlines andy.gsq@qq.com
 * @Date: 2024-05-18 13:43:14
 * @LastEditors: andy andyonlines@qq.com
 * @LastEditTime: 2024-05-24 01:37:13
 * @FilePath: /data-structure-and-algorithms/list/link_list.c
 * @Description: 单向链表的实现
 *
 * Copyright (c) 2024 by andy, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link_list.h"

/**
 * @description: 初始化链表
 * @return {*}
 */
void link_list_init(link_list *list)
{
    list->head = (list_node *)malloc(sizeof(list_node));
    list->head->next = NULL;
    list->size = 0;
}

/**
 * @description: 向链表指定位置添加数据
 * @param {link_list} *list 添加数据的链表
 * @param {void} *data 添加的数据
 * @param {size_t} data_size 添加数据的大小（字节）
 * @param {int} i  插入数据的位置
 * @return {*}
 */
void link_list_insert(link_list *list, void *data, size_t data_size, int i)
{
    // 插入的位置大于链表的大小
    if (i > list->size)
    {
        return;
    }
    else
    {
        // 申请一个node并初始化
        list_node *new_node = (list_node *)malloc(sizeof(list_node));
        new_node->data = malloc(data_size);
        new_node->next = NULL;

        // 把data的值复制到data指针指向的内存
        memcpy(new_node->data, data, data_size);
        // 查找插入位置
        list_node *tmp_node = list->head;
        for (int k = 0; k < i; k++)
        {
            tmp_node = tmp_node->next;
        }

        // 将新节点插入到链表中
        new_node->next = tmp_node->next;
        tmp_node->next = new_node;
        list->size++;
    }
}

/**
 * @description: 遍历链表
 * @param {link_list} *list
 * @param {void (*)(void *)} func
 * @return {*}
 */
void link_list_for_each(link_list *list, void (*func)(void *))
{
    for (list_node *node = list->head->next; node != NULL; node = node->next)
    {
        func(node->data);
    }
}

/**
 * @description: 显示链表
 * @param {link_list} *list
 * @return {*}
 */
void list_show(link_list *list, void (*func)(void *))
{
    printf("list:{");
    link_list_for_each(list, func);
    printf("},size: %zu\n", list->size);
}

/**
 * @description: 删除下一个节点
 * @param {list_node} *node 需要删除节点的上一个节点
 * @return {*}
 */
void del_next_node(list_node *node)
{
    if (node != NULL && node->next != NULL)
    {
        // 获取需要删除的节点
        list_node *tmp_node = node->next;

        // 断开链接
        node->next = tmp_node->next;

        // 释放删除节点的空间
        free(tmp_node->data);
        free(tmp_node);
    }
}

/**
 * @description: 删除指定位置的节点
 * @param {link_list} *list
 * @param {int} i
 * @return {*}
 */
void link_list_del(link_list *list, int i)
{
    if (i < list->size)
    {
        list_node *tmp_node = list->head;

        // 找出需要删除节点的前一个节点
        for (int k = 0; k < i && tmp_node != NULL; k++)
        {
            tmp_node = tmp_node->next;
        }

        del_next_node(tmp_node);
        list->size--;
    }
}

/**
 * @description: 清除链表
 * @param {link_list} *list
 * @return {*}
 */
void link_list_clear(link_list *list)
{
    while (list->head->next != NULL)
    {
        del_next_node(list->head);
        list->size--;
    }
}

int link_list_get_elem(link_list *list, int i, void *elem,size_t data_size)
{
    if (list->head->next != NULL && elem != NULL)
    {
        list_node *tmp = list->head->next;
        for (int k = 0; k < i && tmp->next != NULL; k++)
        {
            tmp = tmp->next;
        }

        memcpy(elem, tmp->data, data_size);
        // int k = *((int*)(tmp->data));
        // printf("%d\n",k);
        return 0;
    }
    return 1;
}