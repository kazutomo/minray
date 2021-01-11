#ifndef NEIGHBOR_LIST_A_H
#define NEIGHBOR_LIST_A_H

#define NEIGHBOR_SIZE 11

typedef struct{
  int list[NEIGHBOR_SIZE];
  int length;
  omp_lock_t mutex;
} NeighborList;

typedef struct{
  int idx;
  int length;
  int is_finished;
} NeighborListIterator;

void nl_init(         NeighborList * neighborList);
void nl_init_iterator(NeighborList * neighborList, NeighborListIterator * neighborListIterator);
int  nl_read_next(    NeighborList * neighborList, NeighborListIterator * neighborListIterator);
void nl_push_back(    NeighborList * neighborList, int new_elem);

#endif // OPENMC_NEIGHBOR_LIST_A_H

// API:

/*
NeighborListIterator nli;
nl_init_iterator(nl, &nli);

while(!nli->is_finished)
{
  int element = nl_read_next(nl, &nli)
}
*/
