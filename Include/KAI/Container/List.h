#pragma once

#include "KAI/Base.h"

// A generic node in a List
typedef struct k_List_Node_t
{
	struct k_List_Node_t *next, *prev;
} k_List_Node;

// A generic list.
typedef struct k_List_t
{
	k_Base base;
	k_Allocator *elementAllocator;
	k_List_Node sentinel;
	k_List_Node *head, *tail;
	k_List_Node *pool;
} k_List;

extern k_Allocator k_List_Alloc;

k_List *k_List_New(int payloadSize);
k_List *k_List_New2(k_Allocator *);
void k_List_Destroy(k_List *);

int k_List_Size(k_List *);

k_List_Node *k_List_PushBack(k_List *);
k_List_Node *k_List_PushFront(k_List *);

void k_List_PopFront(k_List *);
void k_List_PopBack(k_List *);

void k_List_Delete(k_List *, k_List_Node *);
void k_List_Iterate(k_List *, void (*)(k_List_Node *));
