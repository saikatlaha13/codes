#include"header.h"

int File_opr::file_open(Employee* member,const char* filename,int mode,fstream* my_file)
{
    // passing the file opening modes
    if(mode == MODE_APPEND)            // if(1 == 1)
    {
        (*my_file).open(filename,APPEND | WRITE);
    }
    else if(mode == MODE_OUTPUT)       // if(2 == 2)
    {
        (*my_file).open(filename,OUTPUT);
    }
    else if(mode == MODE_READ)
    {
        (*my_file).open(filename,READ);
    }
    else if(mode == MODE_WRITE)
    {
        (*my_file).open(filename,WRITE);
    }
    else if(mode == MODE_TRUNC)
    {
        (*my_file).open(filename,TRUNC);
    }

    return SUCCESS;
}

int File_opr::write_to_file(Employee* Employee_data,const char* filename,int MODE)
{
    // using fstream for both input and output
    fstream my_file;
    File_opr write;

    //user defined opening the file
    write.file_open(Employee_data,filename,MODE,&my_file);

    if(my_file.is_open())
    {
        my_file<<(*Employee_data).username;
        my_file<<SEPARATOR;
        my_file<<(*Employee_data).password;
        my_file<<SEPARATOR;
        my_file<<(*Employee_data).email;
        my_file<<SEPARATOR;
        my_file<<(*Employee_data).department<<endl;
    }
    else
    {
        cout<<"file opening failed in write_to_file()"<<endl;
    }

    // closing the file
    my_file.close();

    return SUCCESS;
}

Node* File_opr::read_complete_data(const char *filename,int MODE)
{
    fstream my_file;
    
    int index=0;
    File_opr read;
    linked_list link_obj;
    string line;
    char* brk_str[4];
    char delim=',';
    
    Node* head=NULL;

    // user defined
    read.file_open(NULL,filename,MODE,&my_file);
                                                           
    // system defined
    if(my_file.is_open())
    {
        while(!(my_file.eof()))
        {
            while(getline(my_file,line))
            {
                index=0;
                brk_str[index]=strtok(&line[0],&delim);
                while(brk_str[index] != NULL)
                {
                    index++;
                    brk_str[index]=strtok(NULL,&delim);
                }
                link_obj.create_list(&head,brk_str[0],brk_str[1],brk_str[2],brk_str[3]);
            }
        }
    }
    else
    {
        cout<<"file opening failed in read_complete_data()"<<endl;
    }

    my_file.close();
    
    return head;
}

Node* linked_list::create_list(Node **head,char *str_1,char *str_2,char* str_3,char* str_4)
{
    // initialising the pointer with head address value
    Node* pointer=(*head);

    // storing the address of new node
    Node* new_node=new (Node);
    new_node->username=str_1;
    new_node->password=str_2;
    new_node->email=str_3;
    new_node->department=str_4;
    new_node->next=NULL;

    if((*head)==NULL)
    {
        // if there is only a base node
        (*head)=new_node;
    }
    else
    {
        pointer=(*head);
        while(pointer->next != NULL)
        {
            // if the pointer has reached its end
            pointer=pointer->next;
        }
        pointer->next=new_node;
        //cout<<(pointer)->email<<endl;
    }

    return (*head);
}

void linked_list::display_data_linked_list(Node** head)
{
    cout<<"printing the list from reading file function"<<endl;
    Node* pointer=(*head);
    while(pointer != NULL)
    {
        cout<<"----------------------------"<<endl;
        cout<<"username:     "<<pointer->username<<endl<<flush;
        cout<<"password:     "<<pointer->password<<endl<<flush;
        cout<<"email:        "<<pointer->email<<endl<<flush;
        cout<<"department:   "<<pointer->department<<endl<<flush;
        cout<<"----------------------------"<<endl;
        
        pointer=pointer->next;
    }
}
