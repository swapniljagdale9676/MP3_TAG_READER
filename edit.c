/* Edit file where we can change the metadata as we want */
#include "mp3_header.h"

//TO EDIT THE CONTENT OF THE SONG
void edit_mp3(const char *TAG, const char *new_txt, const char *file)
{
    FILE *fp = fopen(file, "rb");
    FILE *dub_fp = fopen("dublicate.mp3", "wb");

    if (dub_fp == NULL || fp == NULL) {
        perror("Error");
        exit(0);
    }

    // Read + write header
    char header[10];
    fread(header, 1, 10, fp);
    fwrite(header, 1, 10, dub_fp);

    for (int i = 0; i < 6; i++)
    {
        //Read And Write Tag
        char tag[5];
        fread(tag, sizeof(tag)-1, 1, fp);
        tag[4] = '\0';
        fwrite(tag, sizeof(tag)-1, 1, dub_fp);

        // Match the tag
        if (strcmp(TAG, tag) == 0)
        {
            // new size
            int size = strlen(new_txt) + 1;
            int temp_size = size - 1;

            //Convert Size in Bigendian and write
            int be_size = convert(size);
            fwrite(&be_size, 4, 1, dub_fp);

            // read old size + flags
            int og_size;
            fread(&og_size, 4, 1, fp);

            //Read and Write the Flags
            char flag[2];
            fread(flag, 1, 2, fp);
            fwrite(flag, 1, 2, dub_fp);

            // encoding byte + new content
            char null = 0;
            fwrite(&null, 1, 1, dub_fp);
            fwrite(new_txt, 1, temp_size, dub_fp);

            // skip old content
            og_size = convert(og_size);
            fseek(fp, og_size, SEEK_CUR);

        }
        else
        {
            // copy original frame size + data
            int size;
            fread(&size, 4, 1, fp);
            fwrite(&size, 4, 1, dub_fp);

            int og_size = convert(size);

            char flag[2];
            fread(flag, 1, 2, fp);
            fwrite(flag, 1, 2, dub_fp);

            // Allocate buffer properly
            char content[og_size];
            fread(content, 1, og_size, fp);
            fwrite(content, 1, og_size, dub_fp);
        }
    }

    // Copy rest of MP3 file correctly
    char ch;
    while (fread(&ch, 1, 1, fp) == 1) {
        fwrite(&ch, 1, 1, dub_fp);
    }

    fclose(fp);
    fclose(dub_fp);

    remove(file);
    rename("dublicate.mp3", file);
}
