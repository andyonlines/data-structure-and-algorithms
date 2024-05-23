/*
 * @Author: andyonlines andy.gsq@qq.com
 * @Date: 2024-05-18 13:43:14
 * @LastEditors: andy andyonlines@qq.com
 * @LastEditTime: 2024-05-24 01:39:39
 * @FilePath: /data-structure-and-algorithms/list/test.c
 * @Description:
 *
 * Copyright (c) 2024 by andy, All Rights Reserved.
 */
#include <stdio.h>
#include "link_list.h"

void pri_node(void *data)
{
    int *tmp_data = (int *)data;
    printf("%d ", *tmp_data);
}

int main()
{
    link_list list;
    link_list_init(&list);
    

    int i =1;
    
    link_list_insert(&list,&i,sizeof(int),0);
    i =2;
    link_list_insert(&list,&i,sizeof(int),0);
    i=3;
    link_list_insert(&list,&i,sizeof(int),0);
    i=4;
    link_list_insert(&list,&i,sizeof(int),3);
    i=5;
    link_list_insert(&list,&i,sizeof(int),4);
    i=6;
    link_list_insert(&list,&i,sizeof(int),1);
    i=7;
    link_list_insert(&list,&i,sizeof(int),1);
    list_show(&list,pri_node);

    link_list_del(&list,1);
    list_show(&list,pri_node);
    link_list_del(&list,0);
    list_show(&list,pri_node);
    link_list_del(&list,0);
    list_show(&list,pri_node);
    link_list_del(&list,3);
    list_show(&list,pri_node);


    link_list_clear(&list);
    list_show(&list,pri_node);

    link_list_insert(&list,&i,sizeof(int),0);
    list_show(&list,pri_node);

    link_list_del(&list,0);
    list_show(&list,pri_node);


    link_list_insert(&list,&i,sizeof(int),0);
    i =2;
    link_list_insert(&list,&i,sizeof(int),0);
    i=3;
    link_list_insert(&list,&i,sizeof(int),0);
    i=4;
    link_list_insert(&list,&i,sizeof(int),3);
    i=5;
    link_list_insert(&list,&i,sizeof(int),4);
    i=6;
    link_list_insert(&list,&i,sizeof(int),1);
    i=7;
    link_list_insert(&list,&i,sizeof(int),1);
    list_show(&list,pri_node);

    int k = 99;
    link_list_get_elem(&list,1,&k,sizeof(int));
    printf("%d\n",k);

    link_list_get_elem(&list,0,&k,sizeof(int));
    printf("%d\n",k);

    link_list_get_elem(&list,6,&k,sizeof(int));
    printf("%d\n",k);
    return 0;
}
