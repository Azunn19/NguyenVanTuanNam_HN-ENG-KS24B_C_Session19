#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
struct Student students[5] = {
    {1, "Nguyen Van A", 20, "0123456789"},
    {2, "Nguyen Van B", 22, "0987654321"},
    {3, "Nguyen Van C", 21, "0912345678"},
    {4, "Nguyen Van D", 23, "0923456789"},
    {5, "Nguyen Van E", 20, "0934567890"}
};
int size = 5;
void printStudents() {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}
void addStudent() {
    struct Student newStudent;
    printf("Nhap ID sinh vien: ");
    scanf("%d", &newStudent.id);
    getchar();
    printf("Nhap ten sinh vien: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Nhap so dien thoai sinh vien: ");
    fgets(newStudent.phoneNumber, sizeof(newStudent.phoneNumber), stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';
    students[size] = newStudent;
    size++;
    printf("Sinh vien moi da duoc them.\n");
}
void editStudent() {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("Sinh vien tim thay: %s\n", students[i].name);
            getchar();
            printf("Nhap ten moi sinh vien: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Nhap tuoi moi sinh vien: ");
            scanf("%d", &students[i].age);
            getchar();
            printf("Nhap so dien thoai moi sinh vien: ");
            fgets(students[i].phoneNumber, sizeof(students[i].phoneNumber), stdin);
            students[i].phoneNumber[strcspn(students[i].phoneNumber, "\n")] = '\0';
            printf("Thong tin sinh vien da duoc sua.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}
void deleteStudent() {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    int found = -1;
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
        printf("Sinh vien voi ID %d da bi xoa.\n", id);
    } else {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}
void searchStudent() {
    int id;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);

    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("Sinh vien tim thay: ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %d.\n", id);
}
void sortStudentsByName() {
    struct Student temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo ten.\n");
}
void menu() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                editStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                sortStudentsByName();
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
