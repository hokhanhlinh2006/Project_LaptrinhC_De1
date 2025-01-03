#include<stdio.h>
#include"functions.h"
#include<string.h>

void startTheProgram(void){
    printf("*** Student Management System Using C***\n");
    printf("\n");
    printf("           CHOOSE YOUR ROLE\n");
    printf("        =========================\n");
    printf("        [1] Admin.\n");
    printf("        [2] Student.\n");
    printf("        [3] Teacher.\n");
    printf("        [0] Exit the Program.\n");
    printf("        =========================\n");
    printf("        Enter The Choice: ");
}
void menuAdmin(void){
    printf("*** Student Management System Using C***\n");
    printf("\n");
    printf("                MENU\n");
    printf("        =========================\n");
    printf("        [1] Students management.\n");
    printf("        [2] Classrooms management.\n");
    printf("        [3] Teacher management.\n");
    printf("        [4] User Guideline.\n");
    printf("        [5] About Us.\n");
    printf("        [6] Exit the Program.\n");
    printf("        =========================\n");
    printf("        Enter The Choice: ");

}
void studentManagement(void){
//          system("cls");
       printf("*** Student Management System Using C***\n");
    printf("\n");
    printf("              STUDENT MENU\n");
    printf("        =========================\n");
    printf("        [1] Add A New student.\n");
    printf("        [2] Show All student.\n");
    printf("        [3] Search A student.\n");
    printf("        [4] Edit A student.\n");
    printf("        [5] Delete A student.\n");
    printf("        [0] Exit the Program.\n");
    printf("        =========================\n");
    printf("        Enter The Choice: ");


  }
