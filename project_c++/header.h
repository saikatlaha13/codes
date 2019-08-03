// to include header only once
#pragma once

#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<cstdio>

using namespace std;

#define SUCCESS 1
#define FAIL    0 

#define MATCH_FOUND      1
#define MATCH_NOT_FOUND  0

#define EMAIL_SYM_OPEN  '<'
#define EMAIL_SYM_CLOSE '>'
#define DATA_SYM_OPEN   '{'
#define DATA_SYM_CLOSE  '}'
#define SEPARATOR       ','

#define CHOICE_1 1
#define CHOICE_2 2
#define CHOICE_3 3
#define CHOICE_4 4
#define CHOICE_5 5
#define CHOICE_6 6
#define CHOICE_7 7

#define APPEND  std::fstream::app
#define OUTPUT  std::fstream::ate  
#define READ    std::fstream::in
#define WRITE   std::fstream::out
#define TRUNC   std::fstream::trunc

#define MODE_APPEND 1 
#define MODE_OUTPUT 2
#define MODE_READ   3
#define MODE_WRITE  4
#define MODE_TRUNC  5

// globally defined 
int file_line_count;

// basic class for performing employee operations
class Employee
{
    public:
        int id;
        string username;
        string password;
        string department;
        string email;

        void login_existing_user(Employee *);
        void display_employee_details(Employee *);
        void modify_employee_details(Employee *);
        void register_new_user(Employee *);
        void input_login_details(Employee *);
};

class Node:public Employee
{
    public:
       Node* next;
};

class linked_list:public Node
{
    public:
        Node* create_list(Node **,char *,char*,char*,char*);
        void display_data_linked_list(Node **);
};

// class for performing file operations
// file_opr is inheriting class Employee
class File_opr:public Employee 
{
    public:
        const char* filename;
        int is_found;

        int file_open(Employee*,const char *,int,fstream*);
        Node* read_complete_data(const char*,int);
        int write_to_file(Employee*,const char*,int);
};

class Emp_cred_ver:public Node
{
    public:
        int user_is_present(Employee*,Node *);
        int result_of_strcmp(char*,char*);
        int parse_data_link_list(Employee*,Node *);
};

// function prototypes
int options_display();
void exit();
void read_data_from_user(Employee *);
char* string_opr(Employee*,char *);
int edit_database(Employee*,Employee*,char*);
