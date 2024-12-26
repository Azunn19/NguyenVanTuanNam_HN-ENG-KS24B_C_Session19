#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void deleteStudent(int id, struct Student students[], int *size) {
    int found = -1;
    for (int i = 0; i < *size; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < *size - 1; i++) {
            students[i] = students[i + 1];
        }
        (*size)--;
        printf("Sinh vien voi id %d da bi xoa.\n", id);
    } else {
        printf("Khong tim thay sinh vien voi id %d.\n", id);
    }
}
void printStudents(struct Student students[], int size) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Nguyen Van B", 22, "0987654321"},
        {3, "Nguyen Van C", 21, "0912345678"},
        {4, "Nguyen Van D", 23, "0923456789"},
        {5, "Nguyen Van E", 20, "0934567890"}
    };
    int size = 5;
    printf("Truoc khi xoa:\n");
    printStudents(students, size);
    deleteStudent(3, students, &size);
    printf("\nSau khi xoa:\n");
    printStudents(students, size);

    return 0;
}
