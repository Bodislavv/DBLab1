#pragma once
#include "Master.h"
#include "Movie.h"
#include "stdio.h"
#include "Ind.h"

#define IND_SIZE sizeof(struct Ind)
#define Movie_DATA "movie.fl"
#define Movie_SIZE sizeof(struct Movie)
#define Actor_DATA "actor.fl"
#define Actor_SIZE sizeof(struct Actor)
#define Movie_IND "movie.ind"

int getMovie(struct Movie* movie, int id, char* error);

int checkFileExistence(FILE* indexTable, FILE* database, char* error){
    if (indexTable == NULL || database == NULL) {
        strcpy(error, "this movie doesn't exist");
        return 0;
    }
    return 1;
}

int checkIndexExistence(FILE* indexTable, char* error, int id) {
    fseek(indexTable, 0, SEEK_END);
    long indexTableSize = ftell(indexTable);
    if (indexTableSize == 0 || id * IND_SIZE > indexTableSize) {
        strcpy(error, "this id doesn't exist");
        return 0;
    }
    return 1;
}

int checkRecordExistence(struct Ind ind, char* error) {
    if (ind.exists == 0 ) {
        strcpy(error, "there is no such record");
        return 0;
    }
    return 1;
}

int checkIfRecordExists(struct Movie movie, int actorId, char *error ) {
    FILE* actorsDb = fopen(Actor_DATA, "a+b");
    struct Actor actor;
    fseek(actorsDb, movie.actorFirstAddress, SEEK_SET);
    for (int i = 0; i < movie.actorCount; i++) {
        fread(&actor, Actor_SIZE, 1, actorsDb);
        fclose(actorsDb);
        if (actor.id == actorId){
            if(actor.exists)
                return 1;
            else{
                strcpy(error, "This actor doesn't exist");
                return 0;
            }
        }
        actorsDb = fopen(Actor_DATA, "r+b");
        fseek(actorsDb, actor.nextAddress, SEEK_SET);
    }
    strcpy(error, "Sorry, this movie doesn't have this actor");
    fclose(actorsDb);
    return 0;
}
