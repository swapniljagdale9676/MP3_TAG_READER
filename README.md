# MP3_TAG_READER

# MP3-Tag-Reader-and-Editor

## MP3 Tag Reader & Editor in C

### 📌 Project Overview

This project implements an MP3 Tag Reader & Editor using the C programming language. It allows users to view and modify ID3 metadata tags stored in MP3 files. The application can read and update important song information such as Title, Artist, Album, Year, Genre, and Comments directly from the MP3 file.

This project demonstrates concepts of binary file handling, metadata processing, command-line argument parsing, and low-level file manipulation in C.

---

## 🚀 Features

* View MP3 metadata tags
* Edit MP3 metadata tags
* Supports ID3v2 tag frames
* Read Title, Artist, Album, Year, Genre, and Comment
* Update metadata without affecting audio content
* Command-line based execution
* Makefile-based build system
* Modular code structure

---

## 🛠️ Technologies Used

* C Programming
* File Handling
* Binary File Processing
* GCC Compiler
* Makefile
* Command Line Arguments
* Linux Environment

---

## 📂 Project Files

```text
main.c
view.c
edit.c
help.c
mp3_header.h
Makefile
sample.mp3
README.md
```

---

## ⚙️ Build Instructions

Ensure make is installed, then run:

```bash
make
```

This will compile the project and generate the executable.

To clean build files:

```bash
make clean
```

---

## ▶️ Usage

### View MP3 Tags

```bash
./mp3_tag_editor -v sample.mp3
```

### Edit Title

```bash
./mp3_tag_editor -e -t "New Title" sample.mp3
```

### Edit Artist

```bash
./mp3_tag_editor -e -a "New Artist" sample.mp3
```

### Edit Album

```bash
./mp3_tag_editor -e -A "New Album" sample.mp3
```

### Edit Year

```bash
./mp3_tag_editor -e -y "2026" sample.mp3
```

### Edit Genre

```bash
./mp3_tag_editor -e -m "Pop" sample.mp3
...

### Edit Comment

```bash
./mp3_tag_editor -e -c "My Favorite Song" sample.mp3
```

---

## ⚙️ Algorithm Used

### 🎵 Viewing MP3 Tags

1. Open MP3 file in binary mode.
2. Verify ID3 header.
3. Read ID3 frame information.
4. Extract metadata fields.
5. Display tag information to the user.

### ✏️ Editing MP3 Tags

1. Open original MP3 file.
2. Create duplicate MP3 file.
3. Read each ID3 frame.
4. Identify the selected tag.
5. Update metadata content.
6. Copy remaining MP3 data.
7. Replace original file with updated file.

---

## 📷 Sample Output

```text
MP3 TAG INFORMATION

TIT2 (Title)    : Shape of You
TPE1 (Artist)   : Ed Sheeran
TALB (Album)    : Divide
TYER (Year)     : 2017
TCON (Genre)    : Pop
COMM (Comment)  : Sample Comment
```

---

## 🎯 Learning Outcomes

* Binary File Handling
* Metadata Processing
* Command Line Programming
* File Pointer Manipulation
* Dynamic Data Handling
* Modular Programming in C

---

## 👨‍💻 Author

Swapnil Jagdale

Embedded Systems | Embedded Linux | C Programming
