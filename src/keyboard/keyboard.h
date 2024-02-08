#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEYBOARD_CAPS_LOCK_ON 1
#define KEYBOARD_CAPS_LOCK_OFF 0

typedef int KEYBOARD_CAPS_LOCK_STATE;
typedef int (*KEYBOARD_INIT_FUNCTION)();

struct process;
struct keyboard 
{
    KEYBOARD_INIT_FUNCTION init;
    char name[20];
    KEYBOARD_CAPS_LOCK_STATE capslock_state;
    struct keyboard* next;
};

void keyboard_init();
int keyboard_insert(struct keyboard* keyboard);
void keyboard_backspace(struct process* process);
KEYBOARD_CAPS_LOCK_STATE keayboard_get_caps_lock(struct keyboard* keyboard);
void keyboard_set_capslock(struct keyboard* keyboard, KEYBOARD_CAPS_LOCK_STATE state);
void keyboard_push(char c);
char keyboard_pop();

#endif