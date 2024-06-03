#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define False   0
#define True    1

struct Bitmap {
    int rows;
    int cols;
    short *pixels;
};

struct Node {
    short intensity;
    struct Node *children[4];
};

struct Tree {
    struct Node *root;
};

void create_branches(struct Node *root, short *pixels, int w) {
    int i, j, k;

    short *q1;
    short *q2;
    short *q3;
    short *q4;
    
    root->intensity = pixels[0];
    root->children[0] = NULL;
    root->children[1] = NULL;
    root->children[2] = NULL;
    root->children[3] = NULL;

    if (w != 1) {
        for (i=0; i<w*w; ++i) {
            if (root->intensity != pixels[i]) {
                root->intensity = -1;
    
                q1 = malloc(((w * w)/4) * sizeof(short));
                q2 = malloc(((w * w)/4) * sizeof(short));
                q3 = malloc(((w * w)/4) * sizeof(short));
                q4 = malloc(((w * w)/4) * sizeof(short));
                
                k = 0;
                for (i=0; i<w/2; ++i)
                    for (j=0; j<w/2; ++j) {
                        q1[k] = pixels[w*i + j];
                        ++k; 
                    }
                
                k = 0; 
                for (i=0; i<w/2; ++i)
                    for (j=w/2; j<w; ++j) {
                        q2[k] = pixels[w*i + j];
                        ++k; 
                    }
                
                k = 0;
                for (i=w/2; i<w; ++i)
                    for (j=0; j<w/2; ++j) {
                        q3[k] = pixels[w*i + j];
                        ++k; 
                    }
                
                k = 0;
                for (i=w/2; i<w; ++i)
                    for (j=w/2; j<w; ++j) {
                        q4[k] = pixels[w*i + j];
                        ++k; 
                    }
    
                root->children[0] = malloc(sizeof(struct Node));
                root->children[1] = malloc(sizeof(struct Node)); 
                root->children[2] = malloc(sizeof(struct Node));
                root->children[3] = malloc(sizeof(struct Node));
     
                create_branches(root->children[0], q1, w/2);
                create_branches(root->children[1], q2, w/2);
                create_branches(root->children[2], q3, w/2);
                create_branches(root->children[3], q4, w/2);
                
                return;
            }  
        } 
    }

    else {
        /*printf("d: %d, w: %d\n", root->intensity, w);*/
        return;
    } 

}

void preorder(struct Node *root) {
    /* printf("d: %d\n", root->intensity); */
    printf("%d\n", root->intensity);

    if (root->intensity == -1) {
        preorder(root->children[0]);
        preorder(root->children[1]);
        preorder(root->children[2]);
        preorder(root->children[3]);
    } 
    else {
        free(root);
        return;
    } 
}

struct Tree Tree_new(struct Bitmap *b) {
    struct Tree new_tree;
    new_tree.root = malloc(sizeof(struct Node));
    create_branches(new_tree.root, b->pixels, b->rows);
    return new_tree;
}

void Tree_clear(struct Tree *t) {
    preorder(t->root);
    
}



struct Bitmap Bitmap_new(char *fname){
    FILE *in_file;
    int ch;
    int i;

    int numb_of_lines = 0;
    struct Bitmap btmap = {0, 0, NULL};
    
    in_file = fopen(fname, "r"); /* read only*/

    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(-1);
    }

    while ((ch = fgetc(in_file)) != EOF) {
        if (ch == '\n') {
            ++numb_of_lines;
        }
    }
    fclose(in_file);

    btmap.rows = sqrt(numb_of_lines);
    btmap.cols = sqrt(numb_of_lines);
    btmap.pixels = (short*) malloc(numb_of_lines * sizeof(short));

    i = 0;
    
    in_file = fopen(fname, "r"); /* read only*/
    while ((ch = fgetc(in_file)) != EOF) {
        if (isdigit(ch)) {
            btmap.pixels[i] = ch-'0';
            ++i;
        }
    }

    fclose(in_file);
    return btmap;
}

void Bitmap_clear(struct Bitmap *b) {
    free(b->pixels);
}

int main() {
    struct Bitmap btmap = Bitmap_new("input.txt");
    struct Tree tree = Tree_new(&btmap);
    Tree_clear(&tree);
    Bitmap_clear(&btmap);

    /* printf("Size of simpler image: %ld\n", sizeof(*btmap.pixels)); */

    return 0;
}

