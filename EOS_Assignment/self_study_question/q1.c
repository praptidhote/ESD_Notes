#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

struct movie {
    int id;
    char name[50];
    float rating;
};

void addMovie() {
    int fd;
    struct movie m;

    fd = open("movie.dat", O_CREAT | O_WRONLY | O_APPEND, 0666);

    printf("Enter Movie ID: ");
    scanf("%d", &m.id);

    printf("Enter Movie Name: ");
    scanf(" %[^\n]", m.name);

    printf("Enter Rating: ");
    scanf("%f", &m.rating);

    write(fd, &m, sizeof(m));
    close(fd);

    printf("Movie Added Successfully!\n");
}

void displayMovies() {
    int fd;
    struct movie m;

    fd = open("movie.dat", O_RDONLY);

    printf("\nMovie Records:\n");
    printf("ID\tName\t\tRating\n");

    while (read(fd, &m, sizeof(m)) > 0) {
        printf("%d\t%s\t\t%.1f\n", m.id, m.name, m.rating);
    }

    close(fd);
}

void searchMovie() {
    int fd, id, found = 0;
    struct movie m;

    printf("Enter Movie ID to Search: ");
    scanf("%d", &id);

    fd = open("movie.dat", O_RDONLY);

    while (read(fd, &m, sizeof(m)) > 0) {
        if (m.id == id) {
            printf("Movie Found:\n");
            printf("ID: %d\n", m.id);
            printf("Name: %s\n", m.name);
            printf("Rating: %.1f\n", m.rating);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Movie Not Found!\n");

    close(fd);
}

void updateMovie() {
    int fd, id, found = 0;
    struct movie m;

    printf("Enter Movie ID to Update: ");
    scanf("%d", &id);

    fd = open("movie.dat", O_RDWR);

    while (read(fd, &m, sizeof(m)) > 0) {
        if (m.id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", m.name);

            printf("Enter New Rating: ");
            scanf("%f", &m.rating);

            lseek(fd, -sizeof(m), SEEK_CUR);
            write(fd, &m, sizeof(m));

            found = 1;
            printf("Record Updated!\n");
            break;
        }
    }

    if (!found)
        printf("Movie Not Found!\n");

    close(fd);
}

void deleteMovie() {
    int fd1, fd2, id;
    struct movie m;

    printf("Enter Movie ID to Delete: ");
    scanf("%d", &id);

    fd1 = open("movie.dat", O_RDONLY);
    fd2 = open("temp.dat", O_CREAT | O_WRONLY | O_TRUNC, 0666);

    while (read(fd1, &m, sizeof(m)) > 0) {
        if (m.id != id)
            write(fd2, &m, sizeof(m));
    }

    close(fd1);
    close(fd2);

    remove("movie.dat");
    rename("temp.dat", "movie.dat");

    printf("Record Deleted Successfully!\n");
}

void countRecords() {
    int fd, count = 0;
    struct movie m;

    fd = open("movie.dat", O_RDONLY);

    while (read(fd, &m, sizeof(m)) > 0)
        count++;

    close(fd);

    printf("Total Records = %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== MOVIE MANAGEMENT =====\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Search Movie\n");
        printf("4. Update Movie\n");
        printf("5. Delete Movie\n");
        printf("6. Count Records\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMovie(); break;
            case 2: displayMovies(); break;
            case 3: searchMovie(); break;
            case 4: updateMovie(); break;
            case 5: deleteMovie(); break;
            case 6: countRecords(); break;
            case 7: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
