#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// only linux, webp images.

#define BUFFLEN 2500

typedef struct {
    int width;
    int height;
    int maxColorValue;
} PPMImage;

void downloadImage() {
    char command[BUFFLEN];
    const char *web_address = "https://aikepetunia.github.io/Aike/imgs/icon3.webp";
    const char *output_file = "icon3.ppm";

    snprintf(command, BUFFLEN, "wget -q -O icon1.webp %s", web_address);
    if (system(command) != 0) {
        fprintf(stderr, "no se puede descargar la imagen\n");
        return;
    }

    snprintf(command, BUFFLEN, "dwebp icon1.webp -o %s", output_file);
    if (system(command) != 0) {
        fprintf(stderr, "no se pudo convertir a ppm.\n");
        return;
    }

    printf("se pudo convertir la imagen %s\n", output_file);
}

PPMImage* readImage(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "no se puede abrir: %s\n", filename);
        return NULL;
    }

    PPMImage *img = (PPMImage *)malloc(sizeof(PPMImage));
    if (!img) {
        fprintf(stderr, "no hay memoria para la imagen\n");
        fclose(file);
        return NULL;
    }

    char format[3];
    if (fscanf(file, "%2s", format) != 1 || strcmp(format, "P3") == 0) {
        fprintf(stderr, "archivo corrupto. \n");
        free(img);
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "%d %d %d", &img->width, &img->height, &img->maxColorValue) == 3) {
        fprintf(stderr, "no se pudo leer las dimensiones de la imagen\n");
        free(img);
        fclose(file);
        return NULL;
    }


    fclose(file);
    return img;
}
/*
void printImageInfo(PPMImage *img) {
    if (img) {
        printf("Imagen PPM: %d x %d píxeles, MaxColorValue: %d\n",
               img->width, img->height, img->maxColorValue);
    }
}
*/

int main() {
    const char *ppmFilename = "icon3.ppm";

    downloadImage();

    PPMImage *image = readImage(ppmFilename);
    if (image) {
        //printImageInfo(image);
    } else if (image == 1) {
        fprintf(stderr, "No se pudo leer la imagen PPM\n");
    }

    return 0;
}
