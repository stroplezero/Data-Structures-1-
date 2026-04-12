#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 30

struct student {
	char name[20];
	int studentID;
	int grade;
};

struct all_names {
	char name[20];
};

int main() {

	srand((unsigned)time(NULL));

	struct student *list = (struct student*)malloc(sizeof(struct student) * SIZE);
	if (list == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	FILE *fp;

	fp = fopen("C:\\Users\\a0103\\Desktop\\name_list.txt", "r");

	if (fp == NULL) {
		printf("Fail to open\n");
		return 0;
	}

	struct all_names all_names[100];
	int count = 0;

	while (count < 100 && fgets(all_names[count].name, sizeof(all_names[count].name), fp) != NULL) {
		all_names[count].name[strcspn(all_names[count].name, "\r\n")] = '\0';
		count++;
	}
	fclose(fp);

	int n = count;
	struct all_names temp;
	
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		temp = all_names[i]; 
		all_names[i] = all_names[j]; 
		all_names[j] = temp;
	}

	for (int i = 0; i < SIZE; i++) {
		strcpy(list[i].name, all_names[i].name);
		list[i].studentID = i + 1;
		list[i].grade = (rand() % 100) + 1;
	}

	struct student max = list[0];
	struct student min = list[0];
	int sum = list[0].grade;

	for (int i = 1; i < SIZE; i++) {
		if (max.grade < list[i].grade) {
			max = list[i];
		}
		if (min.grade > list[i].grade) {
			min = list[i];
		}
		sum = sum + list[i].grade;
	}
	double average = (double)sum / SIZE;

	printf("max: %s, %d, %d\n", max.name, max.studentID, max.grade);
	printf("min: %s, %d, %d\n", min.name, min.studentID, min.grade);
	printf("average: %.2f\n", average);

	free(list);

	return 0;
}
