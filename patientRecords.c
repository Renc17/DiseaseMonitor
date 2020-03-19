#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patientRecords.h"

patientRecord* initialize(){
    patientRecord* v = malloc(sizeof(patientRecord));
    return v;
}

int get_id(patientRecord* v){
    return v->recordId;
}

char* get_name(patientRecord* v){
    return v->name;
}

char* get_surname(patientRecord* v){
    return v->surname;
}

char* get_country(patientRecord* v){
    return v->country;
}

char* get_disease(patientRecord* v){
    return v->disease;
}

struct tm get_entryDate(patientRecord* v){
    return v->entryDate;
}

char* get_exitDate(patientRecord* v){
    return v->exitDate;
}

void set_id(patientRecord* v, int id){
    v->recordId = id;
}

void set_name(patientRecord* v, char* n){
    strcpy(v->name,n);
}

void set_surname(patientRecord* v, char* sn){
    strcpy(v->surname, sn);
}

void set_disease(patientRecord* v, char* dis){
    strcpy(v->disease, dis);
}

void set_country(patientRecord* v, char* co){
    strcpy(v->country,co);
}

void set_entryDate(patientRecord* v, char* ed){
    char* t;
    char skip[2] = "-";

    t = strtok(ed, "\n");

    t = strtok(t, skip);
    v->entryDate.tm_mday = atoi(t);
    t = strtok(NULL, skip);
    v->entryDate.tm_mon = atoi(t);
    t = strtok(NULL, skip);
    v->entryDate.tm_year = atoi(t);

    v->entryDate.tm_gmtoff = 0;
    v->entryDate.tm_hour = 0;
    v->entryDate.tm_min = 0;
    v->entryDate.tm_sec = 0;
    v->entryDate.tm_isdst = 0;
    v->entryDate.tm_wday = 0;
    v->entryDate.tm_yday = 0;
    v->entryDate.tm_zone = NULL;
}

void set_exitDate(patientRecord* v, char* ed){
    strcpy(v->exitDate, ed);
}

void delete_patient(patientRecord* v){
    free(v->name);
    free(v->surname);
    free(v->disease);
    free(v->country);
    free(v->exitDate);
    free(v);
}