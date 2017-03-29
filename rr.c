#include <stdio.h>

#include "rcb.h"
#include "scheduler.h"
#include "queue.h"

/* constants */
#define QUANTUM 8192

/* function prototypes */
static void submit(struct rcb* r);
static struct rcb* get_next(void);

/* initialize the queue */
static struct queue ready;

/* initialize the RR scheduler struct */
struct scheduler_info rr_scheduler = {
    "RR",
    &submit,
    &get_next
};

/* inserts an RCB to the queue */
static void submit(struct rcb* r) {
  r->bytes_max_allowed = QUANTUM;                /* set quantum */
  queue_enqueue(&ready, r);        /* enqueue */
}

/* removes the current RCB and gets the next RCB */
static struct rcb* get_next(void) {
  return queue_dequeue(&ready);   /* dequeue and return */
}
