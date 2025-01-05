#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/* int akey_hook(int keycode, void *param)
{
    (void)param; // parametre kullanılmadığı için bu şekilde işaretlenir
    printf("Keycode: %d\n", keycode);
    return (0);
} */

/* int main(void)
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error initializing mlx\n");
        return (1);
    }

    window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Keycode Display");
    if (!window)
    {
        fprintf(stderr, "Error creating window\n");
        return (1);
    }

    mlx_key_hook(window, akey_hook, NULL);
    mlx_loop(mlx);

    return (0);
} */