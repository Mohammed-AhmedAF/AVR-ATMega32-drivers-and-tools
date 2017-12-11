#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct human {
	int id;
	int age;
	char gender;
	char name[10];
};

struct student {
	struct human general;
	int grade;
	int hw; 
};

struct employee {
	struct human general;
	int salary;
	int ot;
};

void getName(char []);

void main() {
	struct employee emp;
	struct student stud;
	char choice;
	int sID = 0, eID = 0;
	struct employee emps [10];
	struct student studs [10];
	while(1) {
		printf("Do you want a student or an employeer\n");
		choice =getchar();
		fflush(stdin);
		if(choice == 's' || choice == 'S') {
			printf("Enter name \n");
			fflush(stdin);
			gets(stud.general.name);
			printf("Enter id, age, gender\n");
			scanf(" %d %d %c",&stud.general.id,&stud.general.age,&stud.general.gender);
			printf("Enter grade and homework:\n");
			scanf(" %d %d",&stud.grade,&stud.hw);
			studs[sID] = stud;
			sID++;
		}
		else if(choice == 'e' || choice == 'E'){
			 printf("Enter name:\n");
			fgets(emp.general.name,10,stdin);
			printf("Enter id, age, gender\n");
			scanf(" %d %d %c", &emp.general.id,&emp.general.age,&emp.general.gender);
			printf("Enter salary and overtime:\n");
			scanf(" %d %d",&emp.salary,&emp.ot);
			emps[eID] = emp;
			eID++;
		}
	}
	
}

