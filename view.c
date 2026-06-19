#include "mp3_header.h"

char *frames[6] = {"Title", "Artist", "Album", "Year", "Content", "Comment"};

void view_mp3(const char *file)
{
    // Open MP3 file in binary read mode
    FILE *fp = fopen(file, "rb");
    if (fp == NULL)
    {
        perror("Error");
        return;
    }

    // Read first 3 bytes (should be "ID3")
    char ID3[4];
    fread(ID3, sizeof(ID3) - 1, 1, fp);
    ID3[3] = '\0';

    // Validate MP3 tag header
    if(strcmp(ID3,"ID3")){
        printf("This is not a .mp3 file..!\n");
        exit(0);
    }

    // Skip next 7 bytes (version + flags + size)
    fseek(fp, 7, SEEK_CUR);

    // Read 6 frames (Title, Artist, Album, Year, Genre, Comment)
    for (int i = 0; i < 6; i++)
    {
        char tag[5];                       // Frame ID (e.g., TIT2)
        fread(tag, 1, 4, fp);
        tag[4] = '\0';

        int size;                          // Frame content size
        fread(&size, sizeof(size), 1, fp);
        size = convert(size);              // Convert big-endian to little-endian

        fseek(fp, 3, SEEK_CUR);            // Skip frame flags (usually 3 bytes)

        char content[size];                // Frame text content
        fread(content, size - 1, 1, fp);
        content[size - 1] = '\0';

        // Print frame ID, content, and readable name
        printf("%s (%s)\t : %s \n", tag, frames[i], content);
    }

    fclose(fp); // Close file
}

// Convert 4-byte integer from big-endian to little-endian
int convert(int size)
{
    char *ptr = (char *)&size;

    for (int i = 0; i < sizeof(int) / 2; i++)
    {
        char temp = ptr[i];
        ptr[i] = ptr[sizeof(int) - i - 1];
        ptr[sizeof(int) - i - 1] = temp;
    }
    return size;
}
