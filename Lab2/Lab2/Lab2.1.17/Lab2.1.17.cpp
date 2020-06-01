// Lab2.1.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdio.h>
#define M_PI 3.1415926
#define M_AU 1.5e8
#define Grav_Const 6.67e-11
#define Mass_Const 1e24

struct Planet {
	float mass;
	float radius;
	float speed;
	float yearPass;
	float distance1;
	float distance2;
	float gravConst1;
	float gravConst2;
};

Planet* CreatePlanet() {
	Planet* planet = (Planet*)malloc(sizeof(Planet));
	return planet;
}

void DestroyPlanet(Planet* planet) {
	free(planet);
}

void EnterData(Planet* planet) {
	printf("Enter planets weight (10^24 kg): ");
	scanf_s("%f", &planet->mass);
	printf("Enter planets orbit radius (astronomical units): ");
	scanf_s("%f", &planet->radius);
	printf("Enter planets turn speed (km/sec): ");
	scanf_s("%f", &planet->speed);
}

float YearPass(Planet* planet)
{
	return 2 * M_PI * M_AU * planet->radius / (86400.0 * (planet->speed));
}

float DistanceCalc(Planet* first, Planet* second, float time) {
	float a1, a2, a1a2, b1, b2, b1b2;
	if (time / first->yearPass > 0.25 || time / first->yearPass < 0.75) {
		a1 = M_AU * first->radius * sin(2 * M_PI * time / first->yearPass);
		b1 = M_AU * first->radius * cos(2 * M_PI * time / first->yearPass);
	}
	else {
		a1 = M_AU * first->radius * sin(2 * M_PI * time / first->yearPass);
		b1 = M_AU * first->radius * (1 - cos(2 * M_PI * time / first->yearPass));
	}
	if (time / second->yearPass > 0.25 || time / second->yearPass < 0.75) {
		a2 = M_AU * second->radius * sin(2 * M_PI * time / second->yearPass);
		b2 = M_AU * second->radius * cos(2 * M_PI * time / second->yearPass);
	}
	else {
		a2 = M_AU * second->radius * sin(2 * M_PI * time / second->yearPass);
		b2 = M_AU * second->radius * (1 - cos(2 * M_PI * time / second->yearPass));
	}
	a1a2 = fabs(a1 - a2);
	b1b2 = fabs(b1 - b2);

	return sqrt(a1a2 * a1a2 + b1b2 * b1b2);
}

void GravitatyConstCalc(Planet* first, Planet* second, Planet* third) {
	second->gravConst1 = first->gravConst1 = Grav_Const * first->mass * Mass_Const * Mass_Const * second->mass / powf(M_AU * first->distance1, 2);
	third->gravConst1 = first->gravConst2 = Grav_Const * first->mass * Mass_Const * Mass_Const * third->mass / powf(M_AU * first->distance2, 2);
	third->gravConst2 = second->gravConst2 = Grav_Const * second->mass * Mass_Const * Mass_Const * third->mass / powf(M_AU * second->distance2, 2);
}

void ResetPlanet(Planet* planet) {
	planet->mass = 0;
	planet->radius = 0;
	planet->speed = 0;
	planet->yearPass = 0;
	planet->distance1 = 0;
	planet->distance2 = 0;
	planet->gravConst1 = 0;
	planet->gravConst2 = 0;
}

