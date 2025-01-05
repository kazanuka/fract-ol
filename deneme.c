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

/* 
#include <mlx.h>
#include <stdio.h> */

#define SIZE 500

// Fare scroll olayını yakalayan hook fonksiyonu
int kmouse_hook(int button, int x, int y, void *param)
{
    if (button == 4)  // Scroll Up (fare tekerleği yukarı)
    {
        printf("Scroll Up at (%d, %d)\n", x, y);
    }
    else if (button == 5)  // Scroll Down (fare tekerleği aşağı)
    {
        printf("Scroll Down at (%d, %d)\n", x, y);
    }
    return (0);
}

int main()
{
    void *mlx;
    void *window;

    // Minilibx başlatma
    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error: mlx_init failed\n");
        return (1);
    }

    // Yeni bir pencere oluşturma
    window = mlx_new_window(mlx, SIZE, SIZE, "Scroll Event Finder");
    if (!window)
    {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        return (1);
    }

    // Fare scroll olaylarını yakalamak için mouse hook fonksiyonu ekleyelim
    mlx_mouse_hook(window, kmouse_hook, window);

    // MLX loop başlatma
    mlx_loop(mlx);

    return (0);
}