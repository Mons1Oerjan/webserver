#include "request_control_block.h"

/* Constants */
#define NUM_SUPPORTED_ALGORITHMS 3

/* function prototypes */
extern void scheduler_init(char* selected_algorithm);
extern void submit_to_scheduler(struct rcb* request_control_block);
extern struct rcb* get_from_scheduler();

/* pointers to the functions inside the scheduler_info struct */
typedef void (*submit_func)(struct rcb*);
typedef struct rcb* (*get_next_func)(void);

/* scheduler struct */
struct scheduler_info {
    char* algorithm;                /* name of the algorithm (e.g. SJF) */
    submit_func submit_rcb;         /* pointer to submit function */
    get_next_func get_next_rcb;     /* pointer to get_next function */
};