void Menu(void) {
	Planet* e2g1 = CreatePlanet();
	Planet* e2g2 = CreatePlanet();
	Planet* e2g3 = CreatePlanet();
	while (true) {
		printf("Choose an option:\n");
		if (e2g1->mass <= 0) {
			printf("[1] Enter the stats of the 1st planet: \n");
		}
		else printf("[1] Weight = %f e24 kg, Orbit radius = %f a.u., Planet's speed = %f km/sec\n", e2g1->mass, e2g1->radius, e2g1->speed);
		if (e2g2->mass <= 0) {
			printf("[2] Enter the stats of the 2nd planet: \n");
		}
		else printf("[2] Weight = %f e24 kg, Orbit radius = %f a.u., Planet's speed = %f km/sec\n", e2g2->mass, e2g2->radius, e2g2->speed);
		if (e2g3->mass <= 0) {
			printf("[3] Enter the stats of the 3rd planet: \n");
		}
		else printf("[3] Weight = %f e24 kg, Orbit radius = %f a.u., Planet's speed = %f km/sec\n", e2g3->mass, e2g3->radius, e2g3->speed);
		if (e2g1->mass > 0 && e2g2->mass > 0 && e2g3->mass > 0)
		{
			printf("[4] year pass calculation.\n");
		}
		if (e2g1->yearPass > 0 && e2g2->yearPass > 0 && e2g3->yearPass > 0)
		{
			printf("[5] Distance between planets.\n");
		}
		if (e2g1->distance1 > 0 && e2g2->distance1 > 0 && e2g3->distance1 > 0)
		{
			printf("[6] Gravity force calculation.\n");
		}
		printf("[7] Reset data.\n");
		printf("[8] Exit.\n");
		printf("[0] About.\n");
		int option;
		scanf_s("%d", &option);
		switch (option) {
		case 1: EnterData(e2g1); break;
		case 2: EnterData(e2g2); break;
		case 3: EnterData(e2g3); break;
		case 4:
			e2g1->yearPass = YearPass(e2g1);
			e2g2->yearPass = YearPass(e2g2);
			e2g3->yearPass = YearPass(e2g3);
			printf("1 year Planet e2g1 lasts %f earth days\n", e2g1->yearPass);
			printf("1 year Planet e2g2 lasts %f earth days\n", e2g2->yearPass);
			printf("1 year Planet e2g3 lasts %f earth days\n", e2g3->yearPass);
			break;
		case 5:
			float time;
			printf("Enter the number of days passed: ");
			scanf_s("%f", &time);
			e2g1->distance1 = DistanceCalc(e2g1, e2g2, time);
			e2g1->distance2 = DistanceCalc(e2g1, e2g3, time);
			e2g2->distance1 = DistanceCalc(e2g2, e2g1, time);
			e2g2->distance2 = DistanceCalc(e2g2, e2g3, time);
			e2g3->distance1 = DistanceCalc(e2g3, e2g1, time);
			e2g3->distance2 = DistanceCalc(e2g3, e2g2, time);
			printf("Distance between e2g1 & e2g2 is %f\n", e2g1->distance1);
			printf("Distance between e2g1 & e2g3 is %f\n", e2g1->distance2);
			printf("Distance between e2g2 & e2g3 is %f\n", e2g2->distance2);
			break;
		case 6:
			GravitatyConstCalc(e2g1, e2g2, e2g3);
			printf("Gravity Constant between e2g1 & e2g2 is %f\n", e2g1->gravConst1);
			printf("Gravity Constant between e2g1 & e2g3 is %f\n", e2g1->gravConst2);
			printf("Gravity Constant between e2g2 & e2g3 is %f\n", e2g2->gravConst2);
			break;
		case 7: {
			printf("Select the planet, to reset data: [1] - 1, [2] - 2, [3] - 3, [4] - all");
			int i = scanf_s("%d", &i);
			switch (i) {
			case 1: ResetPlanet(e2g1); break;
			case 2: ResetPlanet(e2g2); break;
			case 3: ResetPlanet(e2g3); break;
			case 4: {ResetPlanet(e2g1);
				ResetPlanet(e2g2);
				ResetPlanet(e2g3);
				break; }
			default: printf("U can use only [1], [2], [3] & [4] keys");
				break;
			}
		}
			break;
		case 8:	DestroyPlanet(e2g3);
				DestroyPlanet(e2g2);
				DestroyPlanet(e2g1);
				exit(1);
		case 0:
			printf("Developed by Mihail Bogomolov. Version 1.0.\n");
			break;
		default: printf("U can use only [1],[2],[3],[4],[5],[6],[7],[8] & [0] keys!");
		}
		if (e2g1->radius == e2g2->radius || e2g1->radius == e2g3->radius || e2g3->radius == e2g2->radius) {
			printf("invalid input! Planets cannot be on the same orbit! Reenter your data, please.");
		}
	}
	DestroyPlanet(e2g3);
	DestroyPlanet(e2g2);
	DestroyPlanet(e2g1);
}

int main()
{
	printf("Hi,Commander!\nOur spaceship 'GExplorer' must meet another spaceship in 'E2G' system!\n");
	Menu();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
