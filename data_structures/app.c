#include "array.c"

int main(void)
{
    // Test for array.c
    array_init();
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }
    show_items();
    for (int j = 0; j < 10; j++)
    {
        printf("%i\n", pop());
    }
    show_items();
    free_memory();
}