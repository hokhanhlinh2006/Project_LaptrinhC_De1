#include "datatypes.h"
#include<stdio.h>

  void startTheProgram(void);
  void menuAdmin(void);
  void studentManagement(void);
  void invalidSelection(void);
  void endOfTheProgram(void);
  void addStudentInfo(Student students[], int *n);
  void printStudents(Student students[], int n);
  void addStudent(Student students[], int *n, int maxSize);
  void searchStudentById(Student students[], int n);
  void deleteStudent(Student students[], int *n);
  void editStudent(Student students[], int n);
//  void endOrReturn(void);
  void sortStudent(Student students[], int n);
//  void saveStudentToFile(Student students[], int n);
  void loadBooksFromFile(Student students[], int *n);
