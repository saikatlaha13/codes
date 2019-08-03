#include"header.h"

int Emp_cred_ver::user_is_present(Employee* member,Node* node)
{
    Emp_cred_ver object;
    int result_cmp_email,result_cmp_usrname,result_cmp_pswd;

    // calling string compare function_strcmp
    result_cmp_email=object.result_of_strcmp(&(((*member).email)[0]),&((node->email)[0]));
    result_cmp_usrname=object.result_of_strcmp(&(((*member).username)[0]),&((node->username)[0]));
    result_cmp_pswd=object.result_of_strcmp(&(((*member).password)[0]),&((node->password)[0]));

    if((result_cmp_email== MATCH_FOUND) && (result_cmp_usrname==MATCH_FOUND) && (result_cmp_pswd==MATCH_FOUND))
    {
        // to parse_data_link_list()
        return MATCH_FOUND;
    }
    else
    {
        return MATCH_NOT_FOUND;
    }
}

// function_strcmp
int Emp_cred_ver::result_of_strcmp(char *member_from_user,char *member_from_database)
{
    int result;

    result=strcmp(member_from_user,member_from_database);
    if(result==0)
    {
        // to user_is_present function
        return MATCH_FOUND;
    }
    else
    {
        return MATCH_NOT_FOUND;
    }
}

// head has to be passed from main_opt function
// function_all_data_parsing
int Emp_cred_ver::parse_data_link_list(Employee* member,Node* head)
{
    Emp_cred_ver object;
    Node* pointer=head;
    int return_result_each_node;
    if(pointer==NULL)
    {
        cout<<"no data"<<endl;
    }
    else
    {
        pointer=head;

        while(pointer != NULL)
        {
            return_result_each_node=object.user_is_present(member,pointer);
            if(return_result_each_node == MATCH_FOUND)
            {
                return MATCH_FOUND;
                break;
            }
            else
            {
                ++file_line_count;
                pointer=pointer->next;
            }
        }
    }

    // to fun_opt_function.cpp function()
    return MATCH_NOT_FOUND;
}

char* string_opr(Employee* data,char* dest_str)
{
    string sep=",";
    char count=0;
    for(count=0 ; count<50 ; count++)
    {
        dest_str[count]='\0';
    }

    strcat(dest_str,&(((*data).username)[0]));
    strcat(dest_str,&(sep[0]));
    strcat(dest_str,&(((*data).password)[0]));
    strcat(dest_str,&(sep[0]));
    strcat(dest_str,&(((*data).email)[0]));
    strcat(dest_str,&(sep[0]));
    strcat(dest_str,&(((*data).department)[0]));
    //    cout<<"dest_string="<<dest_str;

    return &(dest_str[0]);
}

int edit_database(Employee* data_to_find,Employee *data_to_replace,char *dest_str)
{
    ifstream seek1;
    fstream seek2;
    string temp;
    char* want_to_find;
    char need_to_search[40];
    char* data_to_edit_with;
    char data_to_replace_with[40];
    size_t pos;
    int length;

    memset(need_to_search,'\0',39);
    memset(data_to_replace_with,'\0',39);

    want_to_find=string_opr(data_to_find,dest_str);
    strcpy(&(need_to_search[0]),&(dest_str[0]));
    cout<<"need_to_search="<<need_to_search<<endl;

    data_to_edit_with=string_opr(data_to_replace,dest_str);
    strcpy(&(data_to_replace_with[0]),&(dest_str[0]));
    cout<<"data_to_edit_with="<<data_to_replace_with<<endl;

    seek1.open("database.txt",WRITE);
    length=strlen(&need_to_search[0]);
    // seek2.open("database.txt",APPEND|OUTPUT|READ|WRITE);

    if(seek1.is_open())
    {
        while(getline(seek1,temp))
        {
            pos=temp.find(need_to_search);
            cout<<pos<<endl;
            if(pos != string::npos)
            {
                temp.replace(pos,length,data_to_replace_with);
            }
        }
    }
    seek1.close();
}
