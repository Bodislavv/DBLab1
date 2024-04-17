#pragma once
#include "Master.h"
#include "Slave.h"

void outputMovie(struct Movie movie){
    printf("Movie name: %s\n", movie.name);
    printf("Duration: %s\n", movie.duration);
    printf("Release date: %s\n", movie.releaseDate);
    printf("Genre: %s\n", movie.genre);
    printf("Country: %s\n", movie.country);
    printf("Box office: %s\n", movie.boxOffice);
}

void outputActor(struct Movie movie, struct Actor actor){
    printf("Movie name: %s\n", movie.name);
    printf("Actor's name: %s\n", actor.name);
    printf("Actor's role: %s\n", actor.role);
    printf("Actor's age: %s\n", actor.age);
    printf("Actor's country: %s\n", actor.country);
}
