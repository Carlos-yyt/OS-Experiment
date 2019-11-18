#include "header.h"

PCBNode::PCBNode(){

}

PCBNode::PCBNode(PCB _pcb,int _next)
{
    pcb=_pcb;
    next=_next;
}
