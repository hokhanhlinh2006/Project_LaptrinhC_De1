#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Student students[100];
int studentCount = 0;
int quantity=-1;
int main(int argc, char *argv[]) {
    int choice;
    int choiceAdmin;
    int choicestudent;
    int n = 0;
    do{
       startTheProgram();
       scanf("%d",&choice);
    switch(choice){
        case 1:
            system("cls");
            do{
                menuAdmin();
                scanf("%d",&choiceAdmin);
                    switch(choiceAdmin){


                    case 1:
                        system("cls");
                           do{

                              studentManagement();

                              scanf("%d",&choicestudent);
                             switch(choicestudent){
                                 case 1:
                                     system("cls");
                                    addStudentInfo(students,&n);
                                   break;
                                 case 2:
                                     system("cls");
                                      printStudents(students, n);
//                                      enOrReturn();
                                   break;
                                 case 3:
                                     system("cls");
                                     //searchStudentByName(students, n);
                                   break;
                                 case 4:
                                     system("cls");
                                     editStudent(students, n);
                                   break;
                                 case 5:
                                     system("cls");
                                     deleteStudent(students,&n);
//                                     saveStudentToFile(students,n);
//                                    endOrReturn();
                                   break;
                                   case 0:
                                   break;
                                 default:
                                   invalidSelection();
                                  }
                              }while(choicestudent !=0 );

                      break;
                    case 2:
                      break;
                    case 3:
                      break;
                    case 4:
                      break;
                    case 5:
                      break;
                      case 6:
                          break;

                    default:
                      invalidSelection();
                }
            }while(choiceAdmin !=6);
             break;
        case 2:
             break;
        case 3:
             break;
        case 0:
            endOfTheProgram();
             break;
        default:
           invalidSelection();
    }
   }while(choice != 0);

    return 0;

}
