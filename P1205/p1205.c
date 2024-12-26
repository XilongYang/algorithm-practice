#include <stdio.h>

/**
 * For a image, there are only 4 states about rotate operation: rotate 0, rotate 90, rotate 180, rotate 270
 * and only 2 states about the flip operation: flip or not.
 * So, there are only 8 state at all:
 * 1. origin
 * 2. rotate 90
 * 3. rotate 180
 * 4. rotate 270
 * 5. h_flip
 * 6. h_flip & rotate 90
 * 7. h_flip & rotate 180
 * 8. h_flip & rotate 270
 * Furthermore, there are three meta states, all possible states can be obtained by orthogonally combining them.
 * 1. rotate 90 & h_flip
 * 2. rotate 180 & h_flip
 * 3. flip
 * And we can apply any of those meta states to an image by simply change a way to iterate it:
 * 1. Swap the x and the y for every pixel(x, y) in the image => rotate 90 & h_flip
 * 2. Reverse the traversal order in the vertical direction => rotate 180 & h_flip
 * 3. Reverse the traversal order in the horizontal direction => h_flip
 * We can difine those meta states by 1, 2 and 4 respectly, and then we can combine it by the xor operation.
 * For example, 1 (rotate 90 & h_flip) ^ 3(h_flip) = 5 
*/

int n;

char img_ori[10][10];
char img_trans = 0;

char img_fin[10][10];

void input_img(char img[10][10]) {
    for (int i = 0; i < n; ++i) {
        char cur[10];
        scanf("%s", cur);
        for (int j = 0; j < n; ++j) {
            img[i][j] = cur[j];
        }
    }
}

void show_img(char img[10][10]) {
    int sy = iy_flg ? n - 1 : 0;
    int ey = iy_flg ? -1 : n;
    int dy = iy_flg ? -1 : 1;

    int sx = ix_flg ? n - 1 : 0;
    int ex = ix_flg ? -1 : n;
    int dx = ix_flg ? -1 : 1;

    for (int i = sy; i != ey; i += dy) {
        for (int j = sx; j != ex; j += dx) {
            printf("%c", (t_flg ? img[j][i] : img[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    input_img(img_ori);
    input_img(img_fin);
    return 0;
}