void invalidSelection(void){

    printf("\n");
    printf("\n");
    printf("========== Invalid Selection  =======\n");
    printf("\n");
    printf("\n");

}
void endOfTheProgram(void){
    printf("\n");
    printf("========== Thank You =======\n");
    printf("========== See You Soon ====\n");
    printf("\n");
}
  void addStudentInfo(Student students[], int *n) {
    int numToAdd;
     printf("   **** Add A New Student ****\n");
     printf("\n");
    printf("Nhap so luong sinh vien ban muon them: \n");
    scanf("%d", &numToAdd);
    getchar();

    for (int i = 0; i < numToAdd; i++) {

        snprintf(students[*n].studentId, 10, "%d", *n + 1);


        printf("Moi ban nhap vao ten sinh vien: \n");
        fgets(students[*n].name, 30, stdin);
        students[*n].name[strcspn(students[*n].name, "\n")] = '\0';

        printf("Moi ban nhap vao ma lop hoc: \n");
        fgets(students[*n].classroomId, 20, stdin);
        students[*n].classroomId[strcspn(students[*n].classroomId, "\n")] = '\0';


        printf("Moi ban nhap vao so dien thoai: \n");
        fgets(students[*n].phone, 15, stdin);
        students[*n].phone[strcspn(students[*n].phone, "\n")] = '\0';


        printf("Moi ban nhap vao email: \n");
        fgets(students[*n].email, 40, stdin);
        students[*n].email[strcspn(students[*n].email, "\n")] = '\0';


        printf("Moi ban nhap vao ngay thang nam sinh (dd/mm/yyyy): \n");
        fgets(students[*n].birthDate, 30, stdin);
        students[*n].birthDate[strcspn(students[*n].birthDate, "\n")] = '\0';


        printf("Moi ban nhap vao gioi tinh (Nam/Nu): \n");
        fgets(students[*n].gender, 10, stdin);
        students[*n].gender[strcspn(students[*n].gender, "\n")] = '\0';

        (*n)++;
    }
     printf("Da cap nhat thong tin thanh cong \n");
     printf("\n");

}
  void printStudents(Student students[], int n) {
    printf("\n");
    printf("       **** All Students ****\n");
    printf("\n");
    printf("|=======|==================|==============|=======================|===============|============|========|\n");
    printf("|   ID  |     Name         | classroomId  |        Email          |    Phone      | birthDate  | gender |\n");
    printf("|=======|==================|==============|=======================|===============|============|========|\n");

    for (int i = 0; i < n; i++) {
        printf("| %-5s | %-16s | %-12s | %-21s | %-13s | %-9s | %-6s |\n",
               students[i].studentId,
               students[i].name,
               students[i].classroomId,
               students[i].email,
               students[i].phone,
               students[i].birthDate,
               students[i].gender);
    printf("|=======|==================|==============|=======================|===============|============|========|\n");
    }
        printf("\n");
}
  void searchStudentByName(Student students[], int n) {
    char name[20];
    printf("Nhap ten sinh vien can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(students[i].name, name) == 0) {
            printf("|=======|==================|==============|=======================|===============|===========|========|\n");
            printf("|   ID  |     Name         | classroomId  |        Email          |    Phone      | birthDate | gender |\n");
            printf("|=======|==================|==============|=======================|===============|===========|========|\n");
            printf("| %-5s | %-16s | %-12s | %-21s | %-13s | %-9s | %-6s |\n",
                   students[i].studentId,
                   students[i].name,
                   students[i].classroomId,
                   students[i].email,
                   students[i].phone,
                   students[i].birthDate,
                   students[i].gender);
            printf("|=======|==================|==============|=======================|===============|===========|========|\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi name %s.\n", name);
    }
}
void editStudent(Student students[], int n) {
    char position[20];
    int findIndex = -1;

    printf("**** Edit a Student ****\n");
    printf("Enter The Student ID: ");
    scanf("%s", position);
    getchar();


    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].studentId, position) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("Khong tim thay sinh ID!\n");
        printf("\n");
        printf("\n");
    } else {
        printf("\nOne Student Found for ID: %s\n", position);
        printf("Student Information:\n");
        printf("----------------------------\n");
        printf("ID:     %s\n", students[findIndex].studentId);

        printf("Name:       ");
        fgets(students[findIndex].name, 20, stdin);
        students[findIndex].name[strcspn(students[findIndex].name, "\n")] = '\0';

        printf("Email:      ");
        fgets(students[findIndex].email, 20, stdin);
        students[findIndex].email[strcspn(students[findIndex].email, "\n")] = '\0';

        printf("Phone:      ");
        fgets(students[findIndex].phone, 20, stdin);
        students[findIndex].phone[strcspn(students[findIndex].phone, "\n")] = '\0';

        printf("Birth Date: ");
        fgets(students[findIndex].birthDate, 20, stdin);
        students[findIndex].birthDate[strcspn(students[findIndex].birthDate, "\n")] = '\0';

        printf("Gender:     ");
        fgets(students[findIndex].gender, 20, stdin);
        students[findIndex].gender[strcspn(students[findIndex].gender, "\n")] = '\0';

        printf("\n**** Student Information Updated Successfully ****\n");
    }
}
void deleteStudent(Student students[], int *n) {
    char Id[10];
    int findIndex = -1;
    char Delete;
    printf(" **** Delete a Student ****\n");
    printf("\n");
     printf("Enter The Student ID:");
    scanf("%s", Id);
    getchar();


    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i].studentId, Id) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("Khong tim thay sinh vien voi ID: %s\n", Id);
    } else {
            printf("One Student Found For ID: %s",students[findIndex].studentId);
            printf("\n");
            printf("Student Tnformations\n");
            printf("------------------------\n");
            printf("ID:         %s\n",students[findIndex].studentId);
            printf("Name:       %s\n",students[findIndex].name) ;
            printf("Email:      %s\n",students[findIndex].email) ;
            printf("Phone:      %s\n",students[findIndex].phone);
            printf("Birth Date: %s\n",students[findIndex].birthDate) ;
            printf("Gender:     %s\n",students[findIndex].gender);
            printf("\n");
            printf("\n");
            printf("Are you sure want to delete this student? (Y/N): ");
            scanf("%c",&Delete);
            if(Delete =='Y' || Delete =='y'){

              for (int i = findIndex; i < *n - 1; i++) {
               students[i] = students[i + 1];
        }
        (*n)--;
        printf("Sinh vien co ID %s da duoc xoa thanh cong.\n", Id);
    }else{
        printf("Da huy xoa.\n ");
    }
}
}
void enOrReturn(void){
    char backExit;
   printf("Nhan [O] de ket thuc hoac [B] de quay lai:");
   scanf("%c",&backExit);
   while (getchar() != '\n');
   if (backExit == 'O' || backExit == 'o') {
        endOfTheProgram();
//        exit(0);
    } else if (backExit == 'B' || backExit == 'b') {
        printf("Quay lai menu truoc do...\n");
        return;
    } else {
        printf("Lua chon khong hop le. Vui long thu lai.\n");
        enOrReturn();
    }
}
void sortStudent(Student students[], int n) {
//    system("cls");
    int sortOrder;
    if (n < 2) {
//        system("cls");
        printf("*Not Enough Students To Sort*\n");
        return;
    } else {
        do {
            printf("\nSort By Ascending(0) or Descending(1) order: ");
            scanf("%d", &sortOrder);
        } while (sortOrder != 1 && sortOrder != 2);

//        system("cls");

        if (sortOrder == 1) {

            for (int i = 1; i < n; i++) {
                Student key = students[i];
                int j = i - 1;
                while (j >= 0 && strcmp(key.name, students[j].name) < 0) {
                    students[j + 1] = students[j];
                    j--;
                }
                students[j + 1] = key;
            }
        } else {
            for (int i = 1; i < n; i++) {
                Student key = students[i];
                int j = i - 1;
                while (j >= 0 && strcmp(key.name, students[j].name) > 0) {
                    students[j + 1] = students[j];
                    j--;
                }
                students[j + 1] = key;
            }
        }
    }

    printf("\n\t**SORTED STUDENTS**\n\n");
    printf("|=======|==================|==============|=======================|===============|============|========|\n");
    printf("|   ID  |     Name         | classroomId  |        Email          |    Phone      | birthDate  | gender |\n");
    printf("|=======|==================|==============|=======================|===============|============|========|\n");

    for (int i = 0; i < n; i++) {
        sprintf(students[i].studentId, "%d", i + 1);
         printf("| %-5s | %-16s | %-12s | %-21s | %-13s | %-9s | %-6s |\n",
               students[i].studentId,
               students[i].name,
               students[i].classroomId,
               students[i].email,
               students[i].phone,
               students[i].birthDate,
               students[i].gender);
    printf("|=======|==================|==============|=======================|===============|============|========|\n");
    }
}
