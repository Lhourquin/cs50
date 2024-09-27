#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if(argc != 2){
        printf("Usage ./recover card");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if(card == NULL){
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];

    int count = 0;
    FILE *image = NULL;
    int found_jpg = 0;
    while (fread(buffer, 1, 512, card) == 512) {


        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff ){

            if (found_jpg == 1) {
                fclose(image);
            }

            char filename[20];
            sprintf(filename, "img%03d.png", count);
            image = fopen(filename, "wb");
            if (image == NULL) {
                return 1;
            }

            fwrite(buffer, 1, 512, image);
            found_jpg = 1;
            count++;

        }else if (found_jpg == 1) {
            fwrite(buffer, 1, 512, image);
        }

    }

    if(image != NULL){
        fclose(image);
    }

    fclose(card);


    return 0;

}
