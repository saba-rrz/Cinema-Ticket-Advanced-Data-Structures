#pragma once
#include "Film.h"
#include <cstddef>
class Node
{
public:
    Film data;
    Node* next;
    Node(Film data); 
};

