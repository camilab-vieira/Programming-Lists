#ifndef B_CPP
#define B_CPP

#include "b.h"

Link* createLink(int a, int b, int c){
    Link *link;
    link = new Link;
    link->num = a;
    link->alg = b;
    link->bla = c;
    return link;
}

#endif