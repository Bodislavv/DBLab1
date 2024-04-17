#pragma once
#include <stdio.h>
#include <string.h>
#include "Master.h"
#include "Slave.h"

void inputMovie(struct Movie *movie){
    char name[50];
    char duration[40];
    char releaseDate[40]; 
    char genre[40];
    char country[40]; 
    char boxOffice[40]; 
    int actorCount;
    int actorFirstAddress; 

    printf("Enter movie name: ");
    scanf("%s", name);
    strcpy(movie->name, name);
    printf("Enter movie's duration: ");
    scanf("%s", duration);
    strcpy(movie->duration, duration);
    printf("Enter movie's release date: ");
    scanf("%s", releaseDate);
    strcpy(movie->releaseDate, releaseDate);
    printf("Enter movie's genre: ");
    scanf("%s", genre);
    strcpy(movie->genre, genre);
    printf("Enter movie's country: ");
    scanf("%s", country);
    strcpy(movie->country, country);
    printf("Enter movie's box office: ");
    scanf("%s", boxOffice);
    strcpy(movie->boxOffice, boxOffice);
}

void inputActor(struct Actor *actor){
    char name[50];
    char role[40];
    char age[40];
    char country[40];

    printf("Enter actor's name: ");
    scanf("%s", name);
    strcpy(actor->name, name);
    printf("Enter actor's role: ");
    scanf("%s", role);
    strcpy(actor->role, role);
    printf("Enter actor's age: ");
    scanf("%s", age);
    strcpy(actor->age, age);
    printf("Enter actor's country: ");
    scanf("%s", country);
    strcpy(actor->country, country);
}
