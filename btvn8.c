#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
int main() {
    struct Student students[50];
    int numStudents = 5;
    students[0] = (struct Student){1, "Nguyen Van A", 20, "0901234567"};
    students[1] = (struct Student){2, "Tran Thi B", 21, "0912345678"};
    students[2] = (struct Student){3, "Le Van C", 22, "0923456789"};
    students[3] = (struct Student){4, "Pham Thi D", 19, "0934567890"};
    students[4] = (struct Student){5, "Hoang Van E", 23, "0945678901"};
    printf("Danh sach sinh vien truoc khi chen:\n");
    printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So dien thoai");
    for (int i = 0; i < numStudents; i++) {
        printf("%-5d %-20s %-5d %-15s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
    printf("\n");
    int insertPosition;
    printf("Nhap vi tri can chen sinh vien (0 den %d): ", numStudents);
    scanf("%d", &insertPosition);
    if (insertPosition < 0 || insertPosition > numStudents || numStudents >= 50) {
        printf("Vi tri chen khong hop le hoac danh sach da day.\n");
    } else {
        for (int i = numStudents; i > insertPosition; i--) {
            students[i] = students[i - 1];
        }
        struct Student newStudent;
        printf("\nNhap thong tin sinh vien moi:\n");
        printf("ID: ");
        scanf("%d", &newStudent.id);
        getchar();
        printf("Ten: ");
        fgets(newStudent.name, sizeof(newStudent.name), stdin);
        newStudent.name[strcspn(newStudent.name, "\n")] = 0;
        printf("Tuoi: ");
        scanf("%d", &newStudent.age);
        getchar();
        printf("So dien thoai: ");
        fgets(newStudent.phoneNumber, sizeof(newStudent.phoneNumber), stdin);
        newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = 0;
        students[insertPosition] = newStudent;
        numStudents++;
        printf("\nDa chen sinh vien thanh cong.\n\n");
        printf("Danh sach sinh vien sau khi chen:\n");
        printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So dien thoai");
        for (int i = 0; i < numStudents; i++) {
            printf("%-5d %-20s %-5d %-15s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
        }
    }
    return 0;
}