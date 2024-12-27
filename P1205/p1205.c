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
 * Furthermore, there are three meta operations, all possible states can be obtained by orthogonally combining them.
 * 1. Swap the x and the y for every pixel(x, y) in the image => rotate 90 & h_flip
 * 2. Reverse the traversal order in the vertical direction   => rotate 180 & h_flip
 * 3. Reverse the traversal order in the horizontal direction => h_flip
*/

#include <stdio.h>

int n;

char img_ori[10][10];

char img_fin[10][10];

/*
 * n x y t    result
 * 0 0 0 0 -> origin
 * 1 0 0 1 -> rotate 90 & h_flip
 * 2 0 1 0 -> rotate 180 & h_flip
 * 3 0 1 1 -> rotate 270
 * 4 1 0 0 -> h_flip
 * 5 1 0 1 -> rotate 90
 * 6 1 1 0 -> rotate 180
 * 7 1 1 1 -> rotate 270 & h_flip
 * 
 * r   n result 
 * 1   5 rotate 90
 * 2   6 rotate 180
 * 3   3 rotate 270
 * 4   4 h_flip
 * 5-1 1 h_flip & rotate 90
 * 5-2 2 h_flip & rotate 180
 * 5-3 7 h_flip & rotate 270
 * 6   0 origin
 * 7   - invalid 
*/
int result_map[8] = {1, 2, 3, 4, 5, 5, 5, 6};
int trans_map[8]  = {5, 6, 3, 4, 1, 2, 7, 0};

void input_img(char img[10][10]) {
    for (int i = 0; i < n; ++i) {
        char cur[10];
        scanf("%s", cur);
        for (int j = 0; j < n; ++j) {
            img[i][j] = cur[j];
        }
    }
}

int compare_img(char trans) {
    int t_flg = trans & 1;
    int y_flg = trans & 2;
    int x_flg = trans & 4;

    int sy = y_flg ? n - 1 : 0;
    int ey = y_flg ? -1 : n;
    int dy = y_flg ? -1 : 1;

    int sx = x_flg ? n - 1 : 0;
    int ex = x_flg ? -1 : n;
    int dx = x_flg ? -1 : 1;

    for (int i = sy, y = 0; i != ey && y < n; i += dy, y++) {
        for (int j = sx, x = 0; j != ex && x < n; j += dx, x++) {
            char ori = t_flg ? img_ori[j][i] : img_ori[i][j];
            if (ori != img_fin[y][x]) return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    input_img(img_ori);
    input_img(img_fin);
    int success = 0;
    for (int i = 0; i < 8; ++i) {
        if (!compare_img(trans_map[i])) continue;
        success = 1;
        printf("%d\n", result_map[i]);
        break;
    }
    if (!success) {
        printf("7\n");
    }
    return 0;
}
